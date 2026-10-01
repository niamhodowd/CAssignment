#ifndef WORKINGFUNCTIONS_H
#define WORKINGFUNCTIONS_H 

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

/**
 * @brief Defines a constant for the array capacity used across the program.
 * You can change this in one place if needed.
 */
#define ARRAY_CAPACITY 100

 /**
  * @brief Returns the maximum of two numbers (macro function).
  */
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int getRandomNumber(int min, int max);
void fillArray(int array[], size_t size);
void fillArrayRandom(int array[], size_t size, size_t capacity, int max, int min);
void clearArray(int array[], size_t capacity);
void sortArray(int array[], int capacity);
void randomizeArray(int array[], int capacity);
void printUsed(int array[], int capacity);
void printAll(int array[], int capacity);
int minimumVal(int array[], int capacity);
int maximumVal(int array[], int capacity);
double averageValue(int array[], int capacity);
int medianVal(int array[], int capacity);
double variance(int array[], int capacity);
double standardDeviation(int array[], int capacity);
int usedElements(int array[], int capacity);

#endif
