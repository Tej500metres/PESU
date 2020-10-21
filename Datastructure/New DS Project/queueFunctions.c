#include <stdio.h>
#include <stdlib.h>
#include "header.h"

person *newPerson(int time, int priority)
{
    person *temp = (person *)malloc(sizeof(person));
    if (temp == NULL)
    {
        printf("malloc() Error\n");
        exit(10);
    }
    temp->time = time;
    temp->priority = priority;
    temp->next = NULL;
    return temp;
}

// Return the value at head
int peek(person **head)
{
    return (*head)->time;
}

// Removes the element with the
// highest priority form the list
int pop(person **head)
{
    person *temp = *head;
    (*head) = (*head)->next;
    return temp->time;
}

// Function to push according to priority
person *addPersonToQueue(terminal* ter,person *head, int time, int priority)
{
    person *start = head,*start1=head;
    // Create new person
    int waitingTime = 0;
    person *temp =head;
    if (head == NULL)
    {
        head = newPerson(time,priority);
        temp=head;
        waitingTime = temp->time;
        start1=head;
    }
    else
    {
        temp=newPerson(time,priority);
        // Special Case: The head of list has lesser
        // priority than new person. So insert new
        // person before head person and change head person.
        if (priority < (head->priority))
        {
            // Insert New person before head
            temp->next = head;
            head = temp;
            waitingTime  = waitingTime + temp->time;
            start1=head;
        }
        else
        {
            start1 = head;
            // Traverse the list and find a
            // position to insert new person
            while (start != NULL &&
                   priority >= start ->priority)
            {
                start1=start;
                waitingTime += start->time;
                start = start->next;
            }
            // Either at the ends of the list
            // or at required position 1 2 5
            temp->next = start1->next;
            waitingTime+=temp->time;
            start1->next = temp;
        }
    }
    printf("\nPerson added to terminal number %d.\nPlease ask the person to go to terminal  %d\nHis/her waiting time is %d minutes.\n\n\n",ter->terminalNumber,ter->terminalNumber,waitingTime-temp->time);
    printf("(Added person with time %d and priority %d)\n\n",time,priority);
    return head;
}
// Function to check is list is empty
int isEmpty(person **head)
{
    return (*head) == NULL;
}
