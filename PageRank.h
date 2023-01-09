#pragma once
#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <vector>
#include <iomanip> // https://cplusplus.com/reference/iomanip/setprecision/
using namespace std;
// https://pencilprogrammer.com/cpp-programs/iterate-through-map/


class AdjacencyList {

private:
	map<string, double> pageRankMap; // stores page ranks of websites
	unordered_map<string, int> outDegree; // keeps track of how many outDegrees a website has
	unordered_map<string, vector<string>> inDegree; // adjacency list

public:
	void PageRank(int n);
	void InsertEdge(string& from, string& to);

};

void AdjacencyList::InsertEdge(string& from, string& to) {

	outDegree[from] += 1;
	inDegree[to].push_back(from);


	// make sure both maps have all vertices accounted for
	if (inDegree.count(from) == 0) 
		inDegree[from] = {};

	if (outDegree.count(to) == 0)
		outDegree[to] = 0;

}

void AdjacencyList::PageRank(int n) {


	// each page rank is set equal to (1 / # of vertices)
	for (auto& vertices : inDegree) {
		pageRankMap[vertices.first] = 1.0 / (double)inDegree.size();
	}


	// helps keep track of old page rank for power iterations
	map<string, double> tempPageRank;


	for (int i = 0; i < n - 1; i++) {	// loops power iterations

		tempPageRank = pageRankMap;

		// loops through each vertex 
		for (auto& vertices : inDegree) {

			double pageRank = 0.0;

			// iterates through a vertex's adjacent nodes
			for (auto& adjacentNodes : vertices.second) 
				pageRank += (1.0 / (double)outDegree.find(adjacentNodes)->second) * pageRankMap[adjacentNodes];
			
			// add new calculated page rank
			tempPageRank[vertices.first] = pageRank;
		}

		pageRankMap = tempPageRank;
	}



	// prints page ranks
	for (auto& vertices : pageRankMap) 
		cout << fixed << setprecision(2) << vertices.first << " " << vertices.second << endl;
	
}