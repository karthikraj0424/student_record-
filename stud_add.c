#include <stdio.h>
#include <stdlib.h>
#include "student.h"

void stud_add(struct Student **head)
{
    struct Student *newNode;
    struct Student *temp;
    int roll = 1;

    newNode = malloc(sizeof(struct Student));

    if (newNode == NULL)
    {
        printf("\nMemory allocation failed!\n");
        return;
    }

    while (1)
    {
        int found = 0;

        temp = *head;

        while (temp != NULL)
        {
            if (temp->rollNo == roll)
            {
                found = 1;
                break;
            }

            temp = temp->next;
        }

        if (!found)
        {
            break;
        }

        roll++;
    }

    newNode->rollNo = roll;

    printf("\nEnter Student Name: ");
    scanf(" %[^\n]", newNode->name);

    printf("Enter Percentage: ");
    scanf("%f", &newNode->percentage);

    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        temp = *head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    printf("\nRecord added successfully!\n");
    printf("Assigned Roll Number: %d\n", newNode->rollNo);
}