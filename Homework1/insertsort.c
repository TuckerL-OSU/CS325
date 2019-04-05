// Tucker Lavell
// CS325 Sp 2019
// Homework 1 - insertsort.c
// insert sort taken from https://www.geeksforgeeks.org/insertion-sort/
// also recieved help from friend Dan Drapp

// C program for insertion sort 
#include <stdlib.h>
#include <stdio.h> 
#include <math.h> 

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

// A utility function to print an array of size n 
void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

/* Driver program to test above functions */
int main() {
	int i = 0;
	int j = 0;
	char c = ' ';
	int numOfLines = 0;
	FILE *inputFile;
	int *inputArr;
	int index = 0;

	// open file to get num of lines
	inputFile = fopen("data.txt", "r");

	if (inputFile == NULL) {
		return 0;
	}

	// open output file to get ready to write to
	FILE *outputFile = fopen("insert.txt", "w");
	if (outputFile == NULL)
	{
		printf("Error opening file!\n");
		exit(1);
	}

	while (!feof(inputFile)) {
		c = fgetc(inputFile);
		if (c == '\n' || c == EOF) {
			numOfLines++;
		}
	}
	fclose(inputFile);

	fopen("data.txt", "r");
	for (j = 0; j < numOfLines; j++) {
		int sizeOfInput;
		if (!fscanf(inputFile, "%d", &sizeOfInput)) {
			break;
		}
		int length = sizeOfInput;
		inputArr = malloc(length * sizeof(int));

		for (i = 0; i < length; i++) {
			int nextNum;
			fscanf(inputFile, "%d", &nextNum);
			inputArr[index] = nextNum;
			index++;
		}

		insertionSort(inputArr, length);

		for (i = 0; i < length; i++) {
			int printNumber = inputArr[i];
			if (i == length - 1) {
				fprintf(outputFile, "%d", printNumber);
				if (j < numOfLines - 1) {
					fprintf(outputFile, "\n");
				}
			}
			else {
				fprintf(outputFile, "%d ", printNumber);
			}
		}
		index = 0;
		free(inputArr);
	}

	fclose(outputFile);
	fclose(inputFile);
	return 0;
}
