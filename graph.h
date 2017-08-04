#ifndef GRAPH_H
#define GRAPH_H

#include <map>
#include <vector>

using namespace std;

class Graph
{
	private:
		map<int, vector<int> > adj_list;
		bool findVertex(int i);
		void DepthFirstSearchHelper(int source, map<int, bool>& visited);

	public:
		Graph();
		void addEdge(int vertex, int newEdge);
		void BreadthFirstSearch(int source);
		void DepthFirstSearch(int source);
};

#endif
