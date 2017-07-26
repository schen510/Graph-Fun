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
	public:
		Graph();
		void addEdge(int vertex, int newEdge);
		void BreadthFirstSearch(int source);
};

#endif
