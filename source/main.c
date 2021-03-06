#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <switch.h>
#include <cksys.h>
#include "util.h"
#include "touch.h"
#include "menu.h"
//#include "unzip.h"
//#include "download.h"
//#include "reboot_payload.h"

//#define DEBUG                                              // enable for nxlink debug

int appInit()
{
    Result rc;

    if (R_FAILED(rc = socketInitializeDefault()))           // for curl / nxlink.
        printf("socketInitializeDefault() failed: 0x%x.\n\n", rc);

    #ifdef DEBUG
    if (R_FAILED(rc = nxlinkStdio()))                       // redirect all printout to console window.
        printf("nxlinkStdio() failed: 0x%x.\n\n", rc)
    #endif

    if (R_FAILED(rc = setsysInitialize()))                  // for system version
        printf("setsysInitialize() failed: 0x%x.\n\n", rc);

    if (R_FAILED(rc = splInitialize()))                     // for atmosphere version
        printf("splInitialize() failed: 0x%x.\n\n", rc);

    if (R_FAILED(rc = plInitialize()))                      // for shared fonts.
        printf("plInitialize() failed: 0x%x.\n\n", rc);

    if (R_FAILED(rc = romfsInit()))                         // load textures from app.
        printf("romfsInit() failed: 0x%x.\n\n", rc);

    sdlInit();                                              // int all of sdl and start loading textures.

    romfsExit();                                            // exit romfs after loading sdl as we no longer need it.

    return 0;
}

void appExit()
{
    sdlExit();
    socketExit();
    plExit();
    splExit();
    setsysExit();
}



int main(int argc, char **argv)
{


    // init stuff.
    appInit();
    mkdir(APP_PATH, 0777);
    chdir(ROOT);

    // write sys / ams version to char*.
    //writeSysVersion();
    //writeAmsVersion();

    // set the cursor position to 0.
    short cursor = 0;

    // touch variables.
    int touch_lock = OFF;
    u32 tch = 0;
    touchPosition touch;
    splash(200,200);
    // muh loooooop
    while(appletMainLoop())
    {
        // scan for button / touch input each frame.
        hidScanInput();
        u64 kDown = hidKeysDown(CONTROLLER_P1_AUTO);
        hidTouchRead(&touch, tch);
        u32 touch_count = hidTouchCount();

        // main menu display

        printOptionList(cursor);

        // move cursor down...
        if (kDown & KEY_DOWN)
        {
            if (cursor == CURSOR_LIST_MAX) cursor = 0;
            else cursor++;
        }

        // move cursor up...
        if (kDown & KEY_UP)
        {
            if (cursor == 0) cursor = CURSOR_LIST_MAX;
            else cursor--;
        }

        // select option
        if (kDown & KEY_A || (touch_lock == OFF && touch.px > 530 && touch.px < 1200 && touch.py > FIRST_LINE - HIGHLIGHT_BOX_MIN && touch.py < (NEWLINE * CURSOR_LIST_MAX) + FIRST_LINE + HIGHLIGHT_BOX_MAX))
        {
            // check if the user used touch to enter this option.
            if (touch_lock == OFF && touch_count > 0)
                cursor = touch_cursor(touch.px, touch.py);

            switch (cursor)
            {
              case UPDATE_APP1: // Write TXT
                  if (yesNoBox(cursor, 430, 250, "Write result to text file?\n\nSysCheck.txt!") == YES)
                      //update_app1();
                      Writefile(asm1check);
                  break;


              case UPDATE_APP2: //Exit for now!
                  if (yesNoBox(cursor, 430, 250, "Quite program?") == YES){
                  //  update_app2();

                  SDL_Quit();
                  appExit();
                  return 0;
                  // statements to be executed if the test expression is true
                  }
                  else {
               // statements to be executed if the test expression is false
                  }
                  //break;
                  break;

              case UPDATE_APP3:
                  if (yesNoBox(cursor, 390, 250, "UPDATE_APP3?") == YES)
                      update_app3();
                  break;

              case UPDATE_APP4:
                  if (yesNoBox(cursor, 390, 250, "UPDATE_APP4?") == YES)
                      update_app4();

                      //System.IO.File.WriteAllText("C:\your_path\your_file", Your_contents);

                  break;

              case UPDATE_APP5:
                  if (yesNoBox(cursor, 390, 250, "UPDATE_APP5?") == YES)
                      update_app5();
                  break;
            }
        }

        // exit...
        if (kDown & KEY_PLUS || (touch.px > 1145 && touch.px < SCREEN_W && touch.py > 675 && touch.py < SCREEN_H))
            break;

        // lock touch if the user has already touched the screen (touch tap).
        if (touch_count > 0) touch_lock = ON;
        else touch_lock = OFF;

        // display render buffer
        updateRenderer();
    }

    // cleanup then exit
    appExit();
    return 0;
}
