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
    person* p=NULL;
    int time=0,i=1;
    while(tmp!=NULL)       //loops over all the terminals
    {
        p=tmp->q;
        tmp->waitingTime=0;
        i=1;
        while(p!=NULL)          
        {
            time=time+p->time;
            if(i!=1) 
                tmp->waitingTime= tmp->waitingTime+time-p->time;
            printf("%d(%d)---%d(%d)  ",time,tmp->waitingTime,p->time,p->priority);
            ++i;
            if(p->next!=NULL)
                p=p->next;
            else
            {
                break;
            }
            
        }
        printf("\n");
        if(tmp->next!=NULL)
            tmp=tmp->next;
        else
        {
            break;
        }
        
    }
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
    if(numOfTerminals==0)
    {
        printf("Presently all Terminals are dead.We are opening one for New Passengers.\n");
    }
    head=createTerminals(i,sizeOfTerminal);
    i++;
    terminal* temp=head;
    while(i<=numOfTerminals )
    {
        temp->next=createTerminals(i,sizeOfTerminal);
        temp=temp->next;
        i++;
    }
    return head;          //This is returned to the main function
}

terminal* initialise(terminal *head)
{
    terminal* temp=head;
    int i,j=1;
    while(temp!=NULL)         //lops over all the terminals
    {
        srand(time(NULL)+rand());           //to set a random seed value for 
        i=1;
        temp->q=addPersonToQueue(temp,temp->q,(rand()%10)+1,(rand()%4)+1); 
        temp->functional=1;
        temp->curStatus++;
        i++;
        while(i<(rand()%temp->maxCapacity))           //loops random number of times to add random number of people to the queue
        {
            temp->q=addPersonToQueue(temp,temp->q,(rand()%10)+1,(rand()%4)+1);  
            temp->curStatus++;          //increments terminal's metadata
            i++;
        }
        temp=temp->next;    //moves on to next terminal
        j++;
    }
    printf("\nInitialisation successful\n");
    head=updateWaitingTime(head);
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
            if(temp->waitingTime <=  minWaitingTime)
            {
                minWaitingTime=temp->waitingTime;
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
    terminal *tempTerminal=head;
    terminal *allocatedTerminal=NULL;
    int Time=-1;
    printf("\n1] Add a person\n2] fast forward time\n\n Enter your choice [1/2] : ");
    scanf("%d",&choice);
    // while()
    if(choice==1){
        printf("Enter the person detail [ VIP(0) / pregnant_women(1) / old(2) / handicapped(3) / normal(4 or any other number)] : ");
        scanf("%d",&inputNumber);
        srand(time(NULL)+rand());
        allocatedTerminal=searchFastestTerminal(head);
        Time=rand()%10+1;
        switch (inputNumber)
        {
            case 0 :
                allocatedTerminal->q = addPersonToQueue(allocatedTerminal,allocatedTerminal->q,
                Time,0);
                break;
            case 1 :
                allocatedTerminal->q = addPersonToQueue(allocatedTerminal,allocatedTerminal->q,Time,1);
                break;
            case 2 :
                allocatedTerminal->q = addPersonToQueue(allocatedTerminal,allocatedTerminal->q,Time,2);
                break;
            case 3 :
                allocatedTerminal->q = addPersonToQueue(allocatedTerminal,allocatedTerminal->q,Time,3);
                break;
            default :
                allocatedTerminal->q = addPersonToQueue(allocatedTerminal,allocatedTerminal->q,Time,4);
                break;
        }
        allocatedTerminal->curStatus++;
        head=updateWaitingTime(head);
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
