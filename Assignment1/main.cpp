/**
* @file main.c
*@brief Implements the main menu-driven program that executes menu functions.
*
* This file contains the main function, which presents a simple
* menu to the user. The program repeatedly displays four options allowing
* the user to execute one of three menu functions (MF1, MF2, MF3) or terminate
* the program. Each menu function demonstrates various array manipulation
* and statistical operations defined in the Working Functions (WF) module.
* 
* 
* @author Niamh O'Dowd (24414646)
* @date 06.11.2025
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "workingFunctions.h"
#include "menuFunctions.h"

/**
*@brief main function runs a menu driven program
*
* Main function prints a menu that gives four options:
* - 1. Perform menu function 1
* - 2. Perform menu function 2
* - 3. Perform menu function 3
* - 4. Terminate program
* 
* The function performs the selected function then continues to display the menu until option 4 is selected
* 
* @return int 0 upon successful termination
*/

int main(void)
{
    int choice = 0;

    do {
        //prints out menu options
        printf("\n1. Perform MF1.\n");
        printf("2. Perform MF2.\n");
        printf("3. Perform MF3.\n");
        printf("4. Terminate the program.\n");
        printf("Enter your choice: ");
        scanf_s("%d", &choice); //reads users choice

        switch (choice) {
        case 1: //performs menuFunction1
            menuFunction1();
            break;
        case 2: //performs menuFunction2
            menuFunction2();
            break;
        case 3: //performs menuFunction3
            menuFunction3();
            break;
        case 4: //breaks the switch loop and terminates the program
            printf("Program terminated.\n");
            break;
        default: //if anything else is entered it asks user to try again
            printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
