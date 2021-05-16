#pragma once
#include <iostream>
#include <vector>
#include <list>

class Graph
{
public:
    Graph(int vertexAmount);  // Constructor

 // function to add an edge to graph
    void addEdge(int source, int wantedToAdd);

    // prints BFS traversal from a given source s
    void BFS(int source, int t);

    std::vector<int> getVertex()const;
    
    void setVertexes(const int newsize);

private:
    int m_vertexAmount;    // No. of vertices
    std::vector<std::list<int>> m_adj;// Pointer to an array containing adjacency lists
    std::vector<int> m_father;
    std::vector<int> m_vertex;
};