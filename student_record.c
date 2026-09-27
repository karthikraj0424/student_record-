#include <stdio.h>
#include <string.h>

#define MAX 100

struct Student
{
    int rollNo;
    char name[50];
    int age;
    float marks;
};

void addStudent(struct Student students[], int *count);
void displayStudents(struct Student students[], int count);
void searchStudent(struct Student students[], int count);
void updateStudent(struct Student students[], int count);
void deleteStudent(struct Student students[], int *count);
void highestMarks(struct Student students[], int count);
void averageMarks(struct Student students[], int count);

int main()
{
    struct Student students[MAX];
    int count = 0;
    int choice;

    while (1)
    {
        printf("\n===== STUDENT RECORD MANAGEMENT =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Highest Marks\n");
        printf("7. Average Marks\n");
        printf("8. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addStudent(students, &count);
                break;

            case 2:
                displayStudents(students, count);
                break;

            case 3:
                searchStudent(students, count);
                break;

            case 4:
                updateStudent(students, count);
                break;

            case 5:
                deleteStudent(students, &count);
                break;

            case 6:
                highestMarks(students, count);
                break;

            case 7:
                averageMarks(students, count);
                break;

            case 8:
                printf("\nProgram ended.\n");
                return 0;

            default:
                printf("\nInvalid choice!\n");
        }
    }

    return 0;
}

void addStudent(struct Student students[], int *count)
{
    if (*count >= MAX)
    {
        printf("\nStudent limit reached!\n");
        return;
    }

    printf("\nEnter Roll Number: ");
    scanf("%d", &students[*count].rollNo);

    printf("Enter Name: ");
    scanf(" %[^\n]", students[*count].name);

    printf("Enter Age: ");
    scanf("%d", &students[*count].age);

    printf("Enter Marks: ");
    scanf("%f", &students[*count].marks);

    (*count)++;

    printf("\nStudent added successfully!\n");
}

void displayStudents(struct Student students[], int count)
{
    int i;

    if (count == 0)
    {
        printf("\nNo student records found!\n");
        return;
    }

    printf("\n===== STUDENT RECORDS =====\n");

    for (i = 0; i < count; i++)
    {
        printf("\nStudent %d\n", i + 1);
        printf("Roll Number : %d\n", students[i].rollNo);
        printf("Name        : %s\n", students[i].name);
        printf("Age         : %d\n", students[i].age);
        printf("Marks       : %.2f\n", students[i].marks);
    }
}

void searchStudent(struct Student students[], int count)
{
    int roll, i;
    int found = 0;

    printf("\nEnter Roll Number to search: ");
    scanf("%d", &roll);

    for (i = 0; i < count; i++)
    {
        if (students[i].rollNo == roll)
        {
            printf("\nStudent Found!\n");
            printf("Roll Number : %d\n", students[i].rollNo);
            printf("Name        : %s\n", students[i].name);
            printf("Age         : %d\n", students[i].age);
            printf("Marks       : %.2f\n", students[i].marks);

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\nStudent not found!\n");
    }
}

void updateStudent(struct Student students[], int count)
{
    int roll, i;
    int found = 0;

    printf("\nEnter Roll Number to update: ");
    scanf("%d", &roll);

    for (i = 0; i < count; i++)
    {
        if (students[i].rollNo == roll)
        {
            printf("\nEnter New Name: ");
            scanf(" %[^\n]", students[i].name);

            printf("Enter New Age: ");
            scanf("%d", &students[i].age);

            printf("Enter New Marks: ");
            scanf("%f", &students[i].marks);

            found = 1;

            printf("\nStudent record updated successfully!\n");
            break;
        }
    }

    if (!found)
    {
        printf("\nStudent not found!\n");
    }
}

void deleteStudent(struct Student students[], int *count)
{
    int roll, i, j;
    int found = 0;

    printf("\nEnter Roll Number to delete: ");
    scanf("%d", &roll);

    for (i = 0; i < *count; i++)
    {
        if (students[i].rollNo == roll)
        {
            for (j = i; j < *count - 1; j++)
            {
                students[j] = students[j + 1];
            }

            (*count)--;
            found = 1;

            printf("\nStudent record deleted successfully!\n");
            break;
        }
    }

    if (!found)
    {
        printf("\nStudent not found!\n");
    }
}

void highestMarks(struct Student students[], int count)
{
    int i;
    int highest;

    if (count == 0)
    {
        printf("\nNo student records found!\n");
        return;
    }

    highest = 0;

    for (i = 1; i < count; i++)
    {
        if (students[i].marks > students[highest].marks)
        {
            highest = i;
        }
    }

    printf("\n===== HIGHEST MARKS =====\n");
    printf("Roll Number : %d\n", students[highest].rollNo);
    printf("Name        : %s\n", students[highest].name);
    printf("Marks       : %.2f\n", students[highest].marks);
}

void averageMarks(struct Student students[], int count)
{
    int i;
    float sum = 0;
    float average;

    if (count == 0)
    {
        printf("\nNo student records found!\n");
        return;
    }

    for (i = 0; i < count; i++)
    {
        sum += students[i].marks;
    }

    average = sum / count;

    printf("\nAverage Marks = %.2f\n", average);
}