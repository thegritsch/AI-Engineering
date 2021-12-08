#include <iostream>
#include <list>
using namespace std;
//graph class for DepthFirstSearch travesal  
class DepthFirstSearchGraph
{
    int V;    // No. of vertices
    list<int>* adjList;    // adjacency list
    void DepthFirstSearch_util(int v, bool visited[]);  // A function used by DepthFirstSearch
public:
    // class Constructor
    DepthFirstSearchGraph(int V)
    {
        this->V = V;
        adjList = new list<int>[V];
    }
    // function to add an edge to graph
    void addEdge(int v, int w) {
        adjList[v].push_back(w); // Add w to v’s list.
    }
    void DepthFirstSearch();    // DepthFirstSearch traversal function
};
void DepthFirstSearchGraph::DepthFirstSearch_util(int v, bool visited[])
{
    // current node v is visited
    visited[v] = true;
    cout << v << " ";

    // recursively process all the adjacent vertices of the node
    list<int>::iterator i;
    for (i = adjList[v].begin(); i != adjList[v].end(); ++i)
        if (!visited[*i])
            DepthFirstSearch_util(*i, visited);
}

// DepthFirstSearch traversal 
void DepthFirstSearchGraph::DepthFirstSearch()
{
    // initially none of the vertices are visited 
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
        
    }
    // explore the vertices one by one by recursively calling  DepthFirstSearch_util
    // insert your code here

    visited[0] = true;
    cout << 0 << " ";

    list<int>::iterator i;
    for (i = adjList[0].begin(); i != adjList[0].end(); ++i)
        if (!visited[*i])
            DepthFirstSearch_util(*i, visited);
}

//int main()
//{
//    // in the main method we create a graph and call the breath first search method.
//    DepthFirstSearchGraph gDepthFirstSearch(5);
//    gDepthFirstSearch.addEdge(0, 1);
//    gDepthFirstSearch.addEdge(0, 2);
//    gDepthFirstSearch.addEdge(0, 3);
//    gDepthFirstSearch.addEdge(1, 2);
//    gDepthFirstSearch.addEdge(2, 4);
//    gDepthFirstSearch.addEdge(3, 3);
//    gDepthFirstSearch.addEdge(4, 4);
//
//    cout << "Depth-first traversal for the given graph:" << endl;
//    gDepthFirstSearch.DepthFirstSearch();
//}