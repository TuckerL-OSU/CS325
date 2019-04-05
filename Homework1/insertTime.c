// Tucker Lavell
// CS325 Sp 2019
// Homework 1 - insertsort.c
// insert sort taken from https://www.geeksforgeeks.org/insertion-sort/
// also recieved help from friend Dan Drapp

// C program for insertion sort 
#include <stdlib.h>
#include <stdio.h> 
#include <math.h> 
#include <time.h>

/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;

		/* Move elements of arr[0..i-1], that are
		greater than key, to one position ahead
		of their current position */
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

/* Driver program to test above functions */
int main() {
	// number of values to test
	int testOne = 5000;
	int testTwo = 10000;
	int testThree = 15000;
	int testFour = 20000;
	int testFive = 25000;
	int testSix = 30000;
	int testSeven = 35000;
	int testEight = 40000;
	int testNine = 45000;
	int testTen = 50000;

	int *arrOne = malloc(testOne * sizeof(int));
	int *arrTwo = malloc(testTwo * sizeof(int));
	int *arrThree = malloc(testThree * sizeof(int));
	int *arrFour = malloc(testFour * sizeof(int));
	int *arrFive = malloc(testFive * sizeof(int));
	int *arrSix = malloc(testSix * sizeof(int));
	int *arrSeven = malloc(testSeven * sizeof(int));
	int *arrEight = malloc(testEight * sizeof(int));
	int *arrNine = malloc(testNine * sizeof(int));
	int *arrTen = malloc(testTen * sizeof(int));

	clock_t start, end;
	double time = 0;

	/*********************************************************/
	// One
	/*********************************************************/
	for (int i = 0; i < testOne; i++) {
		arrOne[i] = RNG();
	}

	start = clock();
	insertionSort(arrOne, testOne);
	end = clock();

	time = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Test One\n");
	printf("Array Size: %d\n", testOne);
	printf("Total time: %f\n\n", time);

	/*********************************************************/
	// Two
	/*********************************************************/
	for (int i = 0; i < testTwo; i++) {
		arrTwo[i] = RNG();
	}

	start = clock();
	insertionSort(arrTwo, testTwo);
	end = clock();

	time = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Test Two\n");
	printf("Array Size: %d\n", testTwo);
	printf("Total time: %f\n\n", time);

	/*********************************************************/
	// Three
	/*********************************************************/
	for (int i = 0; i < testThree; i++) {
		arrThree[i] = RNG();
	}

	start = clock();
	insertionSort(arrThree,testThree);

	end = clock();

	time = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Test Three\n");
	printf("Array Size: %d\n", testThree);
	printf("Total time: %f\n\n", time);

	/*********************************************************/
	// Four
	/*********************************************************/
	for (int i = 0; i < testFour; i++) {
		arrFour[i] = RNG();
	}

	start = clock();
	insertionSort(arrFour, testFour);
	end = clock();

	time = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Test Four\n");
	printf("Array Size: %d\n", testFour);
	printf("Total time: %f\n\n", time);

	/*********************************************************/
	// Five
	/*********************************************************/
	for (int i = 0; i < testFive; i++) {
		arrFive[i] = RNG();
	}

	start = clock();
	insertionSort(arrFive, testFive);
	end = clock();

	time = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Test Five\n");
	printf("Array Size: %d\n", testFive);
	printf("Total time: %f\n\n", time);

	/*********************************************************/
	// Six
	/*********************************************************/
	for (int i = 0; i < testSix; i++) {
		arrSix[i] = RNG();
	}

	start = clock();
	insertionSort(arrSix, testSix);
	end = clock();

	time = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Test Six\n");
	printf("Array Size: %d\n", testSix);
	printf("Total time: %f\n\n", time);

	/*********************************************************/
	// Seven
	/*********************************************************/
	for (int i = 0; i < testSeven; i++) {
		arrSeven[i] = RNG();
	}

	start = clock();
	insertionSort(arrSeven, testSeven);
	end = clock();

	time = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Test Seven\n");
	printf("Array Size: %d\n", testSeven);
	printf("Total time: %f\n\n", time);

	/*********************************************************/
	// Eight
	/*********************************************************/
	for (int i = 0; i < testEight; i++) {
		arrEight[i] = RNG();
	}

	start = clock();
	insertionSort(arrEight, testEight);
	end = clock();

	time = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Test Eight\n");
	printf("Array Size: %d\n", testEight);
	printf("Total time: %f\n\n", time);

	/*********************************************************/
	// Nine
	/*********************************************************/
	for (int i = 0; i < testNine; i++) {
		arrNine[i] = RNG();
	}

	start = clock();
	insertionSort(arrNine, testNine);
	end = clock();

	time = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Test Nine\n");
	printf("Array Size: %d\n", testNine);
	printf("Total time: %f\n\n", time);

	/*********************************************************/
	// Ten
	/*********************************************************/
	for (int i = 0; i < testTen; i++) {
		arrTen[i] = RNG();
	}

	start = clock();
	insertionSort(arrTen, testTen);
	end = clock();

	time = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Test Ten\n");
	printf("Array Size: %d\n", testTen);
	printf("Total time: %f\n\n", time);
	/*********************************************************/

	free(arrOne);
	free(arrTwo);
	free(arrThree);
	free(arrFour);
	free(arrFive);
	free(arrSix);
	free(arrSeven);
	free(arrEight);
	free(arrNine);
	free(arrTen);

	return 0;
}