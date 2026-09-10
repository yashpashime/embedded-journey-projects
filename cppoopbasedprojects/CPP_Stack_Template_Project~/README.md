# C++ Mini Project - Stack Application Using Templates

## Project Name

Stack Application Using Templates

## Objective

This project is a menu driven Stack application written in C++.

A class template is used so that the same Stack class can work with different data types.

The program supports:

* Integer Stack
* Character Stack
* Float Stack
* Double Stack
* String Stack

## Main Menu

The program displays the following menu:

1. Integer Stack
2. Character Stack
3. Float Stack
4. Double Stack
5. String Stack
6. Exit

The program continues until the user selects Exit or the invalid choice limit is reached.

## Stack Implementation

The stack is implemented using a class template.


#define MAX_SIZE 5

template<class Type>
class Stack


The maximum size of every stack is 5 elements.

The class contains:

* `stack` - array used to store elements
* `TOP` - stores the current top position

When a new stack is created, `TOP` is initialized to `-1`, which means the stack is empty.

## Stack Operations

### Push

Push is used to insert a new element into the stack.

If the stack already contains 5 elements, the program displays:


Stack Overflow.


Otherwise, the element is inserted and `TOP` is updated.

### Pop

Pop removes the top element from the stack.

If there are no elements in the stack, the program displays:


Stack Underflow.


Otherwise, `TOP` is decreased.

### Display

Display shows all the elements currently present in the stack.

The elements are displayed from `TOP` to the bottom of the stack.

If the stack is empty, the program displays:


Stack is Empty.


## Data Types

The same Stack template is used for all these data types:

```text
int
char
float
double
string
```

No separate Stack class is created for each data type.

## Re-selecting a Data Type

If a data type is selected again after it has already been used, the program gives two choices:

1. Continue with old stack
2. Create new stack

If the user selects the first option, the old elements are retained.

If the user selects the second option, the previous stack contents are removed and a new empty stack is created.

## Invalid Input

The program allows a maximum of 3 consecutive invalid menu choices.

For every invalid choice, an error message is displayed and the user is asked again.

When a valid choice is entered, the invalid choice count is reset.

After 3 consecutive invalid choices, the program terminates.

The program also handles non-numeric input entered where a menu number is expected.

## Program Flow


START
   |
   v
MAIN MENU
   |
   v
Select Data Type
   |
   v
STACK SUBMENU
   |
   +---- Push
   |
   +---- Pop
   |
   +---- Display
   |
   +---- Main Menu
   |
   v
MAIN MENU
   |
   +---- Exit
   |
   v
END
```

## Concepts Used

* C++ Classes
* Class Templates
* Constructors
* Arrays
* Functions
* Objects
* Stack Data Structure
* LIFO (Last In First Out)
* Conditional Statements
* Switch Case
* Loops
* Input and Output

## Stack Principle

The stack follows the **LIFO** principle.

LIFO means:

**Last In First Out**

For example, if we push:


10
20
30


the stack will contain:


30  <- TOP
20
10


When Pop is performed, `30` is removed first.

## Testing

The program should be tested for all five data types.

The following operations should be checked:

* Push
* Pop
* Display
* Stack Overflow
* Stack Underflow
* Returning to Main Menu
* Creating a new stack
* Continuing with an old stack
* Invalid menu choices

## Files


main.cpp
README.md


## Conclusion

This project demonstrates how a C++ class template can be used to implement one Stack class that supports multiple data types. It also demonstrates basic stack operations such as Push, Pop and Display with proper handling of Overflow and Underflow conditions.

