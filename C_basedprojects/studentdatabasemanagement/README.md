# Student Record Management System

A C-based Student Record Management System using a singly linked list.

## Features

* Add a new student record
* Delete a student record by roll number or name
* Display all student records
* Modify student details
* Save records to a file
* Load records from a file
* Sort records by name
* Sort records by percentage
* Delete all records
* Reverse the linked list
* Save and exit or exit without saving

## Student Details

Each student record contains:

* Roll Number
* Student Name
* Percentage

Roll numbers are assigned automatically and are unique.

Percentage must be between 0.00 and 100.00.

## Project Structure


Studentdatabase1/
├── studentmain.c
├── student.h
├── stud_add1.c
├── stud_del1.c
├── stud_delall1.c
├── stud_mod1.c
├── stud_save1.c
├── stud_show1.c
├── stud_sort1.c
├── stud_revlist1.c
├── Makefile
└── README.md


## Compilation

Using the Makefile:


make


Or compile manually:


gcc studentmain.c stud_add1.c stud_del1.c stud_delall1.c stud_mod1.c stud_save1.c stud_show1.c stud_sort1.c stud_revlist1.c -o student


## Run
./student


## Data File

Student records are stored in:

student.dat


The records are loaded automatically when the program starts and can be saved using the **Save** option.

## Concepts Used

* Structures
* Pointers
* Dynamic memory allocation
* Singly linked lists
* File handling
* Functions
* String handling
* Searching
* Sorting
* Linked-list reversal
* Menu-driven programming

