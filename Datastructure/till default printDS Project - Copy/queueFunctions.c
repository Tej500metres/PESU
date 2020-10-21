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
person *addPersonToQueue(person *head, int time, int priority)
{
    person *start = head,*start1=head;
    // Create new person
    int waitingTime = 0;
    person *temp =head;
    if (head == NULL)
    {
        head = newPerson(time,priority);
        temp=head;
        waitingTime += temp->time;
        printf("\nwaitingTime00: %d\n", waitingTime);
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
            waitingTime += temp->time;
            printf("\nwaitingTime01: %d\n", waitingTime);
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
                printf("\nwaitingTime1: %d\n", waitingTime);
                start = start->next;
            }
            // Either at the ends of the list
            // or at required position 1 2 3
            temp->next = start1->next;
            waitingTime += temp->time;
            printf("\nwaitingTime2: %d\n", waitingTime);
            start1->next = temp;
        }
    }
    printf("!@#$&*()%d\n",head->time);
    printf("---temptime:%d ", temp->time);
    printf("starttime:%d ", start1->time);
    printf("priority:%d----\n", temp->priority);
    printf("#%s:%d\n", "His/Her waiting Time is", waitingTime);
    return head;
}
// Function to check is list is empty
int isEmpty(person **head)
{
    return (*head) == NULL;
}
