# Student Record Management System

A C-based Student Record Management System developed using **GCC**, **Structures**, **Pointers**, **Singly Linked Lists**, **Dynamic Memory Allocation**, and **File Handling**.

## Features

* Add new student records
* Automatically assign the smallest available Roll Number
* Delete records by Roll Number or Name
* Display all student records
* Modify student Name or Percentage
* Search records by Roll Number, Name, or Percentage
* Sort records by Name or Percentage
* Save records to a file
* Load records automatically when the program starts
* Save and Exit / Exit without Saving

## Project Structure

```text
student_record/
│
├── main.c
├── stud_add.c
├── stud_del.c
├── stud_show.c
├── stud_mod.c
├── stud_save.c
├── stud_sort.c
└── student.h
```

## Technologies Used

* C Programming
* GCC Compiler
* Structures
* Pointers
* Singly Linked Lists
* Dynamic Memory Allocation
* File Handling
* Multiple Source Files

## Data Stored

Each student record contains:

* Roll Number
* Name
* Percentage

## File Handling

Student records are stored in:

```text
student.dat
```

The program loads saved records when it starts and saves records when the user selects the Save option.

## Menu

```text
**** STUDENT RECORD MENU ****
A/a : Add New Record
D/d : Delete a Record
S/s : Show the List
M/m : Modify a Record
V/v : Save
T/t : Sort the List
E/e : Exit
```

## Compilation Using GCC

Compile all source files together:

```bash
gcc main.c stud_add.c stud_del.c stud_show.c stud_mod.c stud_save.c stud_sort.c -o student
```

## Run the Program

### Linux / macOS

```bash
./student
```

### Windows

```bash
student.exe
```

## Requirements

* GCC compiler
* Standard C library
* Terminal / Command Prompt

## Author

Karthikraj
