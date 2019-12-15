#ifndef _UTIL_H_
#define _UTIL_H_

#define ROOT                    "/"
#define APP_PATH                "/switch/DC-Switch/"
#define AMS_OUTPUT              "/switch/DC-Switch/DCnigma-switch-exampels_zip"
#define HEKATE_OUTPUT           "/switch/DC-Switch/emuiibo.zip"
#define APP_OUTPUT              "/switch/DC-Switch/DC-Switch.nro"
#define OLD_APP_PATH            "/switch/DC-Switch.nro"
#define EBOOK_OUTPUT		"/switch/DC-Switch/ebook.zip"


#define YES                     10
#define NO                      20
#define ON                      1
#define OFF                     0

//void copyFile(char *src, char *dest);                                   // basic copy file. Use malloc if you need dynamic mem
//int parseSearch(char *phare_string, char *filter, char* new_string);    // hacky way to parse a file for a string
int update_app1();
int update_app2();
int update_app3();
int update_app4();                                                      // update the app
int update_app5();                                                      // update the app
#endif
