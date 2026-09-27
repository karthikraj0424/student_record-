#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

void stud_del(struct Student **head)
{
    char choice;
    int roll;
    char name[50];

    if (*head == NULL)
    {
        printf("\nNo student records found!\n");
        return;
    }

    printf("\nR/r : Delete using Roll Number\n");
    printf("N/n : Delete using Name\n");

    printf("\nEnter Your Choice: ");
    scanf(" %c", &choice);

    if (choice == 'R' || choice == 'r')
    {
        struct Student *temp = *head;
        struct Student *prev = NULL;

        printf("\nEnter Roll Number: ");
        scanf("%d", &roll);

        while (temp != NULL)
        {
            if (temp->rollNo == roll)
            {
                if (prev == NULL)
                    *head = temp->next;
                else
                    prev->next = temp->next;

                free(temp);

                printf("\nRecord deleted successfully!\n");
                return;
            }

            prev = temp;
            temp = temp->next;
        }

        printf("\nStudent not found!\n");
    }
    else if (choice == 'N' || choice == 'n')
    {
        struct Student *temp = *head;
        int found = 0;

        printf("\nEnter Student Name: ");
        scanf(" %[^\n]", name);

        printf("\nMatching Records:\n");
        printf("---------------------------------------------\n");
        printf("%-10s %-20s %-10s\n",
               "Roll No", "Name", "Percentage");
        printf("---------------------------------------------\n");

        while (temp != NULL)
        {
            if (strcmp(temp->name, name) == 0)
            {
                printf("%-10d %-20s %-10.2f\n",
                       temp->rollNo,
                       temp->name,
                       temp->percentage);

                found = 1;
            }

            temp = temp->next;
        }

        if (!found)
        {
            printf("\nNo matching student found!\n");
            return;
        }

        printf("\nEnter Roll Number to delete: ");
        scanf("%d", &roll);

        temp = *head;

        {
            struct Student *prev = NULL;

            while (temp != NULL)
            {
                if (temp->rollNo == roll &&
                    strcmp(temp->name, name) == 0)
                {
                    if (prev == NULL)
                        *head = temp->next;
                    else
                        prev->next = temp->next;

                    free(temp);

                    printf("\nRecord deleted successfully!\n");
                    return;
                }

                prev = temp;
                temp = temp->next;
            }
        }

        printf("\nRoll Number does not match the selected name!\n");
    }
    else
    {
        printf("\nInvalid choice!\n");
    }
}