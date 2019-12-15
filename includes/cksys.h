#ifndef _CHSYS_H_
#define _CHSYS_H_

#include "sdl.h"
#include "menu.h"

bool asm1check ;
//bool asm1check = false;    // Check titles Asm  give Result check
//#define Abool asm1check = false;    // Check titles Asm  give Result check
bool uLaunchchecked ;  // Check titles uLaunch give Result check
bool emuiibochecked ;// Result titles emuiibo check
bool BootSoundNXchecked;
bool SysDVRchecked;
bool Sysclkchecked;
bool sysconchecked;
bool sysFTPDchecked;
bool sysnetcheatchecked ;
bool sysAudiochecked ;
bool Presencechecked  ;
//char* str;

int atmosphere();
void asmcheck(bool asm1check);  // Check result
int uLaunchcheck();// Check result
int emuiibocheck(); //check for result!
int BootSoundNXcheck();
int SysDVRcheck();
int Sysclkcheck();
int sysconcheck();
int sysFTPDcheck();
int sysnetcheatcheck ();
int sysAudiocheck ();
int Presencecheck(); //char *Presencechecked
int Writefile(bool asm1check);

#endif
