#include <stdio.h>
#include "student.h"

void stud_show(struct Student *head)
{
    struct Student *temp = head;

    if (head == NULL)
    {
        printf("\nNo student records found!\n");
        return;
    }

    printf("\n---------------------------------------------\n");
    printf("%-10s %-20s %-10s\n",
           "Roll No", "Name", "Percentage");
    printf("---------------------------------------------\n");

    while (temp != NULL)
    {
        printf("%-10d %-20s %-10.2f\n",
               temp->rollNo,
               temp->name,
               temp->percentage);

        temp = temp->next;
    }

    printf("---------------------------------------------\n");
}