// Tucker Lavell
// CS325 Sp 2019
// Homework 3 - shoppingSpree.cpp
// decided to use c++ this time so I could use vectors
// to make this a little easier
// follows pseudocode given for knapsack algorithm
// recieved help from friend Dan Drapp
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include <ostream>

using namespace std;

int calcPriceKnapsack(int[], int[], int, int, vector<int>&);
int getMax(int, int);

int main() {
	int T = 0;	// num test cases
	int testCase = 0; // counter for case number
	int N = 0;	// num of items
	int P[100];	// prices of items
	int W[100];	// weights of items
	int F = 0;	// num of people in the family
	int M = 0;	// max weight that can be carried

	vector<vector<int> > knapsack(100);
	ifstream inFile;
	ofstream outFile;

	// open input file
	inFile.open("shopping.txt");

	// check whether the input file is opend or not
	if (!inFile.is_open()) {
		cout << "can't open the file" << endl;
		return 1;
	}

	// open the output file
	outFile.open("results.txt");

	// check whehter the output file is opened or not
	if (!outFile.is_open()) {
		cout << "can't open the file" << endl;
		return 1;
	}

	// read the number of test cases from the input file
	inFile >> T;

	// process T number of test cases
	for (int i = 0; i < T; i++) {
		int maxPrice = 0;
		// read the number of items from the input file
		inFile >> N;

		// read the price and weight of each item into respective arrays
		for (int j = 0; j < N; j++) {
			inFile >> P[j];
			inFile >> W[j];
		}

		//cout << "Test Case " << ++testCase << endl;

		// read number of family members
		inFile >> F;

		// find maximum price of items that can be carried by each 
		// family member and keep track the total of the maximum prices
		for (int j = 0; j < F; j++) {
			// read the maximum weight that can be carried by a
			// current family member
			inFile >> M;
			// find maximum price of items that can be carried by
			// current family member and add it to maxPrice
			maxPrice += calcPriceKnapsack(W, P, N, M, knapsack[j]);
		}

		// print test case info to file
		outFile << "Test Case " << ++testCase << endl;
		outFile << "Total Price " << maxPrice << endl;
		outFile << "Member Items:" << endl;

		// print the items each family member should take
		for (int j = 0; j < F; j++) {
			sort(knapsack[j].begin(), knapsack[j].end());
			outFile << j + 1 << ": ";
			int size = (int)knapsack[j].size()
			for (int k = 0; k < size; k++) {
				if (k != size - 1) {
					outFile << knapsack[j][k] << " ";
				}
			}

			outFile << endl;
		}

		// add a space between each test case
		if (testCase != T) {
			outFile << endl;
		}
	}

	// close the files
	inFile.close();
	outFile.close();

	return 0;
}

// returns the maximum price of items that can be carried by a person, 
// whom can carry maximum weight M
int calcPriceKnapsack(int W[], int P[], int N, int M, vector<int> &knapsack) {
	// sanitize the vector element we are working on
	if (!knapsack.empty()) {
		knapsack.clear();
	}

	// Build table K[][] with items and weights
	int K[N + 1][M + 1];
	for (int i = 0; i <= N; i++) {
		for (int w = 0; w <= M; w++) {
			if (i == 0 || w == 0) {
				K[i][w] = 0;
			}
			else if (W[i - 1] <= w) {
				K[i][w] = getMax(P[i - 1] + K[i - 1][w - W[i - 1]], K[i - 1][w]);
			}
			else {
				K[i][w] = K[i - 1][w];
			}
		}
	}

	// stores the result of Knapsack
	int res = K[N][M];
	int w = M;

	//static int knapsackBin = 0;

	for (int i = N; i > 0 && res > 0; i--) {
		if (res == K[i - 1][w]) {
			continue;
		}
		else {
			// This item is included.
			knapsack.push_back(i);
			//cout << "added " << i << " to knapsackBin: " << knapsackBin << endl;
			// Since this weight is included its
			// value is deducted
			res = res - P[i - 1];
			w = w - W[i - 1];
		}
	}

	//knapsackBin++;

	// K[N][M] represents the maximum price of items that can be carried by
	// the family member
	return K[N][M];
}

// returns maximum of the two numbers received
int getMax(int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}