# OPMLify
 Convert YouTube Subscriptions JSON into RSS Reader Compatible OPML

### Brief Overview ###
OPMLify allows you to import your YouTube Subscriptions to an RSS Reader like Newsflow or Feeder. This simple C program is perfect if you want to stay updated with your favorite content creators without being logged into YouTube.

### Pre-requisites ###
* json-c library (could be found [here](https://github.com/json-c/json-c "json-c"))
* gcc compiler
* Your YouTube Subscriptions (json file) exported from Google Takeout

### How to use ###
1. Clone this repository to a local directory in your machine using the following command:
```
git clone https://github.com/makorino/OPMLify/
```
2. Install the json-c library using the following command (NOTE: currently not supported on Windows)
```
sudo apt install libjson-c-dev
```
3. Compile this program using the following command:
```
gcc main.c -ljson-c OPMLify
```
4. Get your YouTube Subscriptions file (subscriptions.json) by visiting [Google Takeout](https://takeout.google.com/)
   1. Sign in with your Google Account if needed
   2. Click on "Deselect All"
   3. Scroll down, until you reach "YouTube and YouTube Music", then check the box corresponding to it
   4. Click on "All YouTube data included", then click "Deselect All
   5. Check the box corresponding to "subscriptions, then click "OK"
   6. Click on "Next step"
   7. Just use the default settings, then click on "Create export"
   8. Click on the download button corresponding to "YouTube and YouTube Music". Sign in if needed
   9. Save the zip file locally on your machine, then extract it
   10. Get the "subscriptions.json" file inside of the "subscriptions" folder and place it in the same directory as where you cloned this repo.
5. Run the OPMLify program using the following command:
```
./OPMLify
```
6. If everything worked correctly, a "subscriptions.opml" file should be created within the same directory
7. Import the "subscriptions.opml" file using any RSS Reader. Your YouTube Subscriptions should update automatically.
