#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;
// a directed graph class
class DirectedGraph
{
    int V;    // No. of vertices
    // Pointer to array containing adjacency lists
    list<int>* adjancencyList;
public:
    DirectedGraph(int V);  // Constructor  
    // add an edge from vertex v to w
    void add_Edge(int v, int w);
    // BreathFirstSearch traversal sequence starting with s ->starting node
    void BreathFirstSearch(int s);
};
DirectedGraph::DirectedGraph(int V)
{
    this->V = V;
    adjancencyList = new list<int>[V];
}
void DirectedGraph::add_Edge(int v, int w)
{
    adjancencyList[v].push_back(w); // Add w to v’s list.
}

void DirectedGraph::BreathFirstSearch(int s)
{
    // initially none of the vertices is visited
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // queue to hold BreathFirstSearch traversal sequence 
    list<int> queue;

    // Mark the current node as visited and enqueue it 
    visited[s] = true;
    queue.push_back(s);

    // iterator 'i' to get all adjacent vertices 
    list<int>::iterator i;

    while (!queue.empty())
    {

        // insert your code here

        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        for (i = adjancencyList[s].begin(); i != adjancencyList[s].end(); ++i) {
            if (!visited[*i]) {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }

    }
}

//int main()
//{
//    // in the main method we create a graph and call the breath first search method.
//    DirectedGraph dg(5);
//    dg.add_Edge(0, 1);
//    dg.add_Edge(0, 2);
//    dg.add_Edge(0, 3);
//    dg.add_Edge(1, 2);
//    dg.add_Edge(2, 4);
//    dg.add_Edge(3, 3);
//    dg.add_Edge(4, 4);
//
//    cout << "Breadth First Traversal for given graph (with 0 as starting node): " << endl;
//    dg.BreathFirstSearch(0);
//}