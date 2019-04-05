// Tucker Lavell
// CS325 Sp 2019
// Homework 1 - mergesort.c
// merge sort taken from https://www.geeksforgeeks.org/merge-sort/

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
// first num tells us cols

/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[], int size)
{
	FILE *fp;

	fp = fopen("merge.txt", "w+");
	int i;
	for (i = 0; i < size; i++)
		fprintf(fp, "%d ", A[i]);
	fprintf(fp, "\n");
	fclose(fp);
}

// getNumLines and getLongestLine could be made more efficient with one open,
// then using fseek or rewind to get back to beginning of file
int getNumLinesInFile() {
	FILE *fp;
	int numLines = 0;
	char c = '';

	fp = fopen("data.txt", "r");

	// eof contradiction
	while (1) {
		c = getc(fp);
		if (c == '\n') {
			numLines++;
		}
		else if (c == EOF) {
			numLines++;
			break;
		}
	}

	fclose(fp);

	return numLines;
}

int getLongestLineInFile() {
	FILE *fp;
	int lenOfLongest = 0;
	size_t len = 0;
	char *line = NULL;
	size_t lineBuffer = 0;

	fp = fopen("data.txt", "r");

	while (!EOF) {
		len = getline(&line, &lineBuffer, fp);

		if (len > lenOfLongest) {
			lenOfLongest = len;
		}
	}

	fclose(fp);

	return lenOfLongest;
}

int* readFile() {
	FILE *fp; 
	int numCols = 0;
	int numRows = 0;
	char *line = NULL;

	numRows = getNumLinesInFile();
	numCols = getLongestLineInFile();
	int inputArr[numRows][numCols];

	fp = fopen("data.txt", "r");
	
	int i;
	int j;
	for (i = 0; i < numRows; i++) {
		for (j = 0; j < numCols; j++) {
			fscanf(fp, "%d", &inputArr[i][j]);
		}
	}

	fclose(fp);
}


/* Driver program to test above functions */
int main()
{
	//int arr[] = { 0 };
	int numRows = 0;
	int arr** = (int **)malloc(numRows * sizeof(int *));
	int arr_size = sizeof(arr) / sizeof(arr[0]);

	printf("Given array is \n");
	printArray(arr, arr_size);

	mergeSort(arr, 0, arr_size - 1);

	printf("\nSorted array is \n");
	printArray(arr, arr_size);
	return 0;
}