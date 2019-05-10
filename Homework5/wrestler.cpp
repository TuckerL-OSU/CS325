// Tucker Lavell
// CS325 Sp 2019
// Homework 5 - wrestler.cpp
// adapted from bfs

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
void createVertices(vector < vector <wrestler*> >& graph, vector <string> values) {
	for (int x = 0; x < (int)graph.size(); x++) {
		// creating the new vertex
		graph[x].push_back(new wrestler);

		// we assign the name to each node/vertex
		graph[x][0]->name = values[x];

		// as a start each wrestler will not be assigned a team
		graph[x][0]->team = NONE;

		graph[x][0]->visited = false;
	}
}

// get the index based on the wrestlers name
int getIndex(vector<string> values, string source) {
	for (int x = 0; x < (int)values.size(); x++) {
		if (source == values[x]) {
			return x;
		}
	}
	return -1;
}

// make connections within the graph
void addEdge(vector < vector <wrestler*> >& graph, string A, string B, vector <string> reference) {
	int source = getIndex(reference, A);
	int partner = getIndex(reference, B);

	// creating the pairs 
	graph[source].push_back(graph[partner][0]);
	graph[partner].push_back(graph[source][0]);
}

// check if our graph of wrestlers can provide non conflicting rivalries
void bfs(vector < vector <wrestler*> >& graph, vector <string> reference) {
	vector <string> babyFaces;
	vector <string> heels;

	queue < vector <wrestler*> > list;

	// analyze all the undiscovered vertices in our graph
	for (int i = 0; i < (int)graph.size(); i++) {
		if (!graph[i][0]->visited) {
			// we begin at the initial vertex, we also set the starting vertex
			// to have the team babyface, as per instructions
			graph[i][0]->team = BABY;

			// we also add it to our list of babyfaces
			babyFaces.push_back(graph[i][0]->name);

			// add it to our queue
			list.push(graph[i]);

			while (!list.empty()) {
				// extract the current vertex from our queue
				vector <wrestler*> currentNode = list.front();
				currentNode[0]->visited = true;
				list.pop();

				// here we now check for the neighbors of this vertex
				for (int x = 1; x < (int)currentNode.size(); x++) {
					// condition to check if the neighbor has been previously discovered
					if (currentNode[x]->visited == false) {
						// here is how we assign the teams
						/*
						basically if the current wrestler is a babyface than its neighbors must be heels
						we first check what team the neighbors have
						if they are unknown, than set it to the opposite team from the current vertex
						if they have the same team as the predecessor than we end the traversal because this signals a conflict
						*/
						if (currentNode[x]->team == NONE && currentNode[0]->team == BABY) {
							currentNode[x]->team = HEEL; // set the neighbor to heel if the predecessor is a babyface

							heels.push_back(currentNode[x]->name); // updating our list of heels
						}
						else if (currentNode[x]->team == NONE && currentNode[0]->team == HEEL) {
							currentNode[x]->team = BABY; // set the neighbor to babyface if the predecessor is a heel

							babyFaces.push_back(currentNode[x]->name);  // updating our list of babyfaces
						}
						else if (currentNode[x]->team == currentNode[0]->team) {
							// conflict found
							cout << "Impossible" << endl;
							return;
						}

						// lastly we add the undiscovered neighboring vertex to our queue
						list.push(graph[getIndex(reference, currentNode[x]->name)]);
					}
				}
			}
		}
	}

	// showcasing the result
	cout << "Yes possible" << endl;
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

// method to showcase the graph layout
//void viewGraph(vector < vector <wrestler*> > graph)
//{
//	for (int x = 0; x < graph.size(); x++)
//	{
//		cout << "Current Node: " << graph[x][0]->name << endl;
//
//		if (graph[x].size() > 1)
//		{
//			cout << "Connections are:" << endl;
//		}
//
//		for (int y = 1; y < graph[x].size(); y++)
//		{
//			cout << graph[x][y]->name << " " << graph[x][y]->team << " " << graph[x][y]->visited << endl;
//		}
//		cout << endl;
//	}
//}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		cout << "There is an error please, specify a file in the command line next to the executable name" << endl;
		return 0;
	}

	// setting the file
	ifstream inFile(argv[1]);

	while (!inFile.eof()) {
		int size;
		int edges;
		string currentName;
		vector <string> names;

		// getting the number of vertices
		inFile >> size;

		// declaring our graph
		vector < vector < wrestler*> > graph(size);

		// storing the names
		for (int x = 0; x < size; x++) {
			inFile >> currentName;

			names.push_back(currentName);
		}

		// creating the vertices for our graph
		createVertices(graph, names);

		// getting the number of pairs/edge connections
		inFile >> edges;

		// making the connections for our graph
		for (int x = 0; x < edges; x++) {
			// getting the vertices involved in the pair
			string a, b;
			inFile >> a;
			inFile >> b;

			// making the connections for our graph
			addEdge(graph, a, b, names);
		}

		bfs(graph, names);
	}

	inFile.close();

	return 0;
}