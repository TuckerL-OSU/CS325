// Tucker Lavell
// CS325 Sp 2019
// Homework 1 - mergesort.c
// merge sort taken from https://www.geeksforgeeks.org/merge-sort/
// also recieved help from friend Dan Drapp

/* C program for Merge Sort */
#include<stdlib.h> 
#include<stdio.h> 

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

// getNumLines and getLongestLine could be made more efficient with one open,
// then using fseek or rewind to get back to beginning of file
//int getNumLinesInFile() {
//	FILE *fp;
//	int numLines = 0;
//	char c = ' ';
//
//	fp = fopen("data.txt", "r");
//
//	// eof contradiction
//	while (1) {
//		c = getc(fp);
//		if (c == '\n') {
//			numLines++;
//		}
//		else if (c == EOF) {
//			numLines++;
//			break;
//		}
//	}
//
//	printf("numLines = %d\n", numLines);
//	printf("Closing data.txt in numLines.\n");
//	fclose(fp);
//
//	return numLines;
//}
//
//int getLongestLineInFile() {
//	FILE *fp;
//	int lenOfLongest = 0;
//	size_t len = 0;
//	char *line = NULL;
//	size_t lineBuffer = 0;
//
//	fp = fopen("data.txt", "r");
//
//	while (!EOF) {
//		len = getline(&line, &lineBuffer, fp);
//
//		if (len > lenOfLongest) {
//			lenOfLongest = len;
//		}
//	}
//
//	fclose(fp);
//
//	return lenOfLongest;
//}
//
//int** readFile() {
//	FILE *fp; 
//	int numCols = 0;
//	int numRows = 0;
//	char *line = NULL;
//	int *inputArr = NULL;
//
//	numRows = getNumLinesInFile();
//	int i;
//	for (i = 0; i < numRows; i++) {
//		int sizeOfLine = 0;
//		if (!fscanf(fp, "%d", &sizeOfLine)) {
//			break;
//		}
//		inputArr = malloc(sizeOfLine * sizeof(int));
//
//		int j;
//		for (j = 0; j < sizeOfLine; j++) {
//			int value = 0;
//			fscanf(fp, "%d", &value);
//			inputArr[i] = value;
//		}
//	}
//
//	numCols = getLongestLineInFile();
//	int inputArr[numRows][numCols];
//
//	fp = fopen("data.txt", "r");
//	
//	int i;
//	int j;
//	for (i = 0; i < numRows; i++) {
//		for (j = 0; j < numCols; j++) {
//			fscanf(fp, "%d", &inputArr[i][j]);
//		}
//	}
//
//	fclose(fp);
//
//	return inputArr;
//}

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
	FILE *outputFile = fopen("merge.txt", "w");
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

		mergeSort(inputArr, 0, length - 1);

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
