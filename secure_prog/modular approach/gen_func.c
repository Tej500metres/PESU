#include"headers.h"

//PRE03-A
#if error_disp
    #undef error_disp
#endif


void slowprint(int color, char *text)
{
   //setColor(color);
    for (int i = 0; i < strlen(text); i++)
    {
        putchar(text[i]);
        Sleep(90);
    }
    // resetColor();
}

void line_displayer(int color)
{
   //setColor(color);
    for (size_t i = 0; i < 117; i++)
    {
        printf("-");
    }
    printf("\n");
}

void flashy_text(int color, char *text)
{
    int count;
    for (size_t j = 0; j < 2; j++)
    {
        if (j == 0)
        {
           //setColor(color);
            count = printf("%s", text);
           Sleep(1000);
        }
        else
        {
            for (size_t i = 0; i < count; i++)
                printf("\b");
           //setColor(color);
            count = printf("%s", text);
           Sleep(1000);
        }
        for (size_t i = 0; i < count; i++)
            printf("\b");
       //setColor((color + 8)%16);
        printf("%s", text);
       Sleep(1000);
    }
    // resetColor();
    //printf("\n");       //Sets cursor to newline after flashing ADD if required!
}

void dots(int color, int n)
{
   //setColor(color);
    for (size_t i = 1; i <= n; i++)
    {
        printf(".");
       Sleep(500);
    }
   //setColor(0);
   Sleep(500);
    int count = 0;
    for (size_t i = 1; i <= n; i++)
    {
        if (count == 1)
            for (size_t j = 1; j <= 2; j++)
                printf("\b");
        else
        {
            printf("\b");
            count++;
        }
        printf(".");
       Sleep(500);
    }
}

int capability_pass(player p)
{
    double x=p.r.fuel_capacity;
    double y=p.r.start_thrust;
    return x/(10*x)-y/(10*y) == 0 ? 1 :0;
}

float getVelocity(player p)
{
    return sqrt(12.1*p.r.fuel_capacity/-p.r.start_thrust);
}

errno_t error_disp(const char *msg)//DCL03-A
{
    char const *p=msg;  //DCL30-C
    //p is out of scope outside so it is compilant code
   //setColor(4);
    printf(p);
    slowprint(14,"\nWhat is this! The result is a bit unexpected!..\nwhat to do!!");
   Sleep(2000);
    slowprint(14,"\nTime to call the technicians!..");
    getchar();
    slowprint(6,"\nfixing..");
    return -3;
}

short getDigits(short num)
{
    short d=0;
    while(num)
    {
        num=num/10;
        d+=1;
    }
    return d;
}
