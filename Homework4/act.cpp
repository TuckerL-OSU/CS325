// Tucker Lavell
// CS325 Sp 2019
// Homework 4 - act.cpp
// merge sort from homework 1
// recieved help from friend Dan Drapp

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
	int actCounter = 0;
	Activity subset[numActivities];
	
	insertionSort(activities, numActivities);
	//for (int x = 0; x < numActivities; x++) {
	//	cout << "Activity " << activities[x].actNum << endl;
	//	cout << "Start: " << activities[x].start << "\tFinish: " << activities[x].finish << endl;
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
		if (activities[i].start != activities[i - 1].start) {
			if (activities[i].start >= subset[actCounter - 1].finish && activities[i].start >= subset[actCounter - 1].start) {
				subset[actCounter].actNum = activities[i].actNum;
				subset[actCounter].start = activities[i].start;
				subset[actCounter].finish = activities[i].finish;

				actCounter++;
			}
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
			//cout << "read " << i << endl;
			inFile >> activities[i].actNum >> activities[i].start >> activities[i].finish;
			//activitiesVec[i] = activities[i];
		}

		cout << "Set " << setCount << endl;
		lastToStart(activities, numActivities);
		setCount++;
	}

	inFile.close();
	return 0;
}