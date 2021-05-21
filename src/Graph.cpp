#include "..\include\Graph.h"
#include "Graph.h"
#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>

Graph::Graph(int vertexAmount) : m_vertexAmount(vertexAmount) //	this->V = vertexAmount;
{
    m_adj.resize(vertexAmount); //	adj = new list<int>[V];
    m_father.resize(vertexAmount);
    //insert to any vertex his father
    for (int i = 0; i < vertexAmount; i++)
        m_father[i] = -1;
    m_vertex.resize(0);
}

void Graph::addEdge(int source, int add)
{
    m_adj[source].push_back(add); //adj[source].push_back(add); // Add the neiboor to source
}

void Graph::reduceEdge(int a, int b)
{
  //  std::list myList = m_adj[a];
    std::remove_copy(m_adj[a].begin(), m_adj[a].end(), m_adj[a].begin(),b );
  //  std::remove_copy(m_adj[b].begin(), m_adj[b].end(), m_adj[b].begin(), a);
}

void Graph::BFS(int s, int t)
{
    m_vertex.resize(0);
    // Mark all the vertices as not visited
    std::vector<bool> visited ;//  bool* visited = new bool[V];
    visited.resize(m_vertexAmount);
    for (int i = 0; i < visited.size() ; i++)
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


    while (t != -2)
    {
        m_vertex.push_back(t);
        t = m_father[t];
    }
    /*
    //the t vertex accessible
    if (m_father[t] == -2)
        return true;
    //the t vertex is not accessible
    return false;
    */
}

std::vector<int> Graph::getVertex() const
{
    return m_vertex;
}

void Graph::setVertexes(const int newsize)
{
    m_vertexAmount = newsize;
    m_adj.resize(m_vertexAmount);
    m_father.resize(m_vertexAmount);
    for (int i = 0; i < m_vertexAmount; i++)
        m_adj[i].clear();
    //insert to any vertex his father
    for (int i = 0; i < m_vertexAmount; i++)
        m_father[i] = -1;
    m_vertex.resize(0);
}

void Graph::operator=(const Graph& graph)
{
       std::copy(graph.m_adj.begin(), graph.m_adj.end(), this->m_adj.begin());
       std::copy(graph.m_father.begin(), graph.m_father.end(), this->m_father.begin());
       std::copy(graph.m_vertex.begin(), graph.m_vertex.end(), this->m_vertex.begin());
       this->m_vertexAmount = graph.m_vertexAmount;
}

