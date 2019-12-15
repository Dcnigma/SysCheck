#ifndef _MENU_H_
#define _MENU_H_

#include "sdl.h"
//number of items in printOptionList. 0123456789 for 10
//option_list and description_list
#define CURSOR_LIST_MAX     1
//
#define HIGHLIGHT_BOX_MIN   20
#define HIGHLIGHT_BOX_MAX   70
#define NEWLINE             110
#define FIRST_LINE          130
#define MAX_STRLEN          512
//to remove
#define AMS_URL     "https://github.com/Dcnigma/DC-Switch/raw/master/DCnigma-switch-exampels.zip"
#define HEKATE_URL  "https://github.com/Dcnigma/DC-Switch/raw/master/emuiibo.zip"
#define EBOOK_URL     "https://github.com/Dcnigma/DC-Switch/raw/master/ebooks.zip"
#define APP_URL     "https://github.com/Dcnigma/DC-Switch/raw/master/DC-Switch.nro"
//int reboot_payload(const char *payload);
#define UPDATE_APP1  0
#define UPDATE_APP2  1
#define UPDATE_APP3  2
#define UPDATE_APP4  3
#define UPDATE_APP5  4
// end
// Define State of Sys


#define ASMCHECKA   "false"
#define ASMCHECKB   "Atmosphere is NOT installed\n\n"
//char presenceoutputa(char *text);

//char* str = "string";
int asm1check2();

void refreshScreen(void);                                                   // clear screen, display background with title
void printOptionList(int cursor);                                           // print list of options
void popUpBox(TTF_Font *font, int x, int y, SDL_Colour colour, char *text); // pop-up box in center of screen
int yesNoBox(int mode, int x, int y, char *question);                       // box with yes or no option
void errorBox(int x, int y, char *errorText);                               // used for displaying error messages
void splash(int x, int y);                               // used for displaying error messages
#endif
