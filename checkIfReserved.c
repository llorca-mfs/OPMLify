#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "constants.h"

const char *checkIfReserved(const char *channel_name){
    char resChars[5] = {'<','>','&','\'','\"'};
    string6 repChars[5] = {"(lt)","(gt)","(amp)","(apos)","(quot)"};

    char *natitira;
    char *newString;
    newString = malloc(sizeof(char)*128);

    int i, j;

    for (i=0; i<strlen(channel_name); i++){  
        for(j=0; j<5; j++){
            if(channel_name[i] == resChars[j]){

                printf("FOUND RESERVED CHAR: %c\n", resChars[j]);

                natitira = strcat(strchr(channel_name, resChars[j]),"\0");
                if (natitira[0] == channel_name[i]) natitira++;

                strncpy(newString, channel_name, i);
                strcat(newString, repChars[j]);
                strcat(newString, natitira);

                printf("modified title: %s\n", newString);
                return newString;
            }
        }
    }

    return channel_name;
}