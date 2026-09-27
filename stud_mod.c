#include <stdio.h>
#include <string.h>
#include "student.h"

void stud_mod(struct Student *head)
{
    char choice;
    int roll;
    char name[50];
    float percentage;

    struct Student *temp;
    int found = 0;

    if (head == NULL)
    {
        printf("\nNo student records found!\n");
        return;
    }


    printf("\nR/r : Roll Number\n");
    printf("N/n : Name\n");
    printf("P/p : Percentage\n");

    printf("\nEnter Your Choice: ");
    scanf(" %c", &choice);

    /* Search by Roll Number */
    if (choice == 'R' || choice == 'r')
    {
        printf("\nEnter Roll Number: ");
        scanf("%d", &roll);

        temp = head;

        while (temp != NULL)
        {
            if (temp->rollNo == roll)
            {
                found = 1;
                break;
            }

            temp = temp->next;
        }
    }


    else if (choice == 'N' || choice == 'n')
    {
        printf("\nEnter Name: ");
        scanf(" %[^\n]", name);

        printf("\nMatching Records:\n");
        printf("---------------------------------------------\n");
        printf("%-10s %-20s %-10s\n",
               "Roll No", "Name", "Percentage");
        printf("---------------------------------------------\n");

        temp = head;

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

        printf("\nEnter Roll Number to modify: ");
        scanf("%d", &roll);

        temp = head;
        found = 0;

        while (temp != NULL)
        {
            if (temp->rollNo == roll &&
                strcmp(temp->name, name) == 0)
            {
                found = 1;
                break;
            }

            temp = temp->next;
        }
    }

    
    else if (choice == 'P' || choice == 'p')
    {
        printf("\nEnter Percentage: ");
        scanf("%f", &percentage);

        printf("\nMatching Records:\n");
        printf("---------------------------------------------\n");
        printf("%-10s %-20s %-10s\n",
               "Roll No", "Name", "Percentage");
        printf("---------------------------------------------\n");

        temp = head;

        while (temp != NULL)
        {
            if (temp->percentage == percentage)
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

        printf("\nEnter Roll Number to modify: ");
        scanf("%d", &roll);

        temp = head;
        found = 0;

        while (temp != NULL)
        {
            if (temp->rollNo == roll &&
                temp->percentage == percentage)
            {
                found = 1;
                break;
            }

            temp = temp->next;
        }
    }

    else
    {
        printf("\nInvalid choice!\n");
        return;
    }

    if (!found)
    {
        printf("\nStudent not found!\n");
        return;
    }



    printf("\nN/n : Name\n");
    printf("P/p : Percentage\n");

    printf("\nEnter Your Choice: ");
    scanf(" %c", &choice);

    if (choice == 'N' || choice == 'n')
    {
        printf("\nEnter New Name: ");
        scanf(" %[^\n]", temp->name);

        printf("\nRecord modified successfully!\n");
    }
    else if (choice == 'P' || choice == 'p')
    {
        printf("\nEnter New Percentage: ");
        scanf("%f", &temp->percentage);

        printf("\nRecord modified successfully!\n");
    }
    else
    {
        printf("\nInvalid choice!\n");
    }
}