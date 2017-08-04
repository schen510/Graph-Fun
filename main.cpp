#include "graph.h"
#include <iostream>

using namespace std;

int main(){
	Graph test;

	test.addEdge(0,1);
	test.addEdge(0,2);
	test.addEdge(0,3);
	test.addEdge(1,4);
	test.addEdge(1,5);
	test.addEdge(2,4);
	test.addEdge(3,4);


	test.BreadthFirstSearch(0);
	cout << "--DFS--" << endl;
	test.DepthFirstSearch(0);

	return 0;
}