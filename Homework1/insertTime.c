//// Tucker Lavell
//// CS325 Sp 2019
//// Homework 1 - insertTime.c
//// insert sort taken from https://www.geeksforgeeks.org/insertion-sort/
//// time calc from https://www.geeksforgeeks.org/how-to-measure-time-taken-by-a-program-in-c/
//// also recieved help from friend Dan Drapp
//
//// C program for insertion sort 
//#include <stdlib.h>
//#include <stdio.h> 
//#include <math.h> 
//#include <time.h>
//
///* Function to sort an array using insertion sort*/
//void insertionSort(int arr[], int n)
//{
//	int i, key, j;
//	for (i = 1; i < n; i++) {
//		key = arr[i];
//		j = i - 1;
//
//		/* Move elements of arr[0..i-1], that are
//		greater than key, to one position ahead
//		of their current position */
//		while (j >= 0 && arr[j] > key) {
//			arr[j + 1] = arr[j];
//			j = j - 1;
//		}
//		arr[j + 1] = key;
//	}
//}
//
//int RNG() {
//	return rand() % 10000 + 1;
//}
//
///* Driver program to test above functions */
//int main() {
//	// number of values to test
//	int testOne = 5000;
//	int testTwo = 10000;
//	int testThree = 15000;
//	int testFour = 20000;
//	int testFive = 25000;
//	int testSix = 30000;
//	int testSeven = 35000;
//	int testEight = 40000;
//	int testNine = 45000;
//	int testTen = 50000;
//
//	int *arrOne = malloc(testOne * sizeof(int));
//	int *arrTwo = malloc(testTwo * sizeof(int));
//	int *arrThree = malloc(testThree * sizeof(int));
//	int *arrFour = malloc(testFour * sizeof(int));
//	int *arrFive = malloc(testFive * sizeof(int));
//	int *arrSix = malloc(testSix * sizeof(int));
//	int *arrSeven = malloc(testSeven * sizeof(int));
//	int *arrEight = malloc(testEight * sizeof(int));
//	int *arrNine = malloc(testNine * sizeof(int));
//	int *arrTen = malloc(testTen * sizeof(int));
//
//	clock_t start, end;
//	double time = 0;
//
//	/*********************************************************/
//	// One
//	/*********************************************************/
//	for (int i = 0; i < testOne; i++) {
//		arrOne[i] = RNG();
//	}
//
//	start = clock();
//	insertionSort(arrOne, testOne);
//	end = clock();
//
//	time = (double)(end - start) / CLOCKS_PER_SEC;
//	printf("Test One\n");
//	printf("Array Size: %d\n", testOne);
//	printf("Total time: %f\n\n", time);
//
//	/*********************************************************/
//	// Two
//	/*********************************************************/
//	for (int i = 0; i < testTwo; i++) {
//		arrTwo[i] = RNG();
//	}
//
//	start = clock();
//	insertionSort(arrTwo, testTwo);
//	end = clock();
//
//	time = (double)(end - start) / CLOCKS_PER_SEC;
//	printf("Test Two\n");
//	printf("Array Size: %d\n", testTwo);
//	printf("Total time: %f\n\n", time);
//
//	/*********************************************************/
//	// Three
//	/*********************************************************/
//	for (int i = 0; i < testThree; i++) {
//		arrThree[i] = RNG();
//	}
//
//	start = clock();
//	insertionSort(arrThree,testThree);
//
//	end = clock();
//
//	time = (double)(end - start) / CLOCKS_PER_SEC;
//	printf("Test Three\n");
//	printf("Array Size: %d\n", testThree);
//	printf("Total time: %f\n\n", time);
//
//	/*********************************************************/
//	// Four
//	/*********************************************************/
//	for (int i = 0; i < testFour; i++) {
//		arrFour[i] = RNG();
//	}
//
//	start = clock();
//	insertionSort(arrFour, testFour);
//	end = clock();
//
//	time = (double)(end - start) / CLOCKS_PER_SEC;
//	printf("Test Four\n");
//	printf("Array Size: %d\n", testFour);
//	printf("Total time: %f\n\n", time);
//
//	/*********************************************************/
//	// Five
//	/*********************************************************/
//	for (int i = 0; i < testFive; i++) {
//		arrFive[i] = RNG();
//	}
//
//	start = clock();
//	insertionSort(arrFive, testFive);
//	end = clock();
//
//	time = (double)(end - start) / CLOCKS_PER_SEC;
//	printf("Test Five\n");
//	printf("Array Size: %d\n", testFive);
//	printf("Total time: %f\n\n", time);
//
//	/*********************************************************/
//	// Six
//	/*********************************************************/
//	for (int i = 0; i < testSix; i++) {
//		arrSix[i] = RNG();
//	}
//
//	start = clock();
//	insertionSort(arrSix, testSix);
//	end = clock();
//
//	time = (double)(end - start) / CLOCKS_PER_SEC;
//	printf("Test Six\n");
//	printf("Array Size: %d\n", testSix);
//	printf("Total time: %f\n\n", time);
//
//	/*********************************************************/
//	// Seven
//	/*********************************************************/
//	for (int i = 0; i < testSeven; i++) {
//		arrSeven[i] = RNG();
//	}
//
//	start = clock();
//	insertionSort(arrSeven, testSeven);
//	end = clock();
//
//	time = (double)(end - start) / CLOCKS_PER_SEC;
//	printf("Test Seven\n");
//	printf("Array Size: %d\n", testSeven);
//	printf("Total time: %f\n\n", time);
//
//	/*********************************************************/
//	// Eight
//	/*********************************************************/
//	for (int i = 0; i < testEight; i++) {
//		arrEight[i] = RNG();
//	}
//
//	start = clock();
//	insertionSort(arrEight, testEight);
//	end = clock();
//
//	time = (double)(end - start) / CLOCKS_PER_SEC;
//	printf("Test Eight\n");
//	printf("Array Size: %d\n", testEight);
//	printf("Total time: %f\n\n", time);
//
//	/*********************************************************/
//	// Nine
//	/*********************************************************/
//	for (int i = 0; i < testNine; i++) {
//		arrNine[i] = RNG();
//	}
//
//	start = clock();
//	insertionSort(arrNine, testNine);
//	end = clock();
//
//	time = (double)(end - start) / CLOCKS_PER_SEC;
//	printf("Test Nine\n");
//	printf("Array Size: %d\n", testNine);
//	printf("Total time: %f\n\n", time);
//
//	/*********************************************************/
//	// Ten
//	/*********************************************************/
//	for (int i = 0; i < testTen; i++) {
//		arrTen[i] = RNG();
//	}
//
//	start = clock();
//	insertionSort(arrTen, testTen);
//	end = clock();
//
//	time = (double)(end - start) / CLOCKS_PER_SEC;
//	printf("Test Ten\n");
//	printf("Array Size: %d\n", testTen);
//	printf("Total time: %f\n\n", time);
//	/*********************************************************/
//
//	free(arrOne);
//	free(arrTwo);
//	free(arrThree);
//	free(arrFour);
//	free(arrFive);
//	free(arrSix);
//	free(arrSeven);
//	free(arrEight);
//	free(arrNine);
//	free(arrTen);
//
//	return 0;
//}


#include <stdio.h>
#include <math.h>
#include<stdlib.h>
#include <time.h>



/**********************************
* Insertion sort Algorithm was taken from
* https://www.geeksforgeeks.org/insertion-sort/
* 09/30/18
***********************************/
void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}



int randomNumberGenerator() {
	int number;
	number = rand() % 10000 + 1;
	return number;
}


int main() {

	int arrOne = 5000;
	int arrTwo = 10000;
	int arrThree = 15000;
	int arrFour = 20000;
	int arrFive = 25000;
	int arrSix = 30000;
	int arrSeven = 35000;

	int * arrOnePtr = malloc(arrOne * sizeof(int));
	int * arrTwoPtr = malloc(arrTwo * sizeof(int));
	int * arrThreePtr = malloc(arrThree * sizeof(int));
	int * arrFourPtr = malloc(arrFour * sizeof(int));
	int * arrFivePtr = malloc(arrFive * sizeof(int));
	int * arrSixPtr = malloc(arrSix * sizeof(int));
	int * arrSevenPtr = malloc(arrSeven * sizeof(int));

	clock_t start_t, end_t;
	double total_t = 0;
	//One
	/*********************************************************/
	for (int i = 0; i < arrOne; i++) {
		arrOnePtr[i] = randomNumberGenerator();
	}
	//printf("Given array is \n");
	//printArray(arrOnePtr, arrOne);
	start_t = clock();
	insertionSort(arrOnePtr, arrOne);
	end_t = clock();

	//printf("\nSorted array is \n");
	//printArray(arrOnePtr, arrOne);
	total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
	printf("Array Size: %d\n", arrOne);
	printf("Total time: %f\n\n", total_t);
	/*********************************************************/
	//Two
	/*********************************************************/
	for (int i = 0; i < arrTwo; i++) {
		arrTwoPtr[i] = randomNumberGenerator();
	}
	//printf("Given array is \n");
	//printArray(arrTwoPtr, arrTwo);
	start_t = clock();
	insertionSort(arrTwoPtr, arrTwo);
	end_t = clock();
	//printf("\nSorted array is \n");
	//printArray(arrTwoPtr, arrTwo);
	total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
	printf("Array Size: %d\n", arrTwo);
	printf("Total time: %f\n\n", total_t);
	/*********************************************************/
	//Three
	/*********************************************************/
	for (int i = 0; i < arrThree; i++) {
		arrThreePtr[i] = randomNumberGenerator();
	}
	//printf("Given array is \n");
	//printArray(arrThreePtr, arrThree);
	start_t = clock();
	insertionSort(arrThreePtr, arrThree);
	end_t = clock();
	//printf("\nSorted array is \n");
	//printArray(arrThreePtr, arrThree);
	total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
	printf("Array Size: %d\n", arrThree);
	printf("Total time: %f\n\n", total_t);
	/*********************************************************/
	//Four
	/*********************************************************/
	for (int i = 0; i < arrFour; i++) {
		arrFourPtr[i] = randomNumberGenerator();
	}
	//printf("Given array is \n");
	//printArray(arrFourPtr, arrFour);
	start_t = clock();
	insertionSort(arrFourPtr, arrFour);
	end_t = clock();
	//printf("\nSorted array is \n");
	//printArray(arrFourPtr, arrFour);
	total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
	printf("Array Size: %d\n", arrFour);
	printf("Total time: %f\n\n", total_t);
	/*********************************************************/
	//Five
	/*********************************************************/
	for (int i = 0; i < arrFive; i++) {
		arrFivePtr[i] = randomNumberGenerator();
	}
	//printf("Given array is \n");
	//printArray(arrFivePtr, arrFive);
	start_t = clock();
	insertionSort(arrFivePtr, arrFive);
	end_t = clock();
	//printf("\nSorted array is \n");
	//printArray(arrFivePtr, arrFive);
	total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
	printf("Array Size: %d\n", arrFive);
	printf("Total time: %f\n\n", total_t);
	/*********************************************************/
	//Six
	/*********************************************************/
	for (int i = 0; i < arrSix; i++) {
		arrSixPtr[i] = randomNumberGenerator();
	}
	//printf("Given array is \n");
	//printArray(arrSixPtr, arrSix);
	start_t = clock();
	insertionSort(arrSixPtr, arrSix);
	end_t = clock();
	//printf("\nSorted array is \n");
	//printArray(arrSixPtr, arrSix);
	total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
	printf("Array Size: %d\n", arrSix);
	printf("Total time: %f\n\n", total_t);
	/*********************************************************/
	//Seven
	/*********************************************************/
	for (int i = 0; i < arrSeven; i++) {
		arrSevenPtr[i] = randomNumberGenerator();
	}
	//printf("Given array is \n");
	//printArray(arrSixPtr, arrSix);
	start_t = clock();
	insertionSort(arrSevenPtr, arrSeven);
	end_t = clock();
	//printf("\nSorted array is \n");
	//printArray(arrSixPtr, arrSix);
	total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
	printf("Array Size: %d\n", arrSeven);
	printf("Total time: %f\n\n", total_t);
	/*********************************************************/

	free(arrOnePtr);
	free(arrTwoPtr);
	free(arrThreePtr);
	free(arrFourPtr);
	free(arrFivePtr);
	free(arrSixPtr);
	free(arrSevenPtr);
	return 0;
}
