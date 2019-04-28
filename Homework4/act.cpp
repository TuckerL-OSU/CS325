// Tucker Lavell
// CS325 Sp 2019
// Homework 4 - act.cpp
// insertion sort from homework 1

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

struct Activity {
	int actNum, start, finish;
};

void insertionSort(Activity arr[], int n) {
	Activity key[n];

	int i, j;
	for (i = 1; i < n; i++) {
		key[i].actNum = arr[i].actNum;
		key[i].start = arr[i].start;
		key[i].finish = arr[i].finish;
		j = i - 1;

		/* Move elements of arr[0..i-1], that are
		greater than key, to one position ahead
		of their current position */
		while (j >= 0 && arr[j].finish > key[i].finish) {
			arr[j + 1].actNum = arr[j].actNum;
			arr[j + 1].start = arr[j].start;
			arr[j + 1].finish = arr[j].finish;
			j = j - 1;
		}

		arr[j + 1].actNum = key[i].actNum;
		arr[j + 1].start = key[i].start;
		arr[j + 1].finish = key[i].finish;
	}
}

void lastToStart(Activity activities[], int numActivities) {
	int actCounter = 0;
	Activity subset[numActivities];

	insertionSort(activities, numActivities);
	//for (int x = 0; x < numActivities; x++) {
	//	cout << "Activity " << activities[x].actNum << endl;
	//	cout << "Start: " << activities[x].start << "\tFinish: " << activities[x].finish << endl << endl;
	//}

	//add the first activity to the vector unless there are no activities in the activity.
	if (numActivities <= 0) {
		cout << "There are no activities";
		return;
	}
	else {
		subset[0].actNum = activities[0].actNum;
		subset[0].start = activities[0].start;
		subset[0].finish = activities[0].finish;

		actCounter++;
	}

	//continue to add the activity with the next closest start time that does not conflict
	//with activities already added
	for (int i = 1; i < numActivities; i++) {
		if (activities[i].start >= subset[actCounter - 1].finish) {
			subset[actCounter].actNum = activities[i].actNum;
			subset[actCounter].start = activities[i].start;
			subset[actCounter].finish = activities[i].finish;

			actCounter++;
		}
		// overwriting previous because potentially more optimal solution
		else if (activities[i].start >= subset[actCounter - 1].start && activities[i].finish >= subset[actCounter - 1].start) {
			subset[actCounter - 1].actNum = activities[i].actNum;
			subset[actCounter - 1].start = activities[i].start;
			subset[actCounter - 1].finish = activities[i].finish;
		}
		else if (activities[i].start <= subset[actCounter - 1].start && activities[i].finish >= subset[actCounter - 1].finish) {
			subset[actCounter].actNum = activities[i].actNum;
			subset[actCounter].start = activities[i].start;
			subset[actCounter].finish = activities[i].finish;

			actCounter++;
		}
	}

	cout << "Number of activities selected = " << actCounter << endl;

	//print out activity numbers selected
	cout << "Activities: ";
	for (int j = 0; j < actCounter; j++) {
		cout << subset[j].actNum << " ";
	}
	// space between set runs
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

		// do this to sanitize memory for each run
		Activity *activities = (Activity*)calloc(numActivities, sizeof(Activity));

		inFile >> numActivities;

		for (int i = 0; i < numActivities; i++) {
			inFile >> activities[i].actNum >> activities[i].start >> activities[i].finish;
		}

		cout << "Set " << setCount << endl;
		lastToStart(activities, numActivities);
		setCount++;
	}

	inFile.close();
	return 0;
}