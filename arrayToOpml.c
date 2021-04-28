#include <stdio.h>
#include <string.h>

#include "constants.h"

void arrayToOpml(string24 channel_id[], string128 channel_name[], int nChannels){
    FILE *fp_opml;
    int i;

    fp_opml = fopen("subscriptions.opml", "w");

    fprintf(stdout, "\nWRITING TO \"subscriptions.opml\"...\n");

    //this adds opening tags
    fprintf(fp_opml, "<opml version=\"1.1\">\n\t<body>\n\t\t<outline text=\"OPMLifyed\" title=\"OPMLifyed YTsubs\">");

    //writes the contents of "channel_name[]" and "channel_id[]" arrays to "subscriptions.opml"
    for (i=0; i<nChannels; i++){
        fprintf(fp_opml, "\n\t\t\t<outline text=\"%s\" title=\"%s\" type=\"rss\" xmlUrl=\"https://www.youtube.com/feeds/videos.xml?channel_id=%s\"/>", channel_name[i], channel_name[i], channel_id[i]);
        fprintf(stdout, "title=\"%s\", xmlUrl=\"https://www.youtube.com/feeds/videos.xml?channel_id=%s\"\n", channel_name[i], channel_id[i]);
    }

    //this adds closing tags
    fprintf(fp_opml, "\n\t\t</outline>\n\t</body>\n</opml>");

    fclose(fp_opml);

    fprintf(stdout, "\nSuccessfully created \"subscriptions.opml\"! You may use this file with any compatible RSS Reader.");
}