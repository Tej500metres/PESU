#include"headers.h"


//EXP00-A PRE00-A
#define capability_fail(t1,t2) t1/10*t1-t2/10*t2 ==0 ? 1 :0


static short altitude;


short countdown(player pl)
{
    system("cls");
    slowprint(11,"Assessing rocket capability..");
   Sleep(1500);
    int check=capability_fail(pl.r.fuel_capacity,pl.r.start_thrust);
   //setColor(12);
    printf("\n%s",(check==1 ? "Capable" : "Not Capable"));
    error_disp("\n[EXP00-A FAILED- PARENTHESES]\n[PRE00-A FAILED-INLINE AGAINST MACROS]");
    check=capability_pass(pl);
   //setColor(10);
    printf("\n%s",(check==1 ? "Rocket now Capable" : "Not Capable"));
    printf("\nIssue fixed!");
   Sleep(1000);
    fflush(stdin);
    getchar();
   //setColor(11);
    printf("\nRocket countdown..begins..NOW!\n");
   Sleep(500);
    short c;
    while (c != -1)
    {
        printf("%d", c);
       Sleep(1000);
        printf("\b");
        c--;
    }
    error_disp("\n[EXP33-C FAILED - UNINITIALIZED VARIABLES]"); 
   //setColor(10);
    printf("\nIssue fixed!\n");
    fflush(stdin);
    getchar();
    system("cls");
    flashy_text(11,"Rocket countdown begins NOW!!");
   //setColor(14);
    c=9;
    printf("\n");
    while(c!=-1)
    {
        printf("%d",c);
       Sleep(1000);
        printf("\b");
        c--;
    }
   Sleep(1000);
    slowprint(10,"\nRocket ignition successful!");
   Sleep(1000);
    slowprint(14,"\nRocket acheving escape velocity..");
    float vel=getVelocity(pl);
    printf("\nRocket's velocity: %lf",vel);
    if(!(vel==11))
    {
       //setColor(12);
        printf("\nSeems like the rocket is failing..");
        printf("\n[FLP32C - DOMAIN ERRORS IN MATH FUNCTIONS FAILED]!");
       //setColor(10);
        printf("\nFixing..\n");
        flashy_text(10,"Sucessful!");
        getchar();
    }
    system("cls");
    slowprint(11,"\nRocket velocity now =11km/s.. Escape velocity reached!");
   Sleep(1000);
    slowprint(11,"\nRocket is in motion NOW!..SUCCESS!");
    //sleep(1500);
    fflush(stdin);
    getchar();
    short success=1;
    return success;
}

short phase1(player pl)
{
    system("cls");
    slowprint(3,"Entering rocket deploy monitor page...");
   Sleep(2000);
    system("cls");
    line_displayer(14);
   //setColor(11);
    printf("\t\t\t\t\t\tROCKET MONITOR CENTRE\n");
    line_displayer(14);
   Sleep(1500);
   //setColor(10);
    printf("\nRocket altitude :");
   //setColor(11);
    while(altitude!=300)
    {
        printf("%d",altitude);
        printf("hm");
        printf("\b\b");
        short d=getDigits(altitude);
        while(d!=0)
        {
            printf("\b");
            d--;
        }
        if(altitude==0)
            printf("\b");
        altitude+=50;
       Sleep(1000);
    }
   Sleep(1000);
    printf("\nRocket reached optimal altitude for phase1..");
   Sleep(1000);
    printf("\nLower body seperation initiated..");
   Sleep(1000);
    printf("\n");
    flashy_text(10,"SUCCESSFUL!!");
   Sleep(1000);
    slowprint(6,"\nEntering PHASE 2..");
    short ph=1;
   Sleep(1000);
    return ph;
}
short phase2(player pl)
{
    system("cls");
    line_displayer(14);
   //setColor(11);
    printf("\t\t\t\t\t\tROCKET MONITOR CENTRE\n");
    line_displayer(14);
   //setColor(10);
   Sleep(1500);
    printf("\nRocket altitude :");
   //setColor(11);
    while(altitude!=600)
    {
        printf("%d",altitude);
        printf("hm");
        printf("\b\b");
        short d=getDigits(altitude);
        while(d!=0)
        {
            printf("\b");
            d--;
        }
        if(altitude==0)
            printf("\b");
        altitude+=50;
       Sleep(1000);
    }
   Sleep(1000);
    printf("\nRocket reached optimal altitude for phase2..");
   Sleep(1000);
    printf("\nMiddle body seperation initiated..");
   Sleep(1000);
    printf("\n");
    flashy_text(10, "SUCCESSFUL!!");
   Sleep(1000);
    slowprint(6, "\nEntering PHASE 3..");
    short ph=1;
   Sleep(1000);
    return ph;
}
short phase3(player pl)
{
    system("cls");
    line_displayer(14);
   //setColor(11);
    printf("\t\t\t\t\t\tROCKET MONITOR CENTRE\n");
    line_displayer(14);
   //setColor(10);
   Sleep(1500);
    printf("\nRocket altitude :");
   //setColor(11);
    while(altitude!=700)
    {
        printf("%d",altitude);
        printf("hm");
        printf("\b\b");
        short d=getDigits(altitude);
        while(d!=0)
        {
            printf("\b");
            d--;
        }
        if(altitude==0)
            printf("\b");
        altitude+=10;
       Sleep(1000);
    }
   Sleep(1000);
   //setColor(11);
    printf("\nRocket reached deploy Point!!");
   Sleep(1000);
    slowprint(13,"\nInitiating satellite deploy..\n");
   Sleep(1000);
    flashy_text(10,"SUCCESSFUL!!");
   Sleep(1000);
    short ph=1;
   Sleep(1000);
    return ph;
}
