
#include <unistd.h>
#include <switch.h>

#include "menu.h"
#include "touch.h"
#include "util.h"
#include <string.h>
#include <cksys.h>
#include <dirent.h>//Check dir
#include <errno.h>//Check dir





struct WDATA {
   char  name[50];
   char  trueorfalse[50];
 };

void asmcheck(bool asm1check) //Check Atmosphere Titles
{
  DIR* dir1 = opendir("/atmosphere/titles/0100000000000032");
    DIR* dir2 = opendir("/atmosphere/titles/0100000000000034");
    DIR* dir3 = opendir("/atmosphere/titles/0100000000000036");
    DIR* dir4 = opendir("/atmosphere/titles/0100000000000037");
    DIR* dir5 = opendir("/atmosphere/titles/010000000000000D");
    if (dir1 && dir2 && dir3 && dir4 && dir5)  {
        /* Directory exists. */
        //name = "Atmosphere";
      asm1check = true;
        closedir(dir1);
        closedir(dir2);
        closedir(dir3);
        closedir(dir4);
        closedir(dir5);
        //
      } else if (ENOENT == errno)  {

      }  else {

      }

  if (asm1check){
    drawImageScale(Ledon, 200, 52, 30, 30); // Location with, Location Hight, Size with, size Hight
    drawText(fntSmall, 250, 52, SDL_GetColour(white), "Atmosphere");
    asm1check = true;
    //ASMCHECKA = true;
//    strcpy( asm1.name, "Atmosphere");
//    strcpy( asm1.trueorfalse, " installed");
  }
  else {
    drawImageScale(Ledoff, 200, 52, 30, 30); // Location with, Location Hight, Size with, size Hight
    drawText(fntSmall, 250, 52, SDL_GetColour(red), "Atmosphere");
    //Session["ASMCHECKB"] = "Atmosphere is NOT installed\n\n";
  //   strcpy( asm1.name, "Atmosphere");
  //   strcpy( asm1.trueorfalse, " not installed");
  }
}

int uLaunchcheck() //Check ulaunch Titles
{
  DIR* ulaunchdir1 = opendir("/atmosphere/titles/01008BB00013C000");
  DIR* ulaunchdir2 = opendir("/atmosphere/titles/010000000000100B");
  DIR* ulaunchdir3 = opendir("/atmosphere/titles/0100000000001001");
  DIR* ulaunchdir4 = opendir("/atmosphere/titles/0100000000001000");

  if (ulaunchdir1 && ulaunchdir2 && ulaunchdir3 && ulaunchdir4)  {
      /* Directory exists. */
      uLaunchchecked = true;
      closedir(ulaunchdir1);
      closedir(ulaunchdir2);
      closedir(ulaunchdir3);
      closedir(ulaunchdir4);
  } else if (ENOENT == errno)  {

  }  else {

  }
  if (uLaunchchecked){
    drawImageScale(Ledon, 200, 104, 30, 30); // Location with, Location Hight, Size with, size Hight
    drawText(fntSmall, 250, 104, SDL_GetColour(white), "uLaunch");
  } else {
    drawImageScale(Ledoff, 200, 104, 30, 30);   // Location with, Location Hight, Size with, size Hight
    drawText(fntSmall, 250, 104, SDL_GetColour(red), "uLaunch");
        }
}
int emuiibocheck() //Check ulaunch Titles
{
   DIR* emuiibodir1 = opendir("/atmosphere/titles/0100000000000352");

   if (emuiibodir1)  {
      closedir(emuiibodir1);
      emuiibochecked = true;
    } else if (ENOENT == errno)
    {

        /* Directory does not exist. */
    }  else {

    }
if (emuiibochecked){
         drawImageScale(Ledon, 200, 156, 30, 30); // Location with, Location Hight, Size with, size Hight
         drawText(fntSmall, 250, 156, SDL_GetColour(white), "Emuiibo");
} else {
         drawImageScale(Ledoff, 200, 156, 30, 30);   // Location with, Location Hight, Size with, size Hight
         drawText(fntSmall, 250, 156, SDL_GetColour(red), "Emuiibo");


       }

}

//sys-netcheat
//folder >
int sysnetcheatcheck() //Check ulaunch Titles
{
   DIR* sysnetcheatdir1 = opendir("/modules/sysnetcheat/0100000000000352");

   if (sysnetcheatdir1)  {
      closedir(sysnetcheatdir1);
      sysnetcheatchecked = true;
    } else if (ENOENT == errno)
    {

        /* Directory does not exist. */
    }  else {

    }
if (sysnetcheatchecked){
         drawImageScale(Ledon, 200, 206, 30, 30); // Location with, Location Hight, Size with, size Hight
         drawText(fntSmall, 250, 206, SDL_GetColour(white), "sys-NetCheat");
} else {
         drawImageScale(Ledoff, 200, 206, 30, 30);   // Location with, Location Hight, Size with, size Hight
         drawText(fntSmall, 250, 206, SDL_GetColour(red), "sys-NetCheat");


       }

}

//sys-Audioplayer
//folder >4200000000000000
int sysAudiocheck() //Check ulaunch Titles
{
   DIR* sysAudiodir1 = opendir("/atmosphere/titles/4200000000000000");

   if (sysAudiodir1)  {
      closedir(sysAudiodir1);
      sysAudiochecked = true;
    } else if (ENOENT == errno)
    {

        /* Directory does not exist. */
    }  else {

    }
if (sysAudiochecked){
         drawImageScale(Ledon, 200, 256, 30, 30); // Location with, Location Hight, Size with, size Hight
         drawText(fntSmall, 250, 256, SDL_GetColour(white), "sys-AudioPlayer");
} else {
         drawImageScale(Ledoff, 200, 256, 30, 30);   // Location with, Location Hight, Size with, size Hight
         drawText(fntSmall, 250, 256, SDL_GetColour(red), "sys-AudioPayer ");


       }

}

//sys-FTPD
//folder >/modules/sysftpd/
int sysFTPDcheck() //Check ulaunch Titles
{
   DIR* sysFTPDdir1 = opendir("/modules/sysftpd/");

   if (sysFTPDdir1)  {
      closedir(sysFTPDdir1);
      sysFTPDchecked = true;
    } else if (ENOENT == errno)
    {

        /* Directory does not exist. */
    }  else {

    }
if (sysFTPDchecked){
         drawImageScale(Ledon, 200, 306, 30, 30); // Location with, Location Hight, Size with, size Hight
         drawText(fntSmall, 250, 306, SDL_GetColour(white), "sys-FTPD");
} else {
         drawImageScale(Ledoff, 200, 306, 30, 30);   // Location with, Location Hight, Size with, size Hight
         drawText(fntSmall, 250, 306, SDL_GetColour(red), "sys-FTPD");


       }

}
//sys-con
//folder >

int sysconcheck() //Check ulaunch Titles
{
   DIR* syscondir1 = opendir("/atmosphere/titles/690000000000000D");

   if (syscondir1)  {
      closedir(syscondir1);
      sysconchecked = true;
    } else if (ENOENT == errno)
    {

        /* Directory does not exist. */
    }  else {

    }
if (sysconchecked){
         drawImageScale(Ledon, 200, 356, 30, 30); // Location with, Location Hight, Size with, size Hight
         drawText(fntSmall, 250, 356, SDL_GetColour(white), "sys-Con");
} else {
         drawImageScale(Ledoff, 200, 356, 30, 30);   // Location with, Location Hight, Size with, size Hight
         drawText(fntSmall, 250, 356, SDL_GetColour(red), "sys-Con");


       }

}

//Sysclk
//folder >
int Sysclkcheck() //Check ulaunch Titles
{
   DIR* Sysclkdir1 = opendir("/atmosphere/titles/00FF0000636C6BFF");

   if (Sysclkdir1)  {
      closedir(Sysclkdir1);
      Sysclkchecked = true;
    } else if (ENOENT == errno)
    {

        /* Directory does not exist. */
    }  else {

    }
if (Sysclkchecked){
         drawImageScale(Ledon, 200, 406, 30, 30); // Location with, Location Hight, Size with, size Hight
         drawText(fntSmall, 250, 406, SDL_GetColour(white), "Sys-clk");
} else {
         drawImageScale(Ledoff, 200, 406, 30, 30);   // Location with, Location Hight, Size with, size Hight
         drawText(fntSmall, 250, 406, SDL_GetColour(red), "Sys-clk");


       }

}

//SysDVR
//folder >

int SysDVRcheck() //Check ulaunch Titles
{
   DIR* SysDVRdir1 = opendir("/atmosphere/titles/00FF0000A53BB665");

   if (SysDVRdir1)  {
      closedir(SysDVRdir1);
      SysDVRchecked = true;
    } else if (ENOENT == errno)
    {

        /* Directory does not exist. */
    }  else {

    }
if (SysDVRchecked){
         drawImageScale(Ledon, 200, 456, 30, 30); // Location with, Location Hight, Size with, size Hight
         drawText(fntSmall, 250, 456, SDL_GetColour(white), "Sys-DVR");
} else {
         drawImageScale(Ledoff, 200, 456, 30, 30);   // Location with, Location Hight, Size with, size Hight
         drawText(fntSmall, 250, 456, SDL_GetColour(red), "Sys-DVR");


       }

}
//BootSoundNX
//folder >

int BootSoundNXcheck() //Check ulaunch Titles
{
   DIR* BootSoundNXdir1 = opendir("/atmosphere/titles/00FF0000000002AA");

   if (BootSoundNXdir1)  {
      closedir(BootSoundNXdir1);
      BootSoundNXchecked = true;
    } else if (ENOENT == errno)
    {

        /* Directory does not exist. */
    }  else {

    }
if (BootSoundNXchecked){
         drawImageScale(Ledon, 200, 506, 30, 30); // Location with, Location Hight, Size with, size Hight
         drawText(fntSmall, 250, 506, SDL_GetColour(white), "BootSoundNX true");
} else {
         drawImageScale(Ledoff, 200, 506, 30, 30);   // Location with, Location Hight, Size with, size Hight
         drawText(fntSmall, 250, 506, SDL_GetColour(red), "BootSoundNX False");


       }

}
//BootSoundNX
//folder >

int Presencecheck() //Check ulaunch Titles
{
   DIR* Presencedir1 = opendir("/modules/switchpresence");

   if (Presencedir1)  {
      closedir(Presencedir1);
      Presencechecked = true;
    } else if (ENOENT == errno)
    {

        /* Directory does not exist. */
    }  else {

    }
if (Presencechecked){
         drawImageScale(Ledon, 200, 556, 30, 30); // Location with, Location Hight, Size with, size Hight
         drawText(fntSmall, 250, 556, SDL_GetColour(white), "Switch Presence");
      //extern  char PresencecheckedA[30] = "Switch Presence Installed";

} else {
         drawImageScale(Ledoff, 200, 556, 30, 30);   // Location with, Location Hight, Size with, size Hight
         drawText(fntSmall, 250, 556, SDL_GetColour(red), "Switchp Presence ");
      //extern char PresencecheckedB[30] = "Switch Presence NOT Installed";

       }



 }
