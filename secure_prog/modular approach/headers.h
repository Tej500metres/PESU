#include<stdio.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>
// #include<graphics.h>
#include<windows.h>
#include<math.h>
// #include"rlutil.h"
#include "string_m/string_m.h"
// #include "string_m/string_m_internals.h"


extern int errno;
typedef int errno_t;


enum {SUCCESS=1};   //DCL06-A

typedef struct //DCL05-A
{
    char satellite_name[20];
    int weight;
}payload;

typedef struct 
{
    //DCL32-C   //DCL02-A
    double start_thrust;
    double fuel_capacity;
    char rocket_type[20];
    int height;
    char propulsion[40];
}rocket;

typedef struct  //DCL12-A
{
    char name[20];
    payload p;
    rocket r;
}player;

//DCL07-A
void line_displayer(int color);
//Displays dashed line of a color(0-15)-WORKS ONLY ON SMALL SCREEN!

void slowprint(int color, char *text);
int capability_pass(player p);
float getVelocity(player p);
short getDigits(short num);

void flashy_text(int color, char *text);
/*
Takes a colorcode(ANSI/ DOS based from 0-15 only) and text to be displayed
Make sure youre sending codes from 0-7 ONLY
*/

void dots(int color, int n);
//Takes a color code(0-15) and number of dots to be displayed

player displayStartScreen1();
player displayStartScreen2(player);
player decideRocket(player);
short countdown(player);
short phase1(player);
short phase2(player);
short phase3(player);
short payloadDeployed(player);

errno_t error_disp(const char *);//DCL09-A
