/**
* @file menuFunctions.c
* @brief Implements the menu-driven functions that demonstrate array operations.
*
* This file defines three menu functions (MF1, MF2, MF3) that demonstrate the
* functionality of the Working Functions (WF) module. Each menu function
* demonstrates a different combination of array operations e.g filling
* arrays with random or user-input values and sorting, clearing, and calculating
* statistical properties.
* 
* @author Niamh O'Dowd
* @date 06.11.2025
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "workingFunctions.h"


//defining all functions
void menuFunction1(); //MF1
void menuFunction2(); //MF2
void menuFunction3(); //MF3

/**
*@brief This function creates an array and manipulates it using WF functions
*
* This function demonstrates the use of many of the WF functions:
* -prints 2 blank lines
* -creates an array
* - uses fillArrayRandom() to fill it with random numbers
* -Uses printUsed() and printAll() to print the used elements and all of the array
* - clears the array using clearArray()
* -Uses printUsed() and printAll() to print the used elements and all of the array again
* - uses fillArrayRandom() to fill it with random numbers again
* - Uses sortArray() to sort the array in ascending order
* - Uses printAll() to print all the elements of the array
* - Then prints out the minimum and maximum values of the array using minimumVal() and maximumVal()
*  -prints 2 blank lines
* -demonstrates the use of a preprocessor with 2 parameters
* 
* @return void
*/

void menuFunction1()
{
	printf("\n"); //prints out 2 blank lines
	printf("\n");
	
	int array1[10]; // creates an array with 10 elements
	
	size_t size1 = 7;
	size_t size2 = 5;
	size_t capacity = 10;
	fillArrayRandom(array1, size1, capacity, 20, 10); //fills array with 7 random values from 10 to 20 
	
	printUsed(array1, 10); //prints out the used elements of the array
	printAll(array1, 10); // prints all the elements of the array
	
	clearArray(array1, 10); //clears array
	
	printUsed(array1, 10);//prints out the used elements of the array
	printAll(array1, 10); //prints all elements of the array
	
	fillArrayRandom(array1, size2, capacity, 30, 20); //fills array with 5 random values from 20 to 30
	
	sortArray(array1, 10); //sorts array
	printAll(array1, 10);//prints all elements of the array
	printf("The minimum value in this array is %d\n", (minimumVal(array1, 10))); //prints minimum value
	printf("The maximum value in this array is %d\n", (maximumVal(array1, 10)));//prints maximum value

	int a = 5, b = 8;
	printf("The larger number between %d and %d is %d\n", a, b, MAX(a, b)); //demonstrates pre-processor macro with two parameters

	
	printf("\n");//prints 2 blank lines
	printf("\n");
}

/**
*@brief This function creates an array and manipulates it using WF functions
*
* This function demonstrates the use of many of the WF functions:
* -prints 2 blank lines
* -creates an array
* - uses fillArrayRandom() to fill it with random numbers
* -Uses printUsed() and printAll() to print the used elements and all of the array
* - Uses randomizeArray() to rendomize the array
* - Uses printAll to print the array 
*-prints 2 blank lines
*
* @return void
*/

void menuFunction2()
{
	printf("\n"); //prin 2 blank lines
	printf("\n");

	int array2[20]; //creates an array of size 20
	
	fillArrayRandom(array2, 15, 20, 10, 20); ///fills the array with 15 random values from 10 to 20
	sortArray(array2, 20); //sorts the array
	printAll(array2, 20);//prints all elements of the array
	
	randomizeArray(array2, 20); //randomizes the array
	printAll(array2, 20);//prints all elements of the array
	
	printf("\n"); //prints 2 blank lines
	printf("\n");
}

/**
*@brief This function creates an array and manipulates it using WF functions
*
* This function demonstrates the use of many of the WF functions:
* -prints 2 blank lines
* -Uses fillArray() to fill the array using inputs from the user
* - prints out the minimum and maximum value of the array using minimumVal() and maximumVal()
* -prints out the average and median value of the array using averageValue() and medianVal()
* -prints out the amount of used elements, the variance and the standard deviation of the array using usedElements(), variance() and standardDeviation()
* -prints 2 blank lines
*
* @return void
*/

void menuFunction3()
{
	printf("\n"); //prints 2 blank lines
	printf("\n");

	int array3[ARRAY_CAPACITY]; //creates an array with 100 elements
	fillArray(array3, 100); //prompts the user to fill the array

	printf("The minimum value in this array is %d\n", (minimumVal(array3, 100))); //prints out the minimum value of the array
	printf("The maximum value in this array is %d\n", (maximumVal(array3, 100))); //prints out the maximum value of the array
	
	double x = averageValue(array3, 100); //finds the average value of the array
	double y = medianVal(array3, 100);//finds the median value pf the array

	printf("The array has an average value of %lf and a median value of %lf\n", x, y);//prints out average and median values
	
	int a = usedElements(array3, 100); //finds the amount of used elements in the array
	double b = variance(array3, 100);//finds the variance of the array
	double c = standardDeviation(array3, 100); //finds the standard deviation of the array
	
	//ptints out the amount of used elements, the variance and the standard deviation of the array
	printf("Array with %d used elements, has a variance %lf and a standard deviation %lf\n", a, b, c); 
	
	printf("\n");//prints 2 blank lines
	printf("\n");
}
