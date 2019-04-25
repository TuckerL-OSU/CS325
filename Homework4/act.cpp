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
//
//using namespace std;
//
//struct Activity {
//	int actNum;
//	int start;
//	int finish;
//};
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
//
//void lastToStart(struct Activity arr[], int n) {
//	// **************
//	mergeSort;
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
//int* readFile() {
//
//}
//
//int main() {
//	int T = 0;	// num test cases
//	int testCase = 0; // counter for case number
//	int N = 0;	// num of items
//	int P[100];	// prices of items
//	int W[100];	// weights of items
//	int F = 0;	// num of people in the family
//	int M = 0;	// max weight that can be carried
//
//	vector<vector<int> > knapsack(100);
//	ifstream inFile;
//	ofstream outFile;
//
//	// open input file
//	inFile.open("act.txt");
//
//	// check whether the input file is opend or not
//	if (!inFile.is_open()) {
//		cout << "can't open the file" << endl;
//		return 1;
//	}
//
//	// read the number of test cases from the input file
//	inFile >> T;
//
//	// process T number of test cases
//	for (int i = 0; i < T; i++) {
//		int maxPrice = 0;
//		// read the number of items from the input file
//		inFile >> N;
//
//		// read the price and weight of each item into respective arrays
//		for (int j = 0; j < N; j++) {
//			inFile >> P[j];
//			inFile >> W[j];
//		}
//
//		//cout << "Test Case " << ++testCase << endl;
//
//		// read number of family members
//		inFile >> F;
//
//		// find maximum price of items that can be carried by each 
//		// family member and keep track the total of the maximum prices
//		for (int j = 0; j < F; j++) {
//			// read the maximum weight that can be carried by a
//			// current family member
//			inFile >> M;
//			// find maximum price of items that can be carried by
//			// current family member and add it to maxPrice
//			maxPrice += calcPriceKnapsack(W, P, N, M, knapsack[j]);
//		}
//
//		// print test case info to file
//		cout << "Test Case " << ++testCase << endl;
//		cout << "Total Price " << maxPrice << endl;
//		cout << "Member Items:" << endl;
//
//		// print the items each family member should take
//		for (int j = 0; j < F; j++) {
//			sort(knapsack[j].begin(), knapsack[j].end());
//			cout << j + 1 << ": ";
//			int sizeKnapsack = (int)knapsack[j].size();
//			for (int k = 0; k < sizeKnapsack; k++) {
//				cout << knapsack[j][k];
//				if (k != sizeKnapsack - 1) {
//					cout << " ";
//				}
//			}
//
//			cout << endl;
//		}
//
//		// add a space between each test case
//		if (testCase != T) {
//			cout << endl;
//		}
//	}
//
//	// close the file
//	inFile.close();
//
//	return 0;
//}

#include<bits/stdc++.h>

using namespace std;

//main function

int main()

{

	//read the given file

	freopen("act.txt", "r", stdin);

	//declare the variable for at for activities

	//st for start time and ft for finish time

	//sn for set number

	int tt = 1, at, st, ft, sn = 1;

	int i;

	while (cin >> tt)

	{

		//pair template using vector

		vector<pair<int, pair<int, int> > > p;

		for (i = 0; i < tt; ++i)

		{

			cin >> at >> st >> ft;

			p.push_back(make_pair(ft, make_pair(st, at)));

		}

		//sort the activities

		sort(p.begin(), p.end());

		//initializes the last lt is 0

		int lt = 0;

		//declare the vector variable sd for selected Activities

		vector<int> sd;

		//push the selected activities

		sd.push_back(p[0].second.second);

		for (i = 1; i < tt; ++i)

		{

			if (p[i].second.first >= p[lt].first)

			{

				sd.push_back(p[i].second.second);

				lt = i;

			}

		}

		//print the given result

		cout << "Set " << sn << endl;

		cout << "Number of activities selected = " << sd.size() << "\n";

		cout << "Activities: ";

		for (int i : sd)

		{

			cout << i << " ";

		}

		cout << "\n";

		sn++;

	}

}