#include"headers.h"

void launchtest_run()
{
    //STR00-A   STR01-A
    slowprint(9,"\nThis will be over soon..");
   Sleep(1000);
    string_m a=NULL;
    char *cstr;
    strcreate_m(&a,"Hi demo translation!",0,NULL);
    cstr=getstrptr_m(a);
    printf("\n");
   //setBackgroundColor(13);
    slowprint(11,cstr);
   //setBackgroundColor(0);
    free(cstr);
    slowprint(6,"\n[ABIDING STR00-A USE TR24731 STANDARD FOR STRING MANIPULATION]");
    slowprint(6,"\n[ABIDING STR01-A USING MANANGED LIBRARY ]");
    getchar();
}

short payloadDeployed(player pl)
{
    system("cls");
    slowprint(10,"Good job!..Now we'll actually find if the rumours of life on Planet Omicron are True..");
   Sleep(2000);
    slowprint(11,"\nNow this launch assisst will help you in communicating with your satellite deployed..");
   Sleep(2000);
    slowprint(11,"\nYour satellite will be sending messages at periodic intervals of time..");
   Sleep(2000);
    slowprint(6,"\nOver to satellite communication protocol please..");
    getchar();
    system("cls");
    line_displayer(10);
    printf("\t\t\t\t\t\t");
   //setColor(13);
   //setBackgroundColor(14);
    printf("SATELLITE COMMUNICATION PROTOCOL");
   //setBackgroundColor(0);
    printf("\n\n");
    line_displayer(10);
    slowprint(11,"\nEnabling AI assisted Translation & Decoding Protocol..");
   Sleep(1000);
    slowprint(13,"\nSuccesfully Enabled!");
   Sleep(1000);
    slowprint(6,"\nDoing a test Run");
    dots(6,2);
   Sleep(2000);
    launchtest_run();
    printf("\nTest Run SUCCESS!");
   Sleep(1000);
    fflush(stdin);
    getchar();
    system("cls");
    line_displayer(10);
    printf("\t\t\t\t\t\t");
   //setColor(13);
   //setBackgroundColor(14);
    printf("SATELLITE COMMUNICATION PROTOCOL");
   //setBackgroundColor(0);
    printf("\n\n");
    line_displayer(10);
   Sleep(500);
   //setColor(11);
    printf("\n%s",pl.p.satellite_name);
   //setBackgroundColor(13);
    slowprint(11,": Arcane microbiological life detected..Sending genomes");
   //setBackgroundColor(0);
   Sleep(3000);
   //setColor(11);
    printf("\n\n%s", pl.p.satellite_name);
   //setBackgroundColor(13);
    slowprint(11, ": Analyzing genome samples obtained");
   //setBackgroundColor(0);
   Sleep(3000);
   //setColor(11);
    printf("\n\n%s", pl.p.satellite_name);
   //setBackgroundColor(13);
    slowprint(11, ": Genome (RNA-ATCU schema) sequence being sent");
   //setBackgroundColor(0);
   Sleep(3000);
   //setColor(8);
    printf("\nExiting satellite protocol..");
   Sleep(3000);
    slowprint(11,"\nHere's the Genome sequence obtained..");
    char genomesequence[] = "gcauacac??'??]??)??(ucgcuaugucgauaacaac";
    printf("\n");
    slowprint(13,genomesequence);
   Sleep(2000);
    slowprint(6,"\nWait..what!? Genome sequence is corrupted!\n");
   Sleep(1000);
   //setColor(12);
    printf("\n[PRE05-A FAILED TRIGRAPHS CHECK]");
   Sleep(2000);
   //setColor(11);
    printf("\nOkay time to call the technicians..");
   Sleep(2000);
    printf("\nFixing the problem..");
    char new_genomesequence[] = "gcauacac??ucgcuaugucgauaacaac";
    getchar();
    system("cls");
    slowprint(14,"\nNew Sequence: ");
   //setColor(13);
    printf("%s",new_genomesequence);
   Sleep(5000);
    getchar();
    char buffer[80];
    sprintf(buffer,"\nOkay Great Work Scientist %s!\nYou've found extraterrestrial life!\n", pl.name);
    slowprint(11, buffer);
   Sleep(3000);
    char buff[30];
    sprintf(buff, "*Praises and shouts for Researcher %s! *", pl.name);
    printf("\n");
    flashy_text(11,buff);
   Sleep(2000);
    getchar();
    slowprint(14,"\nOne Thing.. Please forgive the programmers for desigining this horrible Rocket Launch Assist!");
    getchar();
    printf("\nGoodbye %s. Your mission with payload %s is SUCCESSFUL..",pl.name,pl.p.satellite_name);
    printf("\nUntil next Time..");
    getchar();
    return 1;
}
