#include <queue>
#include <iostream>
#include <queue>
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

void Graph::BreadthFirstSearch(int source)
{
	int vertex_to_explore;
	map<int, bool> visited;
    vector<int>::iterator it;

    // visited map is used to prevent cycles
	for(map<int, vector<int> >::iterator it = adj_list.begin(); it != adj_list.end(); ++it) {
	  visited[it->first] = false;
	}

    queue<int> queue_visted;
    queue_visted.push(source);
    cout << "Starting with source: " << source << endl;

    while(!queue_visted.empty())
    {
    	vertex_to_explore = queue_visted.front();
    	queue_visted.pop();
    	for(it = adj_list[vertex_to_explore].begin(); it < adj_list[vertex_to_explore].end(); it++) {
	    // found nth element..print and break.
    		if(!visited[*it])
    		{
    			visited[*it] = true;
    			cout << "Node Value: " << *it << endl;
    			queue_visted.push(*it);
    		}
		}

    }
}