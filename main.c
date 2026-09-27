#include <stdio.h>
#include <stdlib.h>
#include "student.h"

int main()
{
    struct Student *head = NULL;
    char choice;

    stud_load(&head);

    while (1)
    {
        printf("\n**** STUDENT RECORD MENU ****\n");
        printf("A/a : Add New Record\n");
        printf("D/d : Delete a Record\n");
        printf("S/s : Show the List\n");
        printf("M/m : Modify a Record\n");
        printf("V/v : Save\n");
        printf("T/t : Sort the List\n");
        printf("E/e : Exit\n");

        printf("\nEnter Your Choice: ");
        scanf(" %c", &choice);

        switch (choice)
        {
            case 'A':
            case 'a':
                stud_add(&head);
                break;

            case 'D':
            case 'd':
                stud_del(&head);
                break;

            case 'S':
            case 's':
                stud_show(head);
                break;

            case 'M':
            case 'm':
                stud_mod(head);
                break;

            case 'V':
            case 'v':
                stud_save(head);
                break;

            case 'T':
            case 't':
                stud_sort(head);
                break;

            case 'E':
            case 'e':
            {
                char exitChoice;

                printf("\nS/s : Save and Exit\n");
                printf("E/e : Exit Without Saving\n");

                printf("Enter Your Choice: ");
                scanf(" %c", &exitChoice);

                if (exitChoice == 'S' || exitChoice == 's')
                {
                    stud_save(head);
                    printf("\nSaved successfully. Program ended.\n");
                }
                else if (exitChoice == 'E' || exitChoice == 'e')
                {
                    printf("\nExiting without saving.\n");
                }
                else
                {
                    printf("\nInvalid choice!\n");
                    break;
                }

                while (head != NULL)
                {
                    struct Student *temp = head;
                    head = head->next;
                    free(temp);
                }

                return 0;
            }

            default:
                printf("\nInvalid choice!\n");
        }
    }

    return 0;
}