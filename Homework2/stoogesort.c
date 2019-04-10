// Tucker Lavell
// CS325 Sp 2019
// Homework 1 - stoogesort.c
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
	FILE *outputFile = fopen("stooge.out", "w");
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

		stoogeSort(inputArr, 0, length - 1);

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
