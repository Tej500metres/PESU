#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include "header.h"

terminal* createTerminals(int i,int sizeOfTerminal)
{
    terminal *temp=(terminal *)malloc(sizeof(terminal));
    if(temp==NULL){
        printf("Memory Allocation of terminal %d failed\n",i);
        exit(10);
    }
    temp->maxCapacity=sizeOfTerminal;           //initialisation of terminal metadata to default values
    temp->curStatus=0;
    temp->functional=0;
    temp->terminalNumber=i;
    temp->q=NULL;
    temp->waitingTime=0;        //moves to the next terminal
    temp->next=NULL;            //last terminal's next will be NULL
    return temp;                //returns the newly created terminal list's head pointer
}

terminal* updateWaitingTime(terminal *head)
{
    terminal *tmp=head;
    printf("HEADUPDATE:");
    printf("%d\n",head->q->time);
    // tmp->q=head->q;
    person* p=NULL;
    while(tmp!=NULL)       //loops over all the terminals
    {
        p=tmp->q;
        tmp->waitingTime=0;
        printf("%s\n","no");
        while(p!=NULL)          
        {
            printf("1\n");            //adds waiting time of all people
            tmp->waitingTime+=p->time; 
            printf("HEADUPDATE:");
            printf("%d\n",head->q->time);
            printf("QWERTY : %d\n",tmp->waitingTime);
            printf("HEADUPDATE:");
            printf("%d\n",head->q->time);
            if(p->next!=NULL)
                p=p->next;
            else
            {
                break;
            }
            
        }
        // tmp->waitingTime+=tmp->q->time; 
            printf("HEADUPDATE:");
            printf("%d\n",head->q->time);
            printf("**** : %d\n",tmp->waitingTime);
            printf("HEADUPDATE:");
            printf("%d\n",head->q->time);
        // tmp2=tmp2->next;
        if(tmp->next!=NULL)
            tmp=tmp->next;
        else
        {
            printf("break\n");
            break;
        }
        
    }
    printf("HEADUPDATE:");
    printf("%d\n",head->q->time);
    return(head);
}

terminal* beginner()
{
    printf("Welcome to Airport Check-in terminal simulator\n\n");
    printf("Press any to start\n");
    getchar();
    system("@cls||clear");          //clears the terminal screen

    char tempString[30];
    int numOfTerminals,sizeOfTerminal;
    printf("Enter number of terminals to create : ");
    scanf("%s",tempString);
    numOfTerminals=atoi(tempString);
    printf("Enter max size for a queue at terminal : ");
    scanf("%s",tempString);
    sizeOfTerminal=atoi(tempString);
    int i=1;
    terminal* head=NULL;
    head=createTerminals(i,sizeOfTerminal);
    i++;
    terminal* temp=head;
    while(i<=numOfTerminals)
    {
        temp->next=createTerminals(i,sizeOfTerminal);
        temp=temp->next;
        i++;
    }
    return head;          //This is returned to the main function
}

terminal* initialise(terminal *head)
{
    terminal* temp=head,*temp1=temp;
    int i,j=1;
    // temp->q=head->q;
    // person* p=NULL;
    while(temp!=NULL)         //lops over all the terminals
    {
        temp1=temp;
        srand(time(NULL)+rand());           //to set a random seed value for rand() function
        // printf("##:%d",j);
        // temp->q=addPersonToQueue(&temp->q,(rand()%10)+1,(rand()%4)+1);           //adds a person with a given random probablity
        // person* p=temp->q;
        // printf("%d\n",i);
        // temp->q=temp->q->next;
        i=1;
        printf("##:%d",j);
        temp->q=addPersonToQueue(temp->q,(rand()%10)+1,(rand()%4)+1); 
        temp->functional=1;
        temp->curStatus++;
        printf("HEAD++++%d++++\n",head->q->time);
        printf("TEMP++++%d++++\n",temp1->q->time);
        printf("outside+++%d+++\n",temp->q->time);
        // temp->q=temp->q->next;
        i++;
        while(i<(rand()%temp->maxCapacity))           //loops random number of times to add random number of people to the queue
        {
            // if(j==1)
            // {
            //     printf("##:%d",j);
            //     head->q=addPersonToQueue(head->q,(rand()%10)+1,(rand()%4)+1); 
            //     head->functional=1;
            //     head->curStatus++;
            //     printf("+++%d+++\n",temp->q->time);
            //     i++;
            // }
            printf("##:%d",j);
            // if(i==1)
            // {
            temp->q=addPersonToQueue(temp->q,(rand()%10)+1,(rand()%4)+1);  
            //     p=temp->q;
            // }         //adds a person with a given random probablity
            
            temp->curStatus++;          //increments terminal's metadata
            // p=temp->q;
            // temp->q=temp->q->next;
            printf("HEAD++++%d++++\n",head->q->time);
            printf("TEMP++++%d++++\n",temp1->q->time);
            printf("inside+++%d+++\n",temp->q->time);
            // printf("%d\n",i);
            i++;
        }
        
        temp=temp->next;    //moves on to next terminal
        j++;
    }
    // printf("%d \n",head->next->next->q->time);
    printf("\nInitialisation successful\n");

    printf("HEAD00++++%d++++\n",head->q->time);
    head=updateWaitingTime(head);
    printf("BeforeHEAD10\n");
    printf("HEAD10++++%d++++\n",head->q->time);
    return head;
}



terminal* initialisePrompt(terminal *head)
{
    char c;
    printf("\nDo you want to initialise the terminals with test passengers[y/n] : ");
    scanf(" %c",&c);
    if(c=='y')
        return initialise(head);
    else
        return head;
}

terminal* displayQueues(terminal *head)
{
    terminal *temp=head;
    while(temp!=NULL)
    {
        printf("Terminal number : %d\n",temp->terminalNumber);
        printf("Total number of people in the queue are %d\n",temp->curStatus);
        printf("Estimated waiting time is %d minutes\n\n",temp->waitingTime);        
        temp=temp->next;
    }
    return head;
}

// terminal* checkIfTerminalisFull(terminal *head)
// {
//     //If all queues are full with the specified maximum limit a new terminal is created
//     terminal *tempTerminal=head,*prevTerminal;
//     int totalTerminals=0,fullTerminals=0;
//     while(tempTerminal!=NULL)
//         {
//             if(tempTerminal->curStatus==tempTerminal->maxCapacity)
//             {
//                 fullTerminals+=1;
//             }
//             totalTerminals+=1;
//             prevTerminal=tempTerminal;
//             tempTerminal=tempTerminal->next;
//         }
//     if(fullTerminals==totalTerminals)
//     {
//         prevTerminal->next=(terminal *)malloc(sizeof(terminal));
//         tempTerminal=prevTerminal->next;
//         tempTerminal->maxCapacity=prevTerminal->maxCapacity;           //initialisation of terminal metadata to default values
//         tempTerminal->curStatus=0;
//         tempTerminal->functional=1;
//         tempTerminal->terminalNumber=prevTerminal->terminalNumber+1;
//         tempTerminal->waitingTime=0;
//         tempTerminal->next=NULL;
//         return tempTerminal;
//     }
//     return NULL;
// }

terminal* searchFastestTerminal(terminal *head)
{
    terminal *temp=head,*temp1=head;
    terminal *minTerminal=head;
    int minWaitingTime=head->waitingTime;
    int foundTerminal=0;
    while(temp!=NULL)
    {
        temp1=temp;
        if(temp->curStatus < temp->maxCapacity)
        {
            printf("!!!!%d!!!!\n",temp->curStatus);
            if(temp->waitingTime <=  minWaitingTime)
            {
                printf("before%d!!!",temp->waitingTime);
                minWaitingTime=temp->waitingTime;
                printf("after%d!!!\n",temp->waitingTime);
                minTerminal=temp;
                foundTerminal=1;
            }
        }
        temp=temp->next;
    }
    if(foundTerminal==0)
    {
        temp1->next=createTerminals(temp1->terminalNumber+1,temp1->maxCapacity);
        temp1=temp1->next;
        minTerminal=temp1;
    }
    printf("minTER:%d\n",minTerminal->terminalNumber);
    printf("SEARCH\n");
    return minTerminal;
}

int findWaitingTime(terminal *root, person *person)
{
    int waitingTime=0;
    terminal *head=root;
    while(head->q!=NULL)
    {
        if(head->q==person)
            return waitingTime+head->q->time;
        else
        {
            waitingTime+=head->q->time;
            head->q=head->q->next;
        }
    }
    return waitingTime;
}


void actualSimulation(terminal *head)
{
    int inputNumber;
    int choice;
    // person *tempPerson;
    terminal *tempTerminal=head;
    terminal *allocatedTerminal=NULL;
    int Time=-1;
    // person* p=NULL;
    // printf("AllocatedTerminal:%d",allocatedTerminal->q->time);
    printf("\n1] Add a person\n2] fast forward time\n\n Enter your choice [1/2] : ");
    scanf("%d",&choice);
    // while()
    if(choice==1){
        printf("Enter the person detail [ VIP(0) / pregnant_women(1) / old(2) / handicapped(3) / normal(4 or any other number)] : ");
        scanf("%d",&inputNumber);
        // inputNumber = getchar();
        srand(time(NULL)+rand());
        allocatedTerminal=searchFastestTerminal(head);
        // p=allocatedTerminal->q;
        // printf("minTermout:%d",allocatedTerminal->terminalNumber);
        // printf("---%d",p->time);
        Time=rand()%10+1;
        switch (inputNumber)
        {
            case 0 :
                allocatedTerminal->q = addPersonToQueue(allocatedTerminal->q,
                Time,0);
                break;
            case 1 :
                allocatedTerminal->q = addPersonToQueue(allocatedTerminal->q,Time,1);
                break;
            case 2 :
                allocatedTerminal->q = addPersonToQueue(allocatedTerminal->q,Time,2);
                break;
            case 3 :
                allocatedTerminal->q = addPersonToQueue(allocatedTerminal->q,Time,3);
                break;
            default :
                allocatedTerminal->q = addPersonToQueue(allocatedTerminal->q,Time,4);
                break;
        }
            allocatedTerminal->curStatus++;
            printf("2nd++++%d  %d++++",allocatedTerminal->q->time,allocatedTerminal->q->priority);
        //printf("%d\n",tempPerson->priority);
        updateWaitingTime(head);
        printf("\nPerson added to terminal number %d.\nPlease ask the person to go to terminal  %d\nHis/her waiting time is %d minutes.\n\n\n",allocatedTerminal->terminalNumber,allocatedTerminal->terminalNumber,allocatedTerminal->waitingTime);
        
        // findWaitingTime(allocatedTerminal,allocatedTerminal->q);
        printf("(Added person with time %d and priority %d)\n\n",Time,allocatedTerminal->q->priority);
        displayQueues(head);
    }
    else{
        int time,removedTime=0,removedPeople=0;
        printf("Enter the amount of time to fast forward [in mins] : ");
        scanf(" %d",&time);
        tempTerminal=head;
        while(tempTerminal!=NULL && tempTerminal->waitingTime!=0)
        {
            removedTime=0;
            removedPeople=0;
            while((isEmpty(&tempTerminal->q)!=1) && (removedTime+peek(&tempTerminal->q))<time)
            {
                removedTime+=pop(&tempTerminal->q);
                removedPeople++;
            }
            tempTerminal->q->time=time-removedTime;
            tempTerminal->curStatus-=removedPeople;
            tempTerminal->waitingTime-=time;
            tempTerminal=tempTerminal->next;
        }
        displayQueues(head);
    }
    
}
