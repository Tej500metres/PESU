#include"headers.h"

player displayStartScreen1()
{
    //setColor(15);
    //setBackgroundColor(0);
    // saveDefaultColor();
    char badchars[]="@%^&*#$?()|";
    int count=0;
    player p;
    do
    {
        system("cls");
       //setColor(11);
        line_displayer(14);
        printf("\t\t\t\t\t");
       //setBackgroundColor(1);
        flashy_text(14,"ROCKET LAUNCH ASSIST");
       //setBackgroundColor(0);
        printf("\n");
        line_displayer(14);
       //setColor(11);
        slowprint(11,"\n\n\nEnter name:");
        // scanf("%^[\n]s",p.name);
        // fflush(stdin);
        scanf("%19s",p.name); //STR34-C
        count=strspn(p.name,badchars);  //STR02-C
        if(count>0)
        {
           //setColor(4);
            printf("\n[STR02-C FAILED - SANITIZATION]");
            slowprint(4,"\nSorry please dont include special characters!\n");
           Sleep(2000);
           //setColor(11);
        }
    } while (count!=0);
   Sleep(2000);
   //setColor(6);
    printf("\n[FOLLOWING STR34-C - DONT COPY UNBOUNDED DATA TO FIXED LENGTH ARRAY]");
   Sleep(2000);
   //setColor(11);
    getchar();
    return p;
}

player displayStartScreen2(player pl)
{
    system("cls");
    slowprint(14,"You're on a mission to launch a satellite to");
    slowprint(6," 'Planet Omicron'");
    dots(6,3);
    slowprint(10,"\nThis mission is to find extraterrestial life supporting planets..");
   //setColor(11);
    printf("\nAre you ready?? - Y/y :");
    fflush(stdin);
    char c=getchar();
    if(c=='Y' || c=='y')
    {
        fflush(stdin);//FIO09-A
        slowprint(3,"\nGood..\nNow please enter your payload Name(max 19 chars): ");
        fgets(pl.p.satellite_name, 20, stdin);// FIO37-C  STR31-C STR03-A
        char *loc=strchr(pl.p.satellite_name,'\n'); //FIO36-C
        *loc='\0';
       //setColor(6);
        printf("\n[FOLLOWING STR31-C - STRING STORAGE SPACE]");
        printf("\n[FOLLOWING STR03-A - STRING TRUNCATION]");
       //setColor(3);
        printf("\nPayload Name: %s",pl.p.satellite_name);
       Sleep(2000);
        // printf("\nChoose Payload weight :\n1.upto 1500kg\n2.1500-2000kg\n3.2000-4000kg");
        // printf("Enter choice");
        // scanf("%d",&ch);
        printf("\n");
        flashy_text(10,"Great! Let's get started with your mission..");
        printf("\n");
        fflush(stdin);
        getchar();
        return pl;
    }
    exit(0);  
}

player decideRocket(player pl)
{
    int ch;
    system("cls");
    slowprint(11,"\t1.PSLV - XL");
   //setColor(14);
    printf("\nHeight:44m\nStart Thrust:300kN\nPropulsion:Solid +Liquid");
    printf("\nPayload limit:1500kg\nFuel Capacity: 3000 units");
    slowprint(11,"\n\n\t2.RLV-TD");
   //setColor(14);
    printf("\nHeight:48m\nStart Thrust:350kN\nPropulsion:Liquid");
    printf("\nPayload limit:2000kg\nFuel Capacity: 3500 units");
    slowprint(11, "\n\n\t3.GSLV-Mark III");
   //setColor(14);
    printf("\nHeight:43.43m\nStart Thrust:500kN\nPropulsion:Solid+Liquid+Cryogenic");
    printf("\nPayload limit:4000kg\nFuel Capacity: 5000 units");
   //setColor(10);
    printf("\n\nEnter your choice: ");
    // resetColor();
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
   //setColor(7);
    printf("\nGood..Now lets start the actual Mission..");
    fflush(stdin);
    getchar();
    return pl;
}
