// Tucker Lavell
// CS325 Sp 2019
// Homework 1 - mergetime.c
// merge sort taken from https://www.geeksforgeeks.org/merge-sort/
// time calc from https://www.geeksforgeeks.org/how-to-measure-time-taken-by-a-program-in-c/
// also recieved help from friend Dan Drapp

/* C program for Merge Sort */
#include <stdlib.h> 
#include <stdio.h> 
#include <time.h>

// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	/* create temp arrays */
	int L[n1], R[n2];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray 
	j = 0; // Initial index of second subarray 
	k = l; // Initial index of merged subarray 
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there
	are any */
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	are any */
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
	if (l < r)
	{
		// Same as (l+r)/2, but avoids overflow for 
		// large l and h 
		int m = l + (r - l) / 2;

		// Sort first and second halves 
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

int RNG() {
	return rand() % 10000 + 1;
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
	mergeSort(arrOne, 0, testOne - 1);
	end = clock();

	time = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Array Size: %d\n", testOne);
	printf("Total time: %f\n\n", time);

	/*********************************************************/
	// Two
	/*********************************************************/
	for (int i = 0; i < testTwo; i++) {
		arrTwo[i] = RNG();
	}

	start = clock();
	mergeSort(arrTwo, 0, testTwo - 1);
	end = clock();

	time = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Array Size: %d\n", testTwo);
	printf("Total time: %f\n\n", time);

	/*********************************************************/
	// Three
	/*********************************************************/
	for (int i = 0; i < testThree; i++) {
		arrThree[i] = RNG();
	}

	start = clock();
	mergeSort(arrThree, 0, testThree - 1);

	end = clock();

	time = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Array Size: %d\n", testThree);
	printf("Total time: %f\n\n", time);

	/*********************************************************/
	// Four
	/*********************************************************/
	for (int i = 0; i < testFour; i++) {
		arrFour[i] = RNG();
	}

	start = clock();
	mergeSort(arrFour, 0, testFour - 1);
	end = clock();

	time = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Array Size: %d\n", testFour);
	printf("Total time: %f\n\n", time);

	/*********************************************************/
	// Five
	/*********************************************************/
	for (int i = 0; i < testFive; i++) {
		arrFive[i] = RNG();
	}

	start = clock();
	mergeSort(arrFive, 0, testFive - 1);
	end = clock();

	time = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Array Size: %d\n", testFive);
	printf("Total time: %f\n\n", time);

	/*********************************************************/
	// Six
	/*********************************************************/
	for (int i = 0; i < testSix; i++) {
		arrSix[i] = RNG();
	}

	start = clock();
	mergeSort(arrSix, 0, testSix - 1);
	end = clock();

	time = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Array Size: %d\n", testSix);
	printf("Total time: %f\n\n", time);

	/*********************************************************/
	// Seven
	/*********************************************************/
	for (int i = 0; i < testSeven; i++) {
		arrSeven[i] = RNG();
	}

	start = clock();
	mergeSort(arrSeven, 0, testSeven - 1);
	end = clock();

	time = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Array Size: %d\n", testSeven);
	printf("Total time: %f\n\n", time);

	/*********************************************************/
	// Eight
	/*********************************************************/
	for (int i = 0; i < testEight; i++) {
		arrEight[i] = RNG();
	}

	start = clock();
	mergeSort(arrEight, 0, testEight - 1);
	end = clock();

	time = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Array Size: %d\n", testEight);
	printf("Total time: %f\n\n", time);

	/*********************************************************/
	// Nine
	/*********************************************************/
	for (int i = 0; i < testNine; i++) {
		arrNine[i] = RNG();
	}

	start = clock();
	mergeSort(arrNine, 0, testNine - 1);
	end = clock();

	time = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Array Size: %d\n", testNine);
	printf("Total time: %f\n\n", time);

	/*********************************************************/
	// Ten
	/*********************************************************/
	for (int i = 0; i < testTen; i++) {
		arrTen[i] = RNG();
	}

	start = clock();
	mergeSort(arrTen, 0, testTen - 1);
	end = clock();

	time = (double)(end - start) / CLOCKS_PER_SEC;
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