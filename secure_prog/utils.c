#include"headers.h"
#include"rlutil.h"

//PRE03-A
#if error_disp
    #undef error_disp
#endif

static short altitude;

//EXP00-A PRE00-A
#define capability_fail(t1,t2) t1/10*t1-t2/10*t2 ==0 ? 1 :0

void line_displayer(int color);
//Displays dashed line of a color(0-15)-WORKS ONLY ON SMALL SCREEN!

void flashy_text(int color, char *text);
/*
Takes a colorcode(ANSI/ DOS based from 0-15 only) and text to be displayed
Make sure youre sending codes from 0-7 ONLY
*/

void dots(int color, int n);
//Takes a color code(0-15) and number of dots to be displayed

void slowprint(byte color, char *text)
{
    setColor(color);
    for (int i = 0; i < strlen(text); i++)
    {
        putchar(text[i]);
        msleep(100);
    }
    resetColor();
}

void line_displayer(int color)
{
    setColor(color);
    for (size_t i = 0; i < 120; i++)
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
            setColor(color);
            count = printf("%s", text);
            msleep(1000);
        }
        else
        {
            for (size_t i = 0; i < count; i++)
                printf("\b");
            setColor(color);
            count = printf("%s", text);
            msleep(1000);
        }
        for (size_t i = 0; i < count; i++)
            printf("\b");
        setColor((color + 8)%16);
        printf("%s", text);
        msleep(1000);
    }
    resetColor();
    //printf("\n");       //Sets cursor to newline after flashing ADD if required!
}

void dots(int color, int n)
{
    setColor(color);
    for (size_t i = 1; i <= n; i++)
    {
        printf(".");
        msleep(500);
    }
    setColor(BLACK);
    msleep(500);
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
        msleep(500);
    }
}

void launchtest_run()
{
    //STR00-A   STR01-A
    slowprint(9,"\nThis will be over soon..");
    msleep(1000);
    string_m a=NULL;
    char *cstr;
    strcreate_m(&a,"Hi demo translation!",0,NULL);
    cstr=getstrptr_m(a);
    printf("\n");
    setBackgroundColor(5);
    slowprint(11,cstr);
    setBackgroundColor(0);
    free(cstr);
    slowprint(6,"\n[ABIDING STR00-A USE TR24731 STANDARD FOR STRING MANIPULATION]");
    slowprint(6,"\n[ABIDING STR01-A USING MANANGED LIBRARY ]");
    getch();
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
    setColor(4);
    printf(p);
    slowprint(14,"\nWhat is this! The result is a bit unexpected!..\nwhat to do!!");
    msleep(2000);
    slowprint(14,"\nTime to call the technicians!..");
    getch();
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

player displayStartScreen1()
{
    setColor(15);
    setBackgroundColor(0);
    saveDefaultColor();
    char badchars[]="@%^&*#$?()|";
    int count=0;
    player p;
    do
    {
        cls();
        setColor(11);
        line_displayer(14);
        printf("\t\t\t\t\t");
        setBackgroundColor(14);
        flashy_text(13,"ROCKET LAUNCH ASSIST");
        setBackgroundColor(0);
        printf("\n\n");
        line_displayer(14);
        setColor(11);
        slowprint(11,"\n\n\nEnter name:");
        // scanf("%^[\n]s",p.name);
        // fflush(stdin);
        scanf("%19s",p.name); //STR34-C
        count=strspn(p.name,badchars);  //STR02-C
        if(count>0)
        {
            setColor(4);
            printf("\n[STR02-C FAILED - SANITIZATION]");
            slowprint(4,"\nSorry please dont include special characters!\n");
            msleep(2000);
            setColor(11);
        }
    } while (count!=0);
    msleep(2000);
    setColor(6);
    printf("\n[FOLLOWING STR34-C - DONT COPY UNBOUNDED DATA TO FIXED LENGTH ARRAY]");
    msleep(2000);
    setColor(11);
    getch();
    return p;
}

player displayStartScreen2(player pl)
{
    cls();
    slowprint(14,"You're on a mission to launch a satellite to");
    slowprint(8," 'Planet Omicron'");
    dots(8,3);
    slowprint(10,"\nThis mission is to find extraterrestial life supporting planets..");
    setColor(11);
    printf("\nAre you ready?? - Y/y :");
    fflush(stdin);
    char c=getch();
    byte pass=0;
    char t_buff[50];
    if(c=='Y' || c=='y')
    {
        fflush(stdin);//FIO09-A
        slowprint(3,"\nGood..\nNow please enter your payload Name(max 19 chars): ");
        fgets(pl.p.satellite_name, 20, stdin);// FIO37-C  STR31-C STR03-A
        char *loc=strchr(pl.p.satellite_name,'\n'); //FIO36-C
        *loc='\0';
        setColor(6);
        printf("\n[FOLLOWING STR31-C - STRING STORAGE SPACE]");
        printf("\n[FOLLOWING STR03-A - STRING TRUNCATION]");
        setColor(3);
        printf("\nPayload Name: %s",pl.p.satellite_name);
        msleep(2000);
        // printf("\nChoose Payload weight :\n1.upto 1500kg\n2.1500-2000kg\n3.2000-4000kg");
        // printf("Enter choice");
        // scanf("%d",&ch);
        printf("\n");
        flashy_text(10,"Great! Let's get started with your mission..");
        printf("\n");
        fflush(stdin);
        getch();
        return pl;
    }  
}

player decideRocket(player pl)
{
    int ch;
    cls();
    slowprint(11,"\t1.PSLV - XL");
    setColor(14);
    printf("\nHeight:44m\nStart Thrust:300kN\nPropulsion:Solid +Liquid");
    printf("\nPayload limit:1500kg\nFuel Capacity: 3000 units");
    slowprint(11,"\n\n\t2.RLV-TD");
    setColor(14);
    printf("\nHeight:48m\nStart Thrust:350kN\nPropulsion:Liquid");
    printf("\nPayload limit:2000kg\nFuel Capacity: 3500 units");
    slowprint(11, "\n\n\t3.GSLV-Mark III");
    setColor(14);
    printf("\nHeight:43.43m\nStart Thrust:500kN\nPropulsion:Solid+Liquid+Cryogenic");
    printf("\nPayload limit:4000kg\nFuel Capacity: 5000 units");
    setColor(10);
    printf("\n\nEnter your choice: ");
    resetColor();
    scanf("%d",&ch);
    // pl.p.weight = ch == 1 ? 1500 : ch == 2 ? 2000 : 4000;
    switch (ch)
    {
    case 1:
        pl.r.fuel_capacity=3000.0;
        pl.r.height=44.0;
        pl.r.start_thrust=300.0;
        strcpy(pl.r.propulsion,"Solid+Liquid");
        strcpy(pl.r.rocket_type,"PSLV-XL");
        pl.p.weight=1500;
        break;
    case 2:
        pl.r.fuel_capacity = 3500.000;
        pl.r.height = 48;
        pl.r.start_thrust = 350.0;
        strcpy(pl.r.propulsion, "Liquid");
        strcpy(pl.r.rocket_type, "RLV-TD");
        pl.p.weight = 2000;
        break;
    case 3:
        pl.r.fuel_capacity = 5000.00;
        pl.r.height = 43.43;
        pl.r.start_thrust = 500.0;
        strcpy(pl.r.propulsion, "Solid+Liquid+Cryogenic");
        strcpy(pl.r.rocket_type, "GSLV-Mark III");
        pl.p.weight = 1500;
        break;
    // default:
    //     break;
    }
    setColor(7);
    printf("\nGood..Now lets start the actual Mission..");
    fflush(stdin);
    getch();
    return pl;
}

short countdown(player pl)
{
    cls();
    slowprint(11,"Assessing rocket capability..");
    msleep(1500);
    int check=capability_fail(pl.r.fuel_capacity,pl.r.start_thrust);
    setColor(12);
    printf("\n%s",(check==1 ? "Capable" : "Not Capable"));
    error_disp("\n[EXP00-A FAILED- PARENTHESES]\n[PRE00-A FAILED-INLINE AGAINST MACROS]");
    check=capability_pass(pl);
    setColor(10);
    printf("\n%s",(check==1 ? "Rocket now Capable" : "Not Capable"));
    printf("\nIssue fixed!");
    msleep(1000);
    fflush(stdin);
    getch();
    setColor(11);
    printf("\nRocket countdown..begins..NOW!\n");
    msleep(500);
    short c;
    while (c != -1)
    {
        printf("%d", c);
        msleep(1000);
        printf("\b");
        c--;
    }
    error_disp("\n[EXP33-C FAILED - UNINITIALIZED VARIABLES]"); 
    setColor(10);
    printf("\nIssue fixed!\n");
    cls();
    flashy_text(11,"Rocket countdown begins NOW!!");
    setColor(14);
    c=9;
    printf("\n");
    while(c!=-1)
    {
        printf("%d",c);
        msleep(1000);
        printf("\b");
        c--;
    }
    msleep(1000);
    slowprint(10,"\nRocket ignition successful!");
    msleep(1000);
    slowprint(14,"\nRocket acheving escape velocity..");
    float vel=getVelocity(pl);
    printf("\nRocket's velocity: %lf",vel);
    if(!(vel==11))
    {
        setColor(12);
        printf("\nSeems like the rocket is failing..");
        printf("\n[FLP32C - DOMAIN ERRORS IN MATH FUNCTIONS FAILED]!");
        setColor(10);
        printf("\nFixing..\n");
        flashy_text(10,"Sucessful!");
        getch();
    }
    cls();
    slowprint(11,"\nRocket velocity now =11km/s.. Escape velocity reached!");
    msleep(1000);
    slowprint(11,"\nRocket is in motion NOW!..SUCCESS!");
    // msleep(1500);
    fflush(stdin);
    getch();
    short success=1;
    return success;
}

short phase1(player pl)
{
    cls();
    slowprint(3,"Entering rocket deploy monitor page...");
    msleep(2000);
    cls();
    line_displayer(14);
    setColor(11);
    printf("\t\t\t\t\t\tROCKET MONITOR CENTRE\n");
    line_displayer(14);
    msleep(1500);
    setColor(10);
    printf("\nRocket altitude :");
    setColor(11);
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
        msleep(1000);
    }
    msleep(1000);
    printf("\nRocket reached optimal altitude for phase1..");
    msleep(1000);
    printf("\nLower body seperation initiated..");
    msleep(1000);
    printf("\n");
    flashy_text(10,"SUCCESSFUL!!");
    msleep(1000);
    slowprint(6,"\nEntering PHASE 2..");
    short ph=1;
    msleep(1000);
    return ph;
}
short phase2(player pl)
{
    cls();
    line_displayer(14);
    setColor(11);
    printf("\t\t\t\t\t\tROCKET MONITOR CENTRE\n");
    line_displayer(14);
    setColor(10);
    msleep(1500);
    printf("\nRocket altitude :");
    setColor(11);
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
        msleep(1000);
    }
    msleep(1000);
    printf("\nRocket reached optimal altitude for phase2..");
    msleep(1000);
    printf("\nMiddle body seperation initiated..");
    msleep(1000);
    printf("\n");
    flashy_text(10, "SUCCESSFUL!!");
    msleep(1000);
    slowprint(6, "\nEntering PHASE 2..");
    short ph=1;
    msleep(1000);
    return ph;
}
short phase3(player pl)
{
    cls();
    line_displayer(14);
    setColor(11);
    printf("\t\t\t\t\t\tROCKET MONITOR CENTRE\n");
    line_displayer(14);
    setColor(10);
    msleep(1500);
    printf("\nRocket altitude :");
    setColor(11);
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
        msleep(1000);
    }
    msleep(1000);
    setColor(11);
    printf("\nRocket reached deploy Point!!");
    msleep(1000);
    slowprint(13,"\nInitiating satellite deploy..\n");
    msleep(1000);
    flashy_text(10,"SUCCESSFUL!!");
    msleep(1000);
    short ph=1;
    msleep(1000);
    return ph;
}

short payloadDeployed(player pl)
{
    cls();
    slowprint(10,"Good job!..Now we'll actually find if the rumours of life on Planet Omicron are True..");
    msleep(2000);
    slowprint(11,"\nNow this launch assisst will help you in communicating with your satellite deployed..");
    msleep(2000);
    slowprint(11,"\nYour satellite will be sending messages at periodic intervals of time..");
    msleep(2000);
    slowprint(6,"\nOver to satellite communication protocol please..");
    getch();
    cls();
    line_displayer(10);
    printf("\t\t\t\t\t\t");
    setColor(13);
    setBackgroundColor(14);
    printf("SATELLITE COMMUNICATION PROTOCOL");
    setBackgroundColor(0);
    printf("\n\n");
    line_displayer(10);
    slowprint(11,"\nEnabling AI assisted Translation & Decoding Protocol..");
    msleep(1000);
    slowprint(5,"\nSuccesfully Enabled!");
    msleep(1000);
    slowprint(6,"\nDoing a test Run");
    dots(6,2);
    msleep(2000);
    launchtest_run();
    printf("\nTest Run SUCCESS!");
    msleep(1000);
    cls();
    line_displayer(10);
    printf("\t\t\t\t\t\t");
    setColor(13);
    setBackgroundColor(14);
    printf("SATELLITE COMMUNICATION PROTOCOL");
    setBackgroundColor(0);
    printf("\n\n");
    line_displayer(10);
    msleep(500);
    setColor(11);
    printf("\n%s",pl.p.satellite_name);
    setBackgroundColor(5);
    slowprint(11,": Arcane microbiological life detected..Sending genomes");
    setBackgroundColor(0);
    msleep(3000);
    setColor(11);
    printf("\n\n%s", pl.p.satellite_name);
    setBackgroundColor(5);
    slowprint(11, ": Analyzing genome samples obtained");
    setBackgroundColor(0);
    msleep(3000);
    setColor(11);
    printf("\n\n%s", pl.p.satellite_name);
    setBackgroundColor(5);
    slowprint(11, ": Genome (RNA-ATCU schema) sequence being sent");
    setBackgroundColor(0);
    msleep(3000);
    setColor(8);
    printf("\nExiting satellite protocol..");
    msleep(3000);
    slowprint(11,"\nHere's the Genome sequence obtained..");
    char genomesequence[] = "gcauacac??'??]??)??(ucgcuaugucgauaacaac";
    printf("\n");
    slowprint(13,genomesequence);
    msleep(2000);
    slowprint(6,"\nWait..what!? Genome sequence is corrupted!\n");
    msleep(1000);
    setColor(12);
    printf("\n[PRE05-A FAILED TRIGRAPHS CHECK]");
    msleep(2000);
    setColor(11);
    printf("\nOkay time to call the technicians..");
    msleep(2000);
    printf("\nFixing the problem..");
    char new_genomesequence[] = "gcauacac??ucgcuaugucgauaacaac";
    getch();
    cls();
    slowprint(14,"\nNew Sequence: ");
    setColor(13);
    printf("%s",new_genomesequence);
    msleep(5000);
    getch();
    char buffer[80];
    sprintf(buffer,"\nOkay Great Work Scientist %s!\nYou've found extraterrestrial life!\n", pl.name);
    slowprint(11, buffer);
    msleep(3000);
    char buff[30];
    sprintf(buff, "*Praises and shouts for Researcher %s! *", pl.name);
    printf("\n");
    flashy_text(11,buff);
    msleep(2000);
    getch();
    slowprint(14,"\nOne Thing.. Please forgive the programmers for desigining this horrible Rocket Launch Assist!");
    getch();
    printf("\nGoodbye %s. Your mission with payload %s is SUCCESSFUL..",pl.name,pl.p.satellite_name);
    printf("\nUntil next Time..");
    getch();
}
