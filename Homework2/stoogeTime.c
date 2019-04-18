// Tucker Lavell
// CS325 Sp 2019
// Homework 1 - stoogeTime.c
// follows pseudocode given on homework
// recieved help from friend Dan Drapp

#include <stdlib.h> 
#include <stdio.h> 
#include <math.h> 
#include <time.h>

void stoogeSort(int arr[], int n) {
	if (n == 2 && arr[0] > arr[1]) {
		int temp = arr[0];
		arr[0] = arr[1];
		arr[1] = temp;
	}
	else if (n > 2) {
		int m = (int)ceil(((2 * n + 2) / 3));
		int *ptr = &arr[0];

		stoogeSort(ptr, m);
		ptr = &arr[n - m];
		stoogeSort(ptr, m);
		ptr = &arr[0];
		stoogeSort(ptr, m);
	}
}
int RNG() {
	return rand() % 10000 + 1;
}

/* Driver program to test above functions */
int main() {
	// number of values to test
	int testOne = 500;
	int testTwo = 1000;
	int testThree = 1500;
	int testFour = 2000;
	int testFive = 2500;
	int testSix = 3000;
	int testSeven = 3500;
	int testEight = 4000;
	int testNine = 4500;
	int testTen = 5000;

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
	stoogeSort(arrOne, testOne);
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
	stoogeSort(arrTwo, testTwo);
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
	stoogeSort(arrThree, testThree);

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
	stoogeSort(arrFour, testFour);
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
	stoogeSort(arrFive, testFive);
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
	stoogeSort(arrSix, testSix);
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
	stoogeSort(arrSeven, testSeven);
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
	stoogeSort(arrEight, testEight);
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
	stoogeSort(arrNine, testNine);
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
	stoogeSort(arrTen, testTen);
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