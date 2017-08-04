#include <queue>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include "graph.h"

using namespace std;

Graph::Graph()
{
    //Empty Constructor
}

bool Graph::findVertex(int vertex)
{
	if (adj_list.find(vertex) == adj_list.end())
	{
	  return false;
	} 
	else
	{
	  return true;
	}
}
 
void Graph::addEdge(int v, int w)
{
    if (v == w)
    {
        cout << "Cannot add an edge to itself." << endl;
    }

	if(adj_list.empty() || !(this->findVertex(v)) )
	{
		adj_list[v] = vector<int>(); // Add w to v’s list
		adj_list[v].push_back(w);
	}
	else
	{
		adj_list[v].push_back(w);
	}

}

void Graph::DepthFirstSearchHelper(int source, map<int, bool>& visited)
{
    int vertex_to_explore;
    stack<int> stack_nodes;
    vector<int>::iterator it;

    stack_nodes.push(source);

    while(!stack_nodes.empty())
    {
        vertex_to_explore = stack_nodes.top();
        stack_nodes.pop();

        for(it = adj_list[vertex_to_explore].begin(); it < adj_list[vertex_to_explore].end(); it++) {
        // found nth element..print and break.
            if(!visited[*it])
            {
                visited[*it] = true;
                cout << "Node Value: " << *it << endl;
                DepthFirstSearchHelper(*it, visited);
            }
        }
    }
}

void Graph::BreadthFirstSearch(int source)
{
	int vertex_to_explore;
	map<int, bool> visited;
    vector<int>::iterator it;

    // Create a mapping of ints to booleans -- visisted nodes will be set to true
    // This will prevent cycles
	for(map<int, vector<int> >::iterator it = adj_list.begin(); it != adj_list.end(); ++it) {
	  visited[it->first] = false;
	}

    queue<int> queue_nodes;
    queue_nodes.push(source);

    while(!queue_nodes.empty())
    {
    	vertex_to_explore = queue_nodes.front();
    	queue_nodes.pop();
    	for(it = adj_list[vertex_to_explore].begin(); it < adj_list[vertex_to_explore].end(); it++) {
	    // found nth element..print and break.
    		if(!visited[*it])
    		{
    			visited[*it] = true;
    			cout << "Node Value: " << *it << endl;
    			queue_nodes.push(*it);
    		}
		}

    }
}

void Graph::DepthFirstSearch(int source)
{
	map<int, bool> visited;

    // Create a mapping of ints to booleans -- visisted nodes will be set to true
    // This will prevent cycles
	for(map<int, vector<int> >::iterator it = adj_list.begin(); it != adj_list.end(); ++it) {
	  visited[it->first] = false;
	}

    DepthFirstSearchHelper(source, visited);
}