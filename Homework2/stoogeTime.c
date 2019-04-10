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
		double m = ceil(((2 * n + 2) / 3));
		int tempM = m;
		int *ptr = &arr[0];

		stoogeSort(ptr, tempM);
		ptr = &arr[n - tempM];
		stoogeSort(ptr, tempM);
		ptr = &arr[0];
		stoogeSort(ptr, tempM);
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
	stoogeSort(arrOne, 0, testOne - 1);
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
	stoogeSort(arrTwo, 0, testTwo - 1);
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
	stoogeSort(arrThree, 0, testThree - 1);

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
	stoogeSort(arrFour, 0, testFour - 1);
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
	stoogeSort(arrFive, 0, testFive - 1);
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
	stoogeSort(arrSix, 0, testSix - 1);
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
	stoogeSort(arrSeven, 0, testSeven - 1);
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
	stoogeSort(arrEight, 0, testEight - 1);
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
	stoogeSort(arrNine, 0, testNine - 1);
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
	stoogeSort(arrTen, 0, testTen - 1);
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