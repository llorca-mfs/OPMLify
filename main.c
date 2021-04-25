#include <stdio.h>
#include <string.h>
#include <json-c/json.h>

#include "checkIfReserved.c"

#define MAX_SUBS 2048
#define MAX_BUFF 65536

typedef char string24[25];
typedef char string128[129];

int main(){
    FILE *fp_opml, *fp_json;
    char buffer[MAX_BUFF];

    string24 channel_id[MAX_SUBS];
    string128 channel_name[MAX_SUBS];
    int nChannels = 0;

    struct json_object *sub_array;
    struct json_object *sub_elem;

    struct json_object *snippet;
    struct json_object *title;
    struct json_object *resourceId;
    struct json_object *channelId;

    size_t nArray;
    size_t i;
    
    fp_json = fopen("subscriptions.json", "r");
    fread(buffer, MAX_BUFF,1,fp_json);
    fclose(fp_json);

    sub_array = json_tokener_parse(buffer); //treat the input json file as one large array
    
    nArray = json_object_array_length(sub_array);
    printf("Found %lu subscriptions!\n", nArray);

    for(i=0; i<nArray; i++){
        sub_elem = json_object_array_get_idx(sub_array, i);

        json_object_object_get_ex(sub_elem, "snippet", &snippet);
        json_object_object_get_ex(snippet, "title", &title);

        json_object_object_get_ex(snippet, "resourceId", &resourceId);
        json_object_object_get_ex(resourceId, "channelId", &channelId);

        printf("title: %s, channelId: %s\n", json_object_get_string(title), json_object_get_string(channelId));

        strcpy(channel_name[i], checkIfReserved(json_object_get_string(title)));
        strcpy(channel_id[i], json_object_get_string(channelId));

        printf("Successfully added channel to array!\n");

        nChannels++;
    }
    
    fp_opml = fopen("subscriptions.opml", "w");

    //this adds opening tags
    fprintf(fp_opml, "<opml version=\"1.1\">\n\t<body>\n\t\t<outline text=\"OPMLifyed\" title=\"OPMLifyed YTsubs\">");

    for (i=0; i<nChannels; i++){
        fprintf(fp_opml, "\n\t\t\t<outline text=\"%s\" title=\"%s\" type=\"rss\" xmlUrl=\"https://www.youtube.com/feeds/videos.xml?channel_id=%s\"/>", channel_name[i], channel_name[i], channel_id[i]);
    }

    //this adds closing tags
    fprintf(fp_opml, "\n\t\t</outline>\n\t</body>\n</opml>");

    fclose(fp_opml);

    printf("Press any key to continue...");
    getc(stdin);

}