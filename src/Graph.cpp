#include "Graph.h"
#include <iostream>
#include <vector>
#include <list>
#include <iterator>

Graph::Graph(int vertexAmount) : m_vertexAmount(vertexAmount) //	this->V = vertexAmount;
{
    m_adj.resize(vertexAmount); //	adj = new list<int>[V];
    //insert to any vertex his father
    for (int i = 0; i < vertexAmount; i++)
        m_father[i] = -1;
    m_vertex.resize(0);
}

void Graph::addEdge(int source, int add)
{
    m_adj[source].push_back(add); //adj[source].push_back(add); // Add the neiboor to source
}

void Graph::BFS(int s, int t)
{
    m_vertex.resize(0);
    // Mark all the vertices as not visited
    std::vector<bool>(v) visited;//  bool* visited = new bool[V];
    for (int i = 0; i < m_visited; i++)
        visited[i] = false;

    // Create a queue for BFS
    std::list<int> queue;

    // Mark the current node as visited and enqueue it
    m_father[s] = -2;
    visited[s] = true;
    queue.push_back(s);

    // 'i' will be used to get all adjacent
    // vertices of a vertex
    std::list<int>::iterator i;

    while (!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        //m_vertex.push_back(s);//      cout << s << " ";
        queue.pop_front();

        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        for (i = m_adj[s].begin(); i != m_adj[s].end(); ++i)
        {
         /*   if ((*i) == t)
            {
                return;
            }*/
            if (!visited[*i])
            {
                //s is the father of all the for loop so update them father to be s
                m_father[*i] = s;
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }


    while (m_father[t] != -2 || m_father[t]!= -1)
    {
        m_vertex.push_back(t);
        t = m_father[t];
    }
    //the t vertex accessible
    if (m_father[t] == -2)
        return true;
    //the t vertex is not accessible
    return false;
}

std::vector<int> Graph::getVertex() const
{
    return m_vertex;
}
