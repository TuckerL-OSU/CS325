//// Tucker Lavell
//// CS325 Sp 2019
//// Homework 4 - act.cpp
//// merge sort from homework 1
//// recieved help from friend Dan Drapp
//
//#include <stdlib.h> 
//#include <stdio.h> 
//#include <iostream>
//#include <fstream>
//#include <vector>
//#include <ostream>
//#include <ios>
//
//using namespace std;
//
//struct Activity {
//	int actNum;
//	int start;
//	int finish;
//};
//
//
//
//void lastToStart(struct Activity arr[], int n) {
//	// **************
//	//mergeSort;
//
//	int setCount = 0;
//	cout << "Set %d" << setCount++ << endl;
//
//	// The first activity always gets selected 
//	int i = 0;
//	cout << "(" << arr[i].start << ", " << arr[i].finish << "), ";
//
//	// Consider rest of the activities 
//	for (int j = 1; j < n; j++)
//	{
//		// If this activity has start time greater than or 
//		// equal to the finish time of previously selected 
//		// activity, then select it 
//		if (arr[j].start >= arr[i].finish)
//		{
//			cout << "(" << arr[j].start << ", "
//				<< arr[j].finish << "), ";
//			i = j;
//		}
//	}
//}
//
//struct Activity **readFile() {
//	int numActivites = 0;
//	int numSets = 0;
//	ifstream inFile;
//	struct Activity **activities;
//	char *buffer;
//	char c = ' ';
//	int numOfLines = 0;
//
//	// open input file
//	inFile.open("act.txt");
//
//	// check whether the input file is opend or not
//	if (!inFile.is_open()) {
//		cout << "can't open the file" << endl;
//		exit(-1);
//	}
//
//	while (!inFile.eof()) {
//		c = fgetc(inFile);
//		if (c == '\n' || c == EOF) {
//			numOfLines++;
//		}
//	}
//	inFile.close();
//
//	inFile.open("act.txt");
//	for (int i = 0; i < numOfLines; i++) {
//		inFile >> numActivites;
//		activities
//		for (int j = 0; j < numActivites; j++) {
//			int actNum = 0;
//			int start = 0;
//			int finish = 0;
//
//			fscanf(inFile, "%d %d %d", &actNum, &start, &finish);
//			//fscanf(inFile, "%d %d %d", &activities[i].actNum, &activities[i].start, &activities[i].finish);
//			activities[numSets][i].actNum = actNum;
//			activities[numSets][i].start = start;
//			activities[numSets][i].finish = finish;
//		}
//
//		numSets++;
//		if (!inFile.eof()) {
//			continue;
//		}
//		else {
//			break;
//		}
//	}
//
//	while (numSets > 0) {
//		cout << "Set %d" << numSets - (numSets - 1) << endl;
//		cout << "Activities: ";
//
//		int sets = numSets;
//		for (int i = 0; i < sets; i++) {
//			while (activities[numSets - (numSets - 1)][i]) {
//				cout << "%d " << activities[numSets - (numSets - 1)][i];
//			}
//		}
//		numSets--;
//	}
//
//
//	//while (1) {
//	//	// read in the number of possible activities in the set
//	//	inFile >> numActivites;
//	//	activities[numSets] = (struct Activity*)malloc(numActivites * sizeof(struct Activity*));
//
//	//	int i = 0;
//	//	for (; i < numActivites; i++) {
//	//		int actNum = 0;
//	//		int start = 0;
//	//		int finish = 0;
//
//	//		fscanf(inFile, "%d %d %d", &actNum, &start, &finish);
//	//		//fscanf(inFile, "%d %d %d", &activities[i].actNum, &activities[i].start, &activities[i].finish);
//	//		activities[numSets][i].actNum = actNum;
//	//		activities[numSets][i].start = start;
//	//		activities[numSets][i].finish = finish;
//	//	}
//
//	//	numSets++;
//	//	if (i = numActivites && !inFile.eof()) {
//	//		continue;
//	//	}
//	//	else {
//	//		break;
//	//	}
//	//}
//
//	//while (numSets > 0) {
//	//	cout << "Set %d" << numSets - (numSets - 1) << endl;
//	//	cout << "Activities: ";
//	//	
//	//	int sets = numSets;
//	//	for (int i = 0; i < sets; i++) {
//	//		while (activities[numSets - (numSets - 1)][i]) {
//	//			cout << "%d " << activities[numSets - (numSets - 1)][i];
//	//		}
//	//	}
//	//	numSets--;
//	//}
//
//	inFile.close();
//	return activities;
//}
//
//int main() {
//	//int T = 0;	// num test cases
//	//int testCase = 0; // counter for case number
//	//int N = 0;	// num of items
//	//int P[100];	// prices of items
//	//int W[100];	// weights of items
//	//int F = 0;	// num of people in the family
//	//int M = 0;	// max weight that can be carried
//
//	//vector<vector<int> > knapsack(100);
//	//
//	//ofstream outFile;
//
//	//
//
//	//// check whether the input file is opend or not
//	////if (!inFile.is_open()) {
//	////	cout << "can't open the file" << endl;
//	////	return 1;
//	////}
//
//
//	//// process T number of test cases
//	//for (int i = 0; i < T; i++) {
//	//	int maxPrice = 0;
//	//	// read the number of items from the input file
//	//	inFile >> N;
//
//	//	// read the price and weight of each item into respective arrays
//	//	for (int j = 0; j < N; j++) {
//	//		inFile >> P[j];
//	//		inFile >> W[j];
//	//	}
//
//	//	//cout << "Test Case " << ++testCase << endl;
//
//	//	// read number of family members
//	//	inFile >> F;
//
//	//	// find maximum price of items that can be carried by each 
//	//	// family member and keep track the total of the maximum prices
//	//	for (int j = 0; j < F; j++) {
//	//		// read the maximum weight that can be carried by a
//	//		// current family member
//	//		inFile >> M;
//	//		// find maximum price of items that can be carried by
//	//		// current family member and add it to maxPrice
//	//		maxPrice += calcPriceKnapsack(W, P, N, M, knapsack[j]);
//	//	}
//
//	//	// print test case info to file
//	//	cout << "Test Case " << ++testCase << endl;
//	//	cout << "Total Price " << maxPrice << endl;
//	//	cout << "Member Items:" << endl;
//
//	//	// print the items each family member should take
//	//	for (int j = 0; j < F; j++) {
//	//		sort(knapsack[j].begin(), knapsack[j].end());
//	//		cout << j + 1 << ": ";
//	//		int sizeKnapsack = (int)knapsack[j].size();
//	//		for (int k = 0; k < sizeKnapsack; k++) {
//	//			cout << knapsack[j][k];
//	//			if (k != sizeKnapsack - 1) {
//	//				cout << " ";
//	//			}
//	//		}
//
//	//		cout << endl;
//	//	}
//
//	//	// add a space between each test case
//	//	if (testCase != T) {
//	//		cout << endl;
//	//	}
//	//}
//
//	//// close the file
//	//inFile.close();
//
//	readFile();
//
//	return 0;
//}



#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

struct Activity {
	int actNum, start, finish;
};

// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
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

void insertionSort(Activity arr[], int n)
{
	Activity key[n];
	int i, j;
	for (i = 1; i < n; i++) {
		key[i] = arr[i];
		j = i - 1;

		/* Move elements of arr[0..i-1], that are
		greater than key, to one position ahead
		of their current position */
		while (j >= 0 && arr[j].finish > key[i].finish) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}


//comparator helper function for sort
//int compare(Activity x, Activity y) {
//	return x.start > y.start;
//}

/***********************************************************************
** Description: lastToStart() finds the optimal solution to maximizing
** the amount of activities but finding the activity that starts last
** and working backwards toward the front and choosing the activity with
** the next closest starting time that doesn't conflict with already
** selected options.
*************************************************************************/
//void lastToStart(vector<Activity>& vec) {
//	sort(vec.begin(), vec.end(), compare);
//	/*for (int i = 0; i < vec.size(); i++)
//	cout << vec[i].number << " " << vec[i].start << " " << vec[i].finish << endl;
//	verify sort (debug)*/
//	int actCounter = 0;
//	vector<Activity> tracker;
//	//add the first activity to the vector unless there are no activities in the activity.
//	if (vec.size() <= 0) {
//		cout << "There are no activities";
//		return;
//	}
//	else {
//		tracker.push_back(vec[0]);
//		actCounter++;
//	}
//
//	//continue to add the activity with the next closest start time that does not conflict
//	//with activities already added
//	for (int i = 1; i < vec.size(); i++) {
//		if (vec[i].start != vec[i - 1].start && vec[i].finish <= tracker.back().start)
//		{
//			tracker.push_back(vec[i]);
//			actCounter++;
//		}
//	}
//
//	cout << "Number of activities selected = " << actCounter << endl;
//
//	//print out activity numbers selected
//	for (int j = tracker.size() - 1; j >= 0; j--)
//		cout << tracker[j].number << " ";
//	cout << endl << endl;
//}

void lastToStart(Activity activities[], int numActivities) {
	/*sort(vec.begin(), vec.end(), compare);*/
	//mergeSort(activities[]->finish, 0, numActivities - 1);
	insertionSort(activities, numActivities);
	/*for (int i = 0; i < vec.size(); i++)
	cout << vec[i].number << " " << vec[i].start << " " << vec[i].finish << endl;
	verify sort (debug)*/
	int actCounter = 0;
	Activity subset[numActivities];
	//add the first activity to the vector unless there are no activities in the activity.
	if (numActivities <= 0) {
		cout << "There are no activities";
		return;
	}
	else {
		subset[0] = activities[0];
		actCounter++;
	}

	//continue to add the activity with the next closest start time that does not conflict
	//with activities already added
	for (int i = 1; i < numActivities; i++) {
		if (activities[i].start != activities[i - 1].start && activities[i].finish <= subset.back().start)
		{
			subset[i] = activities[i];
			actCounter++;
		}
	}

	cout << "Number of activities selected = " << actCounter << endl;

	//print out activity numbers selected
	for (int j = actCounter - 1; j >= 0; j--)
		cout << subset[j].actNum << " ";
	cout << endl << endl;
}

int main() {
	ifstream inFile;

	inFile.open("act.txt");
	if (!inFile) {
		cout << "Unable to open file!";
		return 1;
	}

	int setCount = 1;
	while (!inFile.eof()) {
		int numActivities;
		Activity activities[numActivities];
		vector<Activity> activitiesVec(numActivities);

		inFile >> numActivities;

		for (int i = 0; i < numActivities; i++) {
			inFile >> activities[i].actNum >> activities[i].start >> activities[i].finish;
			activitiesVec[i] = activities[i];
		}

		cout << "Set " << setCount << endl;
		lastToStart(activities, numActivities);
		setCount++;
	}

	inFile.close();
	return 0;
}