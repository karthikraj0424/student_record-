#ifndef STUDENT_H
#define STUDENT_H

struct Student
{
    int rollNo;
    char name[50];
    float percentage;
    struct Student *next;
};

void stud_add(struct Student **head);
void stud_del(struct Student **head);
void stud_show(struct Student *head);
void stud_mod(struct Student *head);
void stud_save(struct Student *head);
void stud_load(struct Student **head);
void stud_sort(struct Student *head);

#endif