/**
* @file Assignment1
* 
* Description...
* 
* pseudocode...
* 
* @author Niamh O'Dowd (24414646)
* @date 06.11.2025
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

//declare all functions
int getRandomNumber(int min, int max); //WF1
void fillArray(int data[], size_t size); //WF2
void fillArrayRandom(int array[], size_t size, size_t capacity, int max, int min);//WF3
void clearArray(int array1[], size_t capacity);//WF4
void sortArray(int array[], int capacity);//WF5
void randomizeArray(int array[], int capacity);//WF6
void printUsed(int array[], int capacity);//WF7
void printAll(int array[], int capacity); //WF8
int minimumVal(int array[], int capacity);//WF9
int maximumVal(int array[], int capacity);//WF10
double averageValue(int array[], int capacity);//WF11
int medianVal(int array[], int capacity);//WF12
double variance(int array[], int capacity);//WF13
double standardDeviation(int array[], int capacity);//WF14
int usedElements(int array[], int capacity);//WF15



/**
* gets random number between minimum and maximum values
* 
* parameter:
* min - minimum value the random number can be
* max - maximum calue the random number can be
* return: a random number
*/

int getRandomNumber(int min, int max)
{
	int difference = (max - min) + 1; // gettinf the difference between the min and max values to determine the range 
	int number = ((rand() % difference) + min); //generating random number
	return number;
}

/**
*fills the array with values entered from the keyboard
* 
* parameter:
* data[] - array to be filled with values from the keyboard
* size - size of the array
* return: array with numbers from keyboard
*/

void fillArray(int data[], size_t size) 
{
	int fillValue; 
	for (int i = 0; i < size; i++) {// for loop fills array until it is full 
		printf("Please enter a positive integer: "); // asking the user to input a positive integer
		scanf_s("%d", &fillValue); // storing that integer in "fillValue"

		if (fillValue < 0) {//if a negative number is entered fills the rest of the array with -1
			for (int j = i; j < size; j++) {
				data[j] = -1; 
			}
			break; 
		}

		data[i] = fillValue; //storing fillValue in position i of the array
	}

}

/**
* fills array with 'size' random numbers and sets the rest of the array to 'unused' (-1)
* 
* parameters:
* randomArray[] - array to be filled with random values, with the rest of the values set to -1
* size - amount of values in the array to be set to random values
* capacity - the amount of values in the entire array
* max - the maximum value a random number can be (inclusive)
* min - the minimum value a random number can be (inclusive)
* return: randomArray[] filled with random values, with the remainder of the values set to 'unused'
*/

void fillArrayRandom(int array[], size_t size, size_t capacity, int max, int min)
{
	for (int i = 0; i < size; i++) { // fills array with 'size' random numbers 
		randomArray[i] = (getRandomNumber(min, max));
	}
	for (int j = size; j < capacity; j++) { //fills remainder of the array with -1
		randomArray[j] = -1;
	}
}
/**
* clears the array by setting all values to 'unused' (-1)
* 
* parameters:
* array1[] -  the array that is going to be cleared
* capacity -  the size of the array
* return: array1[] with all values set to 'unused' (-1)
*/
void clearArray(int array1[], size_t capacity)
{
	for (int i = 0; i < capacity; i++) { //setting all values in array1 to -1
		array1[i] = -1;
	}
}

/**
* sorts the array, using bubble sort, in ascending order with 'unused' values (-1) at the end of the array
* 
* parameter:
* array[] - array of numbers in random order ( asuming that unused values could be mixed with used values)
* capacity - capacity of the array
* 
* return: sorted array with unused (-1) values at the end
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
* takes an array and randomises the order of the used elemnts in the array
* puts all the unused (-1) values to the back of the array
* 
* parameters: 
* array[] - array with used and unused values
* capacity - capacity of the array
* 
* return - the randomised array with all the unsued values at the back of the array
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
* prints out only used elements of the array and prints out an empty array {} for unsued elements
* 
* parameters :
* array[] - array with used and unused values
* capacity - the capacity of the array
* 
* return - prints out the used values of the array and prints out an empty array for unsued values
*/

void printUsed(int array[], int capacity)
{
	printf("Used elements: {");
	for (int i = 0; i < capacity; i++) {
		if (array[i] >= 0) { //if the value is 'used it prints it out
			printf("%d, ", i);
		}
	}
	printf("}\n");
	printf("Unused elements: {}\n"); //prints out 'empty' array for unused elements
}
/**
* prints out all elements of the array 
*
* parameters :
* array[] - array with used and unused values
* capacity - the capacity of the array
*
* return - prints out all values of the array 
*/

void printAll(int array[], int capacity)
{
	printf("All elements: {");
	for (int i = 0; i < capacity; i++) { 
		if (array[i] >= 0) { //if element is used it prints it out
			printf("%d, ", i);
		} else {
			printf("-1, "); // if element is unused it prints out -1
		}
	}
	printf("}\n");
	
}

/**
* returns the minimum element of an array
* 
* parameter:
* array[] - array of integers
* capacity - capacity of the array
* 
* return: the minimum element of the array
*/

int minimumVal(int array[], int capacity)
{
	int min; //variable for minimum value
	for (int i = 0; i < capacity; i++) {
		if (array[i] >= 0) {
			if (array[i] < array[i + 1]) { //comparing values and storing lower value in min
				min = array[i];
			} else if (array[capacity] < array[capacity - 1]) { // if last value in array is lowest, storing this in min
				min = array[capacity];
			}
		}
	}
	return min;
}
/**
* returns the maximum element of an array
*
* parameter:
* array[] - array of integers
* capacity - capacity of the array
*
* return: the maximum element of the array
*/

int maximumVal(int array[], int capacity)
{
	int max;// variable for maximum value

	for (int i = 0; i < capacity; i++) {
		if (array[i] >= 0) {
			if (array[i] > array[i + 1]) { //comparing values and storinf higher value in max
				max = array[i];
			} else if (array[capacity] > array[capacity - 1]) { //if last value is highest storing this in max
				max = array[capacity];
				}
		}
	}
	return max;
}
/**
* adds all used values together and devides by amount of values to get wverage
* 
* parameter:
* array[] - array with integers
* capacity - capacity of the array
* 
* return: the average of the used values in the array
*/

double averageValue(int array[], int capacity)
{
	double sum; // sum of all values 
	double counter; // counts how many values are being added together
	double average;
	for (int i = 0; i < capacity; i++) { 
		if (array[i] >= 0) { //checks if value is used
			sum = sum + array[i]; //adds value to sum
			counter++; //adds to counter 
		}
	}
	average = sum / counter;

	return average;
}

/**
* finds the median from an array of values
* 
* parameter:
* array[] - array of integers
* capacity - capacity of the array
* 
* return - the median of the values in the array
*/
int medianVal(int array[], int capacity)
{
	sortArray(array, capacity);
	int median;
	int medianIndex;

	int used = 0;
	for (int i = 0; i < capacity; i++) { //finding the amount of used values 
		if (array[i] >= 0) {
			used++;
		}
	}


	if (used % 2 == 0) { // if amount of used values is even gets the two middle values and gets the average to get the median
		int medianIndex1 = (used / 2);
		int medianIndex2 = medianIndex1 + 1;

		median = (array[medianIndex1] + array[medianIndex2]) / 2; 
	} else { // if the amount of used values is even it gets the middle value which is the median
		medianIndex = ((used / 2) + 1);
		median = array[medianIndex];
	}

	return median;

}

/**
* find the variance of each used elemnt in the array 
* 
* paramter:
* array[] - array of integers
* capacity - capacity of the array
* 
* return - the variance of each element
*/

double variance(int array[], int capacity)
{
	int counter;
	int sum;
	int average;
	double squared;
	double varSum = 0;

	for (int i = 0; i < capacity; i++) {
		if (array[i] >= 0) {
			sum = sum + array[i]; //calculates the sum of all the used elements
			counter++; // counts all the amount of used elements
		}
	}
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
* finds the standard deviation 
* 
* paramter:
* array[] - array of integers
* capacity - capacity of the array
* 
* return: returns the standard deviation of the array
*/

double standardDeviation(int array[], int capacity)
{
	double standardDeviation = sqrt(variance(array, capacity)); //gets the quare root of the variance of the array

	return standardDeviation;
}

/**
* counts the used elemnts in an array
* 
* parameter:
* array[] - an array of integers
* capacity- capacity of the array
* 
* return - returns number of used values in the array
*/
int usedElements(int array[], int capacity)
{
	int counter;
	for (int i = 0; i < capacity; i++) {
		if (array[i] >= 0) { //goes through array and counts how many values are 'used'
			counter++;
		}
	}
	return counter;
}