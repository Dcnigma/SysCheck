#include <stdio.h>
#include <string.h>
#include <switch.h>
#include <cksys.h>
#include "util.h"
#include "menu.h"



#define LEN 256
int update_app1()
{
errorBox(500, 250, "SysCheck.txt file writen!\nAt Root of your SD cart");
  return 0;
}
int update_app2()
{
errorBox(400, 250, "Quit program?");

}

int update_app3()
{

errorBox(400, 250, "      update_app3!\nTest Config");
}

int update_app4()
    {
errorBox(400, 250, "      update_app4!\nTest Config");
    }
int update_app5()
    {
errorBox(400, 250, "      update_app5!\nTest Config");

    }
