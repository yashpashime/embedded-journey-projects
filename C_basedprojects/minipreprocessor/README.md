# Mini Preprocessor in C

## About the Project

This is a C programming project that implements a simplified version of selected C preprocessor operations.

The main purpose of this project is to understand how source code can be processed before compilation and to strengthen my understanding of C programming, pointers, arrays, strings, and file handling.

## Features

### 1. Macro Replacement

The program supports single-line `#define` macros.

The macro names and their corresponding values are stored using a 2D character array. The program searches for the defined macros and replaces their occurrences with the corresponding values.

### 2. Predefined Header-File Inclusion

The program supports inclusion of predefined header files.

The predefined header-file information is maintained in `header.h` and is used while processing header-file inclusion.

### 3. Comment Removal

The program identifies and removes comments from the C source code during preprocessing.

## Project Structure

minipreprocessor/
├── abc.c(input file)
├── macroreplace.c
├── headerfileinclusion.c
├── commentremoval.c
├── project1.c
├── header.h
├── Makefile
└── README.md

## Concepts Used

* C Programming
* Pointers
* 2D Character Arrays
* Character Arrays
* String Processing
* File Handling
* Dynamic Memory Allocation
* Modular Programming
* Makefile
* Basic C Preprocessor Concepts

## Compilation

The project includes a Makefile for compilation.

make

This generates the `mypreprocessor` executable.

## Running the Project

./mypreprocessor

The program processes the input C source file according to the preprocessing operations implemented in the project.

## Current Limitations

This is a simplified implementation created for learning purposes.

* Macro replacement currently supports single-line `#define` macros.
* Macros are stored using fixed-size 2D character arrays.
* Header-file inclusion is limited to the predefined header files supported by the project.
* The project implements selected preprocessing operations and is not intended to be a complete replacement for the C preprocessor.

## Learning Outcome

This project helped me understand how C source code can be processed before compilation.

While developing it, I practiced pointers, 2D character arrays, string processing, file handling, dynamic memory allocation, and modular programming.

It also helped me understand the basic concepts behind macro replacement, header-file inclusion, and comment removal.

## Future Improvements

Possible improvements for future versions include:

* Supporting more complex macro definitions
* Improving memory management
* Handling more edge cases
* Adding more preprocessing features
* Improving error handling

## Project Status

**Completed — Initial Version**
