#include <stdio.h>
#include "constants.h"

#include "jsonToArray.c"
#include "arrayToOpml.c"

int main(){
    FILE *fp_opml;
    
    //locally declared arrays, data to be retrieved from function "jsonToArray()", while data to be written to .opml file via function "arrayToOpml()"
    string24 channel_id[MAX_SUBS];
    string128 channel_name[MAX_SUBS];

    int nChannels = 0;

    if(jsonToArray(channel_id, channel_name, &nChannels)){ //if json file was read correctly
        arrayToOpml(channel_id, channel_name, nChannels); //write contents of array to opml
    }

    printf("\n\nOPMLify created by /u/mako-rino");
    printf("\nPress any key to continue...");
    getc(stdin);

}