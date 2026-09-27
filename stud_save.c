#include <stdio.h>
#include <stdlib.h>
#include "student.h"

void stud_save(struct Student *head)
{
    FILE *fp;
    struct Student *temp = head;

    fp = fopen("student.dat", "wb");

    if (fp == NULL)
    {
        printf("\nUnable to open student.dat!\n");
        return;
    }

    while (temp != NULL)
    {
        fwrite(temp, sizeof(struct Student) - sizeof(struct Student *), 1, fp);

        temp = temp->next;
    }

    fclose(fp);

    printf("\nRecords saved successfully!\n");
}

void stud_load(struct Student **head)
{
    FILE *fp;
    struct Student data;
    struct Student *newNode;
    struct Student *temp;

    fp = fopen("student.dat", "rb");

    if (fp == NULL)
    {
        return;
    }

    while (fread(&data,
                 sizeof(struct Student) - sizeof(struct Student *),
                 1,
                 fp) == 1)
    {
        newNode = malloc(sizeof(struct Student));

        if (newNode == NULL)
        {
            printf("\nMemory allocation failed!\n");
            fclose(fp);
            return;
        }

        newNode->rollNo = data.rollNo;

        for (int i = 0; i < 50; i++)
        {
            newNode->name[i] = data.name[i];
        }

        newNode->percentage = data.percentage;
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
    }

    fclose(fp);
}