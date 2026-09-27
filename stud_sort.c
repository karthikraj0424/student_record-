#include <stdio.h>
#include <string.h>
#include "student.h"

void stud_sort(struct Student *head)
{
    char choice;

    struct Student *i;
    struct Student *j;

    if (head == NULL)
    {
        printf("\nNo student records found!\n");
        return;
    }

    printf("\nN/n : Sort by Name\n");
    printf("P/p : Sort by Percentage\n");

    printf("\nEnter Your Choice: ");
    scanf(" %c", &choice);

    if (choice == 'N' || choice == 'n')
    {
        for (i = head; i != NULL; i = i->next)
        {
            for (j = i->next; j != NULL; j = j->next)
            {
                if (strcmp(i->name, j->name) > 0)
                {
                    int tempRoll;
                    float tempPercentage;
                    char tempName[50];

                    tempRoll = i->rollNo;
                    i->rollNo = j->rollNo;
                    j->rollNo = tempRoll;

                    tempPercentage = i->percentage;
                    i->percentage = j->percentage;
                    j->percentage = tempPercentage;

                    strcpy(tempName, i->name);
                    strcpy(i->name, j->name);
                    strcpy(j->name, tempName);
                }
            }
        }

        printf("\nRecords sorted by name successfully!\n");
    }
    else if (choice == 'P' || choice == 'p')
    {
        for (i = head; i != NULL; i = i->next)
        {
            for (j = i->next; j != NULL; j = j->next)
            {
                if (i->percentage > j->percentage)
                {
                    int tempRoll;
                    float tempPercentage;
                    char tempName[50];

                    tempRoll = i->rollNo;
                    i->rollNo = j->rollNo;
                    j->rollNo = tempRoll;

                    tempPercentage = i->percentage;
                    i->percentage = j->percentage;
                    j->percentage = tempPercentage;

                    strcpy(tempName, i->name);
                    strcpy(i->name, j->name);
                    strcpy(j->name, tempName);
                }
            }
        }

        printf("\nRecords sorted by percentage successfully!\n");
    }
    else
    {
        printf("\nInvalid choice!\n");
    }
}