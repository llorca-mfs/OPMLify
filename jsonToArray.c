#include <stdio.h>
#include <string.h>
#include <json-c/json.h>

#include "constants.h"
#include "checkIfReserved.c"

int jsonToArray(string24 channel_id[], string128 channel_name[], int *nChannels){

    FILE *fp_json;
    char buffer[MAX_BUFF];

    size_t nArray;
    size_t i;

    struct json_object *sub_array;
    struct json_object *sub_elem;

    struct json_object *snippet;
    struct json_object *title;
    struct json_object *resourceId;
    struct json_object *channelId;

    if((fp_json = fopen("subscriptions.json", "r"))!=NULL){ //if subscriptions.json exists
        fread(buffer, MAX_BUFF,1,fp_json);
        fclose(fp_json);

        sub_array = json_tokener_parse(buffer); //treat the input json file as one large array
        
        nArray = json_object_array_length(sub_array);
        printf("Found %lu subscriptions!\n", nArray);

        printf("\nREADING \"subscriptions.json\"...\n");

        for(i=0; i<nArray; i++){
            sub_elem = json_object_array_get_idx(sub_array, i); //refers to one entry within the subscriptions array

            //opens "snippet" key, then gets "title" field from inside
            json_object_object_get_ex(sub_elem, "snippet", &snippet);
            json_object_object_get_ex(snippet, "title", &title);

            //opens "resourceId" key from within snippet, then gets "channelId" field from inside
            json_object_object_get_ex(snippet, "resourceId", &resourceId);
            json_object_object_get_ex(resourceId, "channelId", &channelId);

            printf("title: %s, channelId: %s\n", json_object_get_string(title), json_object_get_string(channelId));

            //copies retrieved strings from json to locally declared array
            strcpy(channel_name[i], checkIfReserved(json_object_get_string(title)));
            strcpy(channel_id[i], json_object_get_string(channelId));

            *nChannels+=1;
        }
        return 1; //function terminated successfully
    }
    else{ //if subscriptions.json does not exist
        printf("\"subscriptions.json\" file not found. Make sure it is within the same directory as this program\n");

        return 0; //function terminated unsuccessfully
    }
}