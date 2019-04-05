//// Tucker Lavell
//// CS325 Sp 2019
//// Homework 1 - mergesort.c
//// merge sort taken from https://www.geeksforgeeks.org/merge-sort/
//
///* C program for Merge Sort */
//#include<stdlib.h> 
//#include<stdio.h> 
//
//// Merges two subarrays of arr[]. 
//// First subarray is arr[l..m] 
//// Second subarray is arr[m+1..r] 
//void merge(int arr[], int l, int m, int r)
//{
//	int i, j, k;
//	int n1 = m - l + 1;
//	int n2 = r - m;
//
//	/* create temp arrays */
//	int L[n1], R[n2];
//
//	/* Copy data to temp arrays L[] and R[] */
//	for (i = 0; i < n1; i++)
//		L[i] = arr[l + i];
//	for (j = 0; j < n2; j++)
//		R[j] = arr[m + 1 + j];
//
//	/* Merge the temp arrays back into arr[l..r]*/
//	i = 0; // Initial index of first subarray 
//	j = 0; // Initial index of second subarray 
//	k = l; // Initial index of merged subarray 
//	while (i < n1 && j < n2)
//	{
//		if (L[i] <= R[j])
//		{
//			arr[k] = L[i];
//			i++;
//		}
//		else
//		{
//			arr[k] = R[j];
//			j++;
//		}
//		k++;
//	}
//
//	/* Copy the remaining elements of L[], if there
//	are any */
//	while (i < n1)
//	{
//		arr[k] = L[i];
//		i++;
//		k++;
//	}
//
//	/* Copy the remaining elements of R[], if there
//	are any */
//	while (j < n2)
//	{
//		arr[k] = R[j];
//		j++;
//		k++;
//	}
//}
//
///* l is for left index and r is right index of the
//sub-array of arr to be sorted */
//void mergeSort(int arr[], int l, int r)
//{
//	if (l < r)
//	{
//		// Same as (l+r)/2, but avoids overflow for 
//		// large l and h 
//		int m = l + (r - l) / 2;
//
//		// Sort first and second halves 
//		mergeSort(arr, l, m);
//		mergeSort(arr, m + 1, r);
//
//		merge(arr, l, m, r);
//	}
//}
//// first num tells us cols
//
///* UTILITY FUNCTIONS */
///* Function to print an array */
//void printArray(int A[], int size)
//{
//	FILE *fp;
//
//	fp = fopen("merge.txt", "w+");
//	int i;
//	for (i = 0; i < size; i++)
//		fprintf(fp, "%d ", A[i]);
//	fprintf(fp, "\n");
//	fclose(fp);
//}
//
//// getNumLines and getLongestLine could be made more efficient with one open,
//// then using fseek or rewind to get back to beginning of file
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
//
//	numRows = getNumLinesInFile();
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
//
//
///* Driver program to test above functions */
//int main()
//{
//	//int arr[] = { 0 };
//	//int numRows = 0;
//	//int arr** = (int **)malloc(numRows * sizeof(int *));
//	//int arr_size = sizeof(arr) / sizeof(arr[0]);
//	int arr** = readFile();
//
//	//printf("Given array is \n");
//	//printArray(arr, arr_size);
//
//	mergeSort(arr, 0, arr_size - 1);
//
//	printf("\nSorted array is \n");
//	printArray(arr, arr_size);
//	return 0;
//}

/* C program for Merge Sort */
#include<stdlib.h>
#include<stdio.h>

/**********************************
* Merge sort Algorithm was taken from
* https://www.geeksforgeeks.org/merge-sort/
* 09/30/18
***********************************/
void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[n1], R[n2];

	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	i = 0;
	j = 0;
	k = l;
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

	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

void printArray(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}

int main(void) {
	int i;
	int h;
	int ch;
	int numOfLines = 0;
	int nextLine = 1;
	FILE * fp;
	char * line = NULL;
	size_t len = 0;
	int read;
	int* ptr;
	int curFill = 0;
	fp = fopen("data.txt", "r");

	if (fp == NULL) {
		return 0;
	}

	/******************************************************************************/
	FILE *f = fopen("merge.out", "w");
	if (f == NULL)
	{
		printf("Error opening file!\n");
		exit(1);
	}

	while (!feof(fp)) {
		ch = fgetc(fp);
		if (ch == '\n') {
			numOfLines++;
		}
	}
	fclose(fp);
	//printf("%d\n", numOfLines);
	fopen("data.txt", "r");
	/******************************************************************************/
	for (h = 0; h < numOfLines; h++) {
		int size;
		if (!fscanf(fp, "%d", &size)) {
			break;
		}
		int length = size;
		//printf("%d\n",length);
		ptr = malloc(length * sizeof(int));

		for (i = 0; i<length; i++) {
			int nextNum;
			fscanf(fp, "%d", &nextNum);
			ptr[curFill] = nextNum;
			curFill++;
		}

		for (i = 0; i < length; i++) {
			//printf("array number: %d\n", ptr[i]);
		}

		//printf("Given array is \n");
		//printArray(ptr, length);
		mergeSort(ptr, 0, length - 1);
		//printf("\nSorted array is \n");
		//printArray(ptr, length);
		/* print integers and floats */
		for (i = 0; i < length; i++) {
			int printNumber = ptr[i];
			fprintf(f, "%d ", printNumber);
		}
		fprintf(f, "\n");
		curFill = 0;
		free(ptr);
	}

	fclose(f);
	fclose(fp);
	if (line) {
		free(line);
	}
	return 0;
}
