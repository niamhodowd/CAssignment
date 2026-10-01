/**
* @file Source.c
* 
* @brief Implements array manipulation and statistical functions
*
* This file contains implementations of various array-processing functions used by the
* program's menu system. These include functions to:
* - Fill arrays manually or randomly with integers
* - Clear or randomize arrays
* - Sort arrays in ascending order
* - Print used and unused array elements
* - Calculate statistical values such as minimum, maximum, average, median,
*   variance, and standard deviation
* 
* @author Niamh O'Dowd (24414646)
* @date 2025.11.06
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h> //for when using rand()
#include <math.h>//for sqrt in standardDeviation function
#include "menuFunctions.h"

//declare all functions
int getRandomNumber(int min, int max); //WF1
void fillArray(int array[], size_t size); //WF2
void fillArrayRandom(int array[], size_t size, size_t capacity, int max, int min); //WF3
void clearArray(int array[], size_t capacity); //WF4
void sortArray(int array[], int capacity); //WF5
void randomizeArray(int array[], int capacity); //WF6
void printUsed(int array[], int capacity); //WF7
void printAll(int array[], int capacity); //WF8
int minimumVal(int array[], int capacity); //WF9
int maximumVal(int array[], int capacity); //WF10
double averageValue(int array[], int capacity); //WF11
int medianVal(int array[], int capacity); //WF12
double variance(int array[], int capacity); //WF13
double standardDeviation(int array[], int capacity); //WF14
int usedElements(int array[], int capacity); //WF15



/**
* @brief This function gets random number between minimum and maximum values
* 
* This function generates a random number between given minimum and maximum values:
* - Finds the difference between the minimum and maximum value and adds one 
* - Computes rand() modulus the difference between minimum and maximum to get the range of random numbers
* - Adds the minimum to this number so the range of random numbers is now from minimum to maximum
* 
* @param min Minimum value the random number can be
* @param max Maximum calue the random number can be
* 
* @return A random number
*/

int getRandomNumber(int min, int max)
{
	int difference = (max - min) + 1; // gettinf the difference between the min and max values to determine the range 
	int number = ((rand() % difference) + min); //generating random number
	return number;
}

/**
*@brief This function fills the array with values entered from the keyboard
* 
* Fills a given array with numbers entered by the user:
* - Asks the user to enter a positive integer
* - Reads this value and enters it into the array
* - Repeats these steps until the array is full or until the user enters a negative number
* 
* If the user enters a negative number the loop will end and the remainder of the array will be filled with -1
* 
* @param array Array to be filled with values from the keyboard
* @param size Size of the array
* 
* @return void
*/

void fillArray(int array[], size_t size) 
{
	int fillValue; 
	for (int i = 0; i < size; i++) {// for loop fills array until it is full 
		printf("Please enter a positive integer: "); // asking the user to input a positive integer
		scanf_s("%d", &fillValue); // storing that integer in "fillValue"

		if (fillValue < 0) {//if a negative number is entered fills the rest of the array with -1
			for (int j = i; j < size; j++) {
				array[j] = -1; 
			}
			break; 
		}

		array[i] = fillValue; //storing fillValue in position i of the array
	}

}

/**
* @brief This function fills array with 'size' random numbers and sets the rest of the array to 'unused' (-1)
* 
* Fills the given array with a given amount of random numbers and fills the rest of the array with -1:
* - Fills the array with random numbers by calling getRandomNumber()
* - Repeats the 'size' times
* - Fill the rest of the array with -1
* 
* @param randomArray Array to be filled with random values, with the rest of the values set to -1
* @param size Amount of values in the array to be set to random values
* @param capacity The amount of values in the entire array
* @param max The maximum value a random number can be (inclusive)
* @param min The minimum value a random number can be (inclusive)
* 
* @return void
* 
* @see getRandomNumber() for generating a random number between two values
*/

void fillArrayRandom(int array[], size_t size, size_t capacity, int max, int min)
{
	for (int i = 0; i < size; i++) { // fills array with 'size' random numbers 
		array[i] = (getRandomNumber(min, max));
	}
	for (int j = size; j < capacity; j++) { //fills remainder of the array with -1
		array[j] = -1;
	}
}
/**
* @brief This function clears the array by setting all values to 'unused' (-1)
* 
* Goes through every element in the array and sets the value to -1
* Repeats this until all of array is set to -1
* 
* @param array The array that is going to be cleared
* @param capacity The size of the array
* 
* @return void
*/
void clearArray(int array[], size_t capacity)
{
	for (int i = 0; i < capacity; i++) { //setting all values in array1 to -1
		array[i] = -1;
	}
}

/**
* @brief This function sorts the array in ascending order 
* 
* Using bubble sort, the function sorts the array in ascending order with 'unused' values (-1) at the end of the array:
* -Counts the amount of used elements
* - Puts the used elements at the beginning of the array
* - Sets the rest of the values after the used elements to -1
* - Sorts the array in ascending order using a bubble sort
* 
* @param array Array of numbers in random order ( asuming that unused values could be mixed with used values)
* @param capacity Capacity of the array
* 
* @return void
*/

void sortArray(int array[], int capacity)
{
	//variables used for for loops and bubble sort
	int i;
	int j;
	int temp;

	int used = 0; // counter for how many values in the array are used
		for (i = 0; i < capacity; i++) { 
			//if a value is a 'used' value it will store it at the beginning of the array
			if (array[i] != -1) {
				array[used++] = array[i]; // stored value at the beginning and adds to used counter every time
			}
		}
		for (i = used; i < capacity; i++) {
			//sets all values after the used values to 'unused' (-1)
			array[i] = -1;
		}

		//bubble sort to sort 'used' values
		for (i = 0; i < (used - 1); i++) { // sets the amount of times the next for loop will go through array
			for (j = 0; j < (used - i - 1); j++) {
				//compares each element with the next and swaps them to be in ascending order if needed
				if (array[j] > array[j + 1]) {
					temp = array[j];
					array[j] = array[j + 1];
					array[j + 1] = temp;
				}
			}
		}

}

/**
* @brief This function takes an array and randomises the order of the used elemnts in the array and puts all the unused (-1) values to the back of the array
* 
* The function randomizes the array :
* - counts the amount of used elements
* - puts these elements to the beginning of the array
* - sets the rest of the 'unused' elements to -1
* - seeds the random number generator with the time 
* - swaps the elements of the array with another random element of the array
* - does this until all used elements have been swaped
*  
* @param array Array with used and unused values
* @param capacity Capacity of the array
* 
* @return void
*/

void randomizeArray(int array[], int capacity)
{
	//variables used for for loops and randomizing
	int i;
	int j;
	int temp;
	srand(time(NULL)); //seeds the random number generator with the current time

	int used = 0; // counter for how many values in the array are used
	for (i = 0; i < capacity; i++) {
		//if a value is a 'used' value it will store it at the beginning of the array
		if (array[i] != -1) {
			array[used++] = array[i]; // stored value at the beginning and adds to used counter every time
		}
	}
	for (i = used; i < capacity; i++) {
		//sets all values after the used values to 'unused' (-1)
		array[i] = -1;
	}

	for (i = (used - 1); i > 0; i--) { //loops once for every used value in the array
		//sets j to a random number between 0 and the number of used elements 
		j = rand() % (i + 1);
		//swaps the value at index i with the number of index j (random index)
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}

}

/**
* @brief This function prints out only used elements of the array and prints out an empty array {} for unsued elements
* 
* This function goes through the array and prints out used elements
* It then prints out a message with the array of unused elements i.e {}
* 
* @param array Array with used and unused values
* @param capacity The capacity of the array
* 
* @return void
*/

void printUsed(int array[], int capacity)
{
	printf("Used elements: {");
	for (int i = 0; i < capacity; i++) {
		if (array[i] >= 0) { //if the value is 'used it prints it out
			printf("%d, ", array[i]);
		}
	}
	printf("}\n");
	printf("Unused elements: {}\n"); //prints out 'empty' array for unused elements
}
/**
* @brief This function prints out all elements of the array 
*
* The function goes through the entire array and prints out each element
* If an element is 'unused' it will print out -1
*
* @param array Array with used and unused values
* @param capacity The capacity of the array
*
* @return void 
*/

void printAll(int array[], int capacity)
{
	printf("All elements: {");
	for (int i = 0; i < capacity; i++) { 
		if (array[i] >= 0) { //if element is used it prints it out
			printf("%d, ", array[i]);
		} else {
			printf("-1, "); // if element is unused it prints out -1
		}
	}
	printf("}\n");
	
}

/**
* @brief This function returns the minimum element of an array
* 
* This function calls sortArray() to sort the array in ascending order
* It then returns the first value of the array as this will be the smallest
* 
* @param array Array of integers
* @param capacity Capacity of the array
* 
* @return the minimum element of the array
* 
* @see sortArray() for sorting the array of integers
*/

int minimumVal(int array[], int capacity)
{


	sortArray(array, capacity); //sorts array
	int min = array[0];//first element in the sorted array will be the smallest
	
	return min;
}

/**
* @brief This function returns the maximum element of an array
*
* This function returns the largest element of the given array:
* - calls sortArray() to sort the array in ascending order 
* - counts the amount of used elements in the array
* - returns the last used element as this is the biggest
* 
* @param array Array of integers
* @param capacity Capacity of the array
*
* @return the maximum element of the array
* 
* @see sortArray() for sorting the array of integers
*/

int maximumVal(int array[], int capacity)
{
	
	sortArray(array, capacity);//sorts the array so array is in ascending order

	int usedCount = 0;
	for (int k = 0; k < capacity; k++) {
		if (array[k] >= 0) {
			usedCount++; //counts how many elements are used - last used element will be the biggest
		}
	}

	int max = array[(usedCount - 1)]; //last used element is the biggest

	return max;
}
/**
* @brief This function adds all used values together and devides by amount of values to get wverage
* 
* This function returns the average value of all the used elements in the array as a double:
* -Adds all used elements together
* - counts how mnay times a used element is added
* - devides the sum of the used elements by the amount of times an element was added to the sum
* 
* @param array Array with integers
* @param capacity Capacity of the array
* 
* @return The average of the used values in the array
*/

double averageValue(int array[], int capacity)
{
	double sum = 0.0; // sum of all values 
	int counter = 0; // counts how many values are being added together
	double average;
	for (int i = 0; i < capacity; i++) { 
		if (array[i] >= 0) { //checks if value is used
			sum = sum + array[i]; //adds value to sum
			counter++; //adds to counter 
		}
	}
	if (counter == 0) return 0.0;

	average = sum / counter;

	return average;
}

/**
* @brief This function finds the median from an array of values
* 
* This function finds the median of a given array:
* -calls sortArray() to sort the elements in ascending order 
* -calls usedElements() to get the amount of used elements in the array, if this is 0 return -1
* 
* If the amount of used values is even:
* - get the two middle values of the used values in the array, add them together and devide by 2
* -return this value
* 
* If the amount of used values is odd:
* -return the midlle value of the used elements in the array
* 
* 
* @param array Array of integers
* @param capacity Capacity of the array
* 
* @return The median of the values in the array
*
* @see sortArray() to sort the array of integers in ascending order
* @see usedElements() to get the amount of used elements in the array
*/
int medianVal(int array[], int capacity)
{
	sortArray(array, capacity);
	int median;
	int medianIndex;

	int used = usedElements(array, capacity);
	if (used == 0) {
		return -1;
	}


	if (used % 2 == 0) { // if amount of used values is even gets the two middle values and gets the average to get the median
		int mid1 = (used / 2) - 1;
		int mid2 = used / 2;

		median = (array[mid1] + array[mid2]) / 2; 
	} else { // if the amount of used values is even it gets the middle value which is the median
		medianIndex = (used / 2);
		median = array[medianIndex];
	}

	return median;

}

/**
* @brief This function finds the variance of each used elemnt in the array 
* 
* The function gets the variance of a given array:
* -Calculates the sum of all the used elements
* - Counts how many used elements there are
* - find the average of the used elements by deviding the sum by the amount of used elements
* For each used element:
* - find the square of the element subtract the average
* - add all of these values together
* Return this sum devided by the amount of used elements
* 
* @param array Array of integers
* @param capacity Capacity of the array
* 
* @return The variance of each element
*/

double variance(int array[], int capacity)
{
	int counter = 0;
	int sum = 0;
	double average = 0;
	double squared;
	double varSum = 0.0;

	for (int i = 0; i < capacity; i++) {
		if (array[i] >= 0) {
			sum = sum + array[i]; //calculates the sum of all the used elements
			counter++; // counts all the amount of used elements
		}
	}
	if (counter == 0) return 0.0;

	average = sum / counter; // finds the average of all the used elemnts


	for (int j = 0; j < capacity; j++) {
		if (array[j] >= 0) {
			squared = (array[j] - average) * (array[j] - average); //finfd the square of the element minus the average
			varSum = varSum + squared;
			
		}
	}
	double variance = (varSum/ counter); // finds the variance
	
	return variance;

}

/**
* @brief This function finds the standard deviation of the array
* 
* This function finds the standard deviation of a given array:
* - calls variance() to find the variance of the given array
* - returns the square root of this value
* 
* @param array Array of integers
* @param capacity Capacity of the array
* 
* @return The standard deviation of the array
* 
* @see variance() for getting the variance of the array
*/

double standardDeviation(int array[], int capacity)
{
	double standardDeviation = sqrt(variance(array, capacity)); //gets the quare root of the variance of the array

	return standardDeviation;
}

/**
* @brief This function counts the used elemnts in an array
* 
* The function goes through the array and adds to a counter every time a value is used
* This value is returned
* 
* @param array An array of integers
* @param capacity Capacity of the array
* 
* @return The number of used values in the array
* 
*/
int usedElements(int array[], int capacity)
{
	int counter = 0;
	for (int i = 0; i < capacity; i++) {
		if (array[i] >= 0) { //goes through array and counts how many values are 'used'
			counter++;
		}
	}
	return counter;
}