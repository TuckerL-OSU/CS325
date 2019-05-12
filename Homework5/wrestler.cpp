// Tucker Lavell
// CS325 Sp 2019
// Homework 5 - wrestler.cpp
// adapted from bfs, with help from friend Dan Drapp

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <fstream>
#include <sstream>
using namespace std;

enum Team {
	NONE,
	BABY,
	HEEL
};

// struct to represent each wrestler(vertices)
struct wrestler {
	string name;
	Team team;
	bool visited;
};

// initialize our graph, here we are only setting up the vertices
void createVertices(vector < vector <wrestler*> >& graph, vector <string> namesList) {
	for (int x = 0; x < (int)graph.size(); x++) {
		// creating the new vertex
		graph[x].push_back(new wrestler);

		// we assign the name to each node/vertex
		graph[x][0]->name = namesList[x];

		// as a start each wrestler will not be assigned a team
		graph[x][0]->team = NONE;

		graph[x][0]->visited = false;
	}
}

// get the index based on the wrestlers name
int getIndex(string name, vector <string> namesList) {
	for (int x = 0; x < (int)namesList.size(); x++) {
		if (name == namesList[x]) {
			return x;
		}
	}
	return -1;
}

// make connections within the graph
void addEdge(vector < vector <wrestler*> >& graph, string wrestlerName, string rivalName, vector <string> namesList) {
	int wrestler = getIndex(wrestlerName, namesList);
	int rival = getIndex(rivalName, namesList);

	// creating the edges 
	graph[wrestler].push_back(graph[rival][0]);
	graph[rival].push_back(graph[wrestler][0]);
}

// check if our graph of wrestlers can provide non conflicting rivalries
void bfs(vector < vector <wrestler*> >& graph, vector <string> namesList) {
	vector <string> babyFaces;
	vector <string> heels;

	queue < vector <wrestler*> > list;

	// analyze all the undiscovered vertices in our graph
	for (int i = 0; i < (int)graph.size(); i++) {
		if (!graph[i][0]->visited) {
			// we begin at the initial vertex, we also set the starting vertex
			// to have the team babyface, as per instructions
			graph[i][0]->team = BABY;

			// add it to list of babyfaces
			babyFaces.push_back(graph[i][0]->name);

			// add it to queue
			list.push(graph[i]);

			while (!list.empty()) {
				// extract the current vertex from queue
				vector <wrestler*> currentWrestler = list.front();
				currentWrestler[0]->visited = true;
				list.pop();

				// here we check for the neighbors of this vertex
				for (int x = 1; x < (int)currentWrestler.size(); x++) {
					// condition to check if the neighbor has been previously discovered
					if (currentWrestler[x]->visited == false) {
						// assign the teams
						// set the neighbor to heel if the predecessor is a babyface
						if (currentWrestler[x]->team == NONE && currentWrestler[0]->team == BABY) {
							currentWrestler[x]->team = HEEL;

							heels.push_back(currentWrestler[x]->name);
						}
						// set the neighbor to babyface if the predecessor is a heel
						else if (currentWrestler[x]->team == NONE && currentWrestler[0]->team == HEEL) {
							currentWrestler[x]->team = BABY; 

							babyFaces.push_back(currentWrestler[x]->name);
						}
						// conflict found
						else if (currentWrestler[x]->team == currentWrestler[0]->team) {
							cout << "No" << endl;
							return;
						}

						// lastly we add the undiscovered neighboring vertex to our queue
						list.push(graph[getIndex(currentWrestler[x]->name, namesList)]);
					}
				}
			}
		}
	}

	// show the result
	cout << "Yes" << endl;
	cout << "Babyfaces: ";
	for (int x = 0; x < (int)babyFaces.size(); x++) {
		cout << babyFaces[x] << " ";
	}
	cout << endl << "Heels: ";
	for (int x = 0; x < (int)heels.size(); x++) {
		cout << heels[x] << " ";
	}
	cout << endl;
}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		cout << "Incorrect Arguments. Please use: \"./wrestler [file].txt\"" << endl;
		return 0;
	}

	// setting the file
	ifstream inFile(argv[1]);

	while (!inFile.eof()) {
		int size;
		int edges;
		string currentName;
		vector <string> namesList;

		// getting the number of vertices
		inFile >> size;

		// declare graph
		vector < vector < wrestler*> > graph(size);

		// storing the names
		for (int x = 0; x < size; x++) {
			inFile >> currentName;

			namesList.push_back(currentName);
		}

		// creating the vertices for our graph
		createVertices(graph, namesList);

		// getting the number of pairs/edge connections
		inFile >> edges;

		// making the connections for the graph
		for (int x = 0; x < edges; x++) {
			// getting the vertices involved in the pair
			string wrestlerName, rivalName;
			inFile >> wrestlerName;
			inFile >> rivalName;

			// make the connections for the graph
			addEdge(graph, wrestlerName, rivalName, namesList);
		}

		bfs(graph, namesList);
	}

	inFile.close();

	return 0;
}