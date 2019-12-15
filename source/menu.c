#include <unistd.h>
#include <switch.h>

#include "menu.h"
#include "touch.h"
#include "util.h"
#include <string.h>
#include <cksys.h>
#include <dirent.h>//Check dir
#include <errno.h>//Check dir


//bool asm1check = NULL;

void refreshScreen()
{
    clearRenderer();
    drawButton(fntButton, BUTTON_A, 970, 672, SDL_GetColour(black));
    drawText(fntSmall, 1010, 675, SDL_GetColour(black), "Select");
    drawButton(fntButton, BUTTON_PLUS, 1145, 672, SDL_GetColour(black));
    drawText(fntSmall, 1185, 675, SDL_GetColour(black), "Exit");
    drawButton(fntButton, BUTTON_B, 770, 672, SDL_GetColour(black));
    drawText(fntSmall, 810, 675, SDL_GetColour(black), "Cancel");
}



void splash(int x, int y)
{
    drawImageScale(splash_icon, 570, 340, 128, 128); // Location with, Location Hight, Size with, size Hight
    updateRenderer();
    sleep(2);
    drawImageScale(error_icon, 570, 340, 128, 128); // Location with, Location Hight, Size with, size Hight
    updateRenderer();
    sleep(1);

}

void printOptionList(int cursor)
{
    refreshScreen();
    asmcheck(asm1check);
    uLaunchcheck();
    emuiibocheck();
     BootSoundNXcheck();
     SysDVRcheck();
     Sysclkcheck();
     sysconcheck();
     sysFTPDcheck();
     sysnetcheatcheck ();
     sysAudiocheck ();
     Presencecheck();

//Field();

//Change itemcount in menu.h > #define CURSOR_LIST_MAX     4
    char *option_list[]      = {    "Write to Text", \
                                    "Quit!", \
                                    "UPDATE_APP3", \
                                    "UPDATE_APP4", \
                                    "UPDATE_APP5" };

    for (int i=0, nl=0; i < (CURSOR_LIST_MAX+1); i++, nl+=NEWLINE)
    {
        if (cursor != i) drawText(fntSmall, 950, FIRST_LINE+nl, SDL_GetColour(white), option_list[i]);
        else
        {
            // icon for the option selected.
      //      drawImage(textureArray[i], 600, 350);
            // highlight box.
            drawShape(SDL_GetColour(black), 900, (FIRST_LINE + nl - HIGHLIGHT_BOX_MIN), 300, HIGHLIGHT_BOX_MAX);
            // option text.
            drawText(fntSmall, 950, FIRST_LINE+nl, SDL_GetColour(white), option_list[i]);
            // description.
          //  drawText(fntSmall, 950, 5, SDL_GetColour(black), description_list[i]);
        }

    }
}


int Writefile(bool asm1check) //Check ulaunch Titles
{
//Write file
  FILE * fp;
  //  int i;

  DIR* ulaunchdir1 = opendir("/atmosphere/titles/01008BB00013C000");
  DIR* ulaunchdir2 = opendir("/atmosphere/titles/010000000000100B");
  DIR* ulaunchdir3 = opendir("/atmosphere/titles/0100000000001001");
  DIR* ulaunchdir4 = opendir("/atmosphere/titles/0100000000001000");

  if (ulaunchdir1 && ulaunchdir2 && ulaunchdir3 && ulaunchdir4)  {
      /* Directory exists. */
      closedir(ulaunchdir1);
      closedir(ulaunchdir2);
      closedir(ulaunchdir3);
      closedir(ulaunchdir4);
    /* open the file for writing*/
    fp = fopen ("/SysCheck.txt","w");
    fprintf (fp,"%s %s %s","Created with SysCheck", "By Dcnigma","2019\n\n");
    fprintf (fp,"%s %s","Atmosphere;", "is installed\n");
        fclose (fp);
} else if (ENOENT == errno)  {
  fp = fopen ("/SysCheck.txt","w");
  fprintf (fp,"%s %s %s","Created with SysCheck", "By Dcnigma","2019\n\n");
    fprintf (fp,"%s %s","Atmosphere;", "is not installed\n");
        fclose (fp);
}


  DIR* emuiibodir1 = opendir("/atmosphere/titles/0100000000000352");

  if (emuiibodir1)  {
     closedir(emuiibodir1);
     fp = fopen ("/SysCheck.txt","a+");
    fprintf (fp,"%s %s","Emu Amiibo;", "is installed\n");
             fclose (fp);
} else if (ENOENT == errno){
         fp = fopen ("/SysCheck.txt","a+");
         fprintf (fp,"%s %s","Emu Amiibo;", "is not installed\n");
             fclose (fp);
}

DIR* sysnetcheatdir1 = opendir("/modules/sysnetcheat/0100000000000352");

if (sysnetcheatdir1)  {
     closedir(sysnetcheatdir1);
     fp = fopen ("/SysCheck.txt","a+");
     fprintf (fp,"%s %s","Sys NetCheat;", "is installed\n");
         fclose (fp);
} else if (ENOENT == errno){
     fp = fopen ("/SysCheck.txt","a+");
     fprintf (fp,"%s %s","Sys NetCheat;", "is not installed\n");
         fclose (fp);
}

DIR* sysAudiodir1 = opendir("/atmosphere/titles/4200000000000000");

if (sysAudiodir1)  {
   closedir(sysAudiodir1);
     fp = fopen ("/SysCheck.txt","a+");
     fprintf (fp,"%s %s","Sys Audio;", "is installed\n");
         fclose (fp);
} else if (ENOENT == errno){
     fp = fopen ("/SysCheck.txt","a+");
     fprintf (fp,"%s %s","Sys Audio;", "is not installed\n");
         fclose (fp);
}

DIR* sysFTPDdir1 = opendir("/modules/sysftpd/");

if (sysFTPDdir1)  {
   closedir(sysFTPDdir1);

     fp = fopen ("/SysCheck.txt","a+");
     fprintf (fp,"%s %s","Sys FTPD;", "is installed\n");
         fclose (fp);
} else if (ENOENT == errno){
     fp = fopen ("/SysCheck.txt","a+");
     fprintf (fp,"%s %s","Sys FTPD;", "is not installed\n");
         fclose (fp);
}

DIR* syscondir1 = opendir("/atmosphere/titles/690000000000000D");

if (syscondir1)  {
   closedir(syscondir1);
     fp = fopen ("/SysCheck.txt","a+");
     fprintf (fp,"%s %s","Sys Con;", "is installed\n");
         fclose (fp);
} else if (ENOENT == errno){
     fp = fopen ("/SysCheck.txt","a+");
     fprintf (fp,"%s %s","Sys Con;", "is not installed\n");
         fclose (fp);
}

DIR* Sysclkdir1 = opendir("/atmosphere/titles/00FF0000636C6BFF");

if (Sysclkdir1)  {
   closedir(Sysclkdir1);
     fp = fopen ("/SysCheck.txt","a+");
     fprintf (fp,"%s %s","Sys CLK;", "is installed\n");
         fclose (fp);
} else if (ENOENT == errno){
     fp = fopen ("/SysCheck.txt","a+");
     fprintf (fp,"%s %s","Sys CLK;", "is not installed\n");
         fclose (fp);
}

DIR* SysDVRdir1 = opendir("/atmosphere/titles/00FF0000A53BB665");

if (SysDVRdir1)  {
   closedir(SysDVRdir1);
     fp = fopen ("/SysCheck.txt","a+");
     fprintf (fp,"%s %s","Sys DVR;", "is installed\n");
         fclose (fp);
} else if (ENOENT == errno){
     fp = fopen ("/SysCheck.txt","a+");
     fprintf (fp,"%s %s","Sys DVR;", "is not installed\n");
         fclose (fp);
}

DIR* BootSoundNXdir1 = opendir("/atmosphere/titles/00FF0000000002AA");

if (BootSoundNXdir1)  {
   closedir(BootSoundNXdir1);
     fp = fopen ("/SysCheck.txt","a+");
     fprintf (fp,"%s %s","Boot Sound NX;", "is installed\n");
         fclose (fp);
} else if (ENOENT == errno){
     fp = fopen ("/SysCheck.txt","a+");
     fprintf (fp,"%s %s","Boot Sound NX;", "is not installed\n");
         fclose (fp);
}

DIR* Presencedir1 = opendir("/modules/switchpresence");

if (Presencedir1)  {
   closedir(Presencedir1);
     fp = fopen ("/SysCheck.txt","a+");
     fprintf (fp,"%s %s","Switch Presence;", "is installed\n");
         fclose (fp);
} else if (ENOENT == errno){
     fp = fopen ("/SysCheck.txt","a+");
     fprintf (fp,"%s %s","Switch Presence;", "is not installed\n");
         fclose (fp);
}

fp = fopen ("/SysCheck.txt","a+");
fprintf (fp,"%s %s","\n\n", "\n\n");
fprintf (fp,"%s %s","Credits:\n", "-name, -name, -name, -name...\n");
fprintf (fp,"%s %s","\n\n", "\n\n");
fprintf (fp,"%s %s","Visit my blog for more cool projects:", "http://dcnigma.eu5.org\n");
fprintf (fp,"%s %s","or my youtube channel:", "https://www.youtube.com/channel/UCHLMK8BBqyDKyVC7b9VkVdw/\n");
fprintf (fp,"%s %s","\n\n", "Keep the Dream alive!\n\n");
    fclose (fp);
    /* close the file*/
  //  fclose (fp);
    return 1;
  }



void popUpBox(TTF_Font *font, int x, int y, SDL_Colour colour, char *text)
{
    // outline. box
    drawShape(SDL_GetColour(black), (SCREEN_W/4)-5, (SCREEN_H/4)-5, (SCREEN_W/2)+10, (SCREEN_H/2)+10);
    drawShape(SDL_GetColour(dark_grey), SCREEN_W/4, SCREEN_H/4, SCREEN_W/2, SCREEN_H/2);
    // text to draw.
    drawText(font, x, y, colour, text);
}

int yesNoBox(int mode, int x, int y, char *question)
{
    printOptionList(mode);
    popUpBox(fntMedium, x, y, SDL_GetColour(white), question);
    // highlight box.
    drawShape(SDL_GetColour(black), 380, 410, 175, 65);
    drawShape(SDL_GetColour(black), 700, 410, 190, 65);
    // option text.
    drawButton(fntButtonBig, BUTTON_B, 410, 425, SDL_GetColour(white));
    drawText(fntMedium, 455, 425, SDL_GetColour(white), "No");
    drawButton(fntButtonBig, BUTTON_A, 725, 425, SDL_GetColour(white));
    drawText(fntMedium, 770, 425, SDL_GetColour(white), "Yes");

    updateRenderer();

    int res = 0;
    int touch_lock = OFF;
    touchPosition touch;
    u32 tch = 0;
    u32 touch_count = hidTouchCount();

    // check if the user is already touching the screen.
    if (touch_count > 0) touch_lock = ON;

    while (1)
    {
        hidScanInput();
        u64 kDown = hidKeysDown(CONTROLLER_P1_AUTO);
        hidTouchRead(&touch, tch);
        touch_count = hidTouchCount();

        if (touch_count == 0) touch_lock = OFF;

        if (touch_count > 0 && touch_lock == OFF)
            res = touch_yes_no_option(touch.px, touch.py);

        if (kDown & KEY_A || res == YES)
            return YES;

        if (kDown & KEY_B || res == NO)
            return NO;
    }
}



void errorBox(int x, int y, char *errorText)
{
    popUpBox(fntMedium, x, y, SDL_GetColour(white), errorText);
    drawImageScale(error_icon, 570, 340, 128, 128);
    updateRenderer();

    sleep(3);
}
