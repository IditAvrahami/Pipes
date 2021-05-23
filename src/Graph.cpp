#include "..\include\Graph.h"
#include "Graph.h"
#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>

Graph::Graph(int vertexAmount) : m_vertexAmount(vertexAmount)
{
    m_adj.resize(vertexAmount); 
    m_father.resize(vertexAmount);
    //insert to any vertex his father
    for (int i = 0; i < vertexAmount; i++)
        m_father[i] = -1;
    m_vertex.resize(0);
}

void Graph::addEdge(int source, int add)
{
    m_adj[source].push_back(add); // Add the neiboor to source
}

void Graph::reduceEdge(int a, int b)
{
    std::vector<int> list;
    if (m_adj[a].size() == 0)
        return;
    list.resize(0);
    size_t size = m_adj[a].size();
    for (size_t i = 0; i < size; i++)
    {
        if (m_adj[a].front() != b)
            list.push_back(m_adj[a].front()); // copy the list to a vector
        m_adj[a].pop_front();
    }

    m_adj[a].clear();
    for (size_t i = 0; i < list.size(); i++)
    {
        m_adj[a].push_back(list[i]);
    }
    
}

void Graph::BFS(int s, int t)
{
    m_vertex.resize(0);
    for (int i = 0; i < m_vertexAmount; i++)
        m_father[i] = -1;
    // Mark all the vertices as not visited
    std::vector<bool> visited ;
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
            if (!visited[*i])
            {
                //s is the father of all the for loop so update them father to be s
                m_father[*i] = s;
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }


    while (t != -2 && t != -1)
    {
        m_vertex.push_back(t);
        t = m_father[t];
    }
    if (t == -1)
    {
        m_vertex.clear();
        for (int i = 0; i < visited.size(); i++)
        {
            if (visited[i])
                m_vertex.push_back(i);
        }
    }
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
       this->m_vertexAmount = graph.m_vertexAmount;
}

void Graph::resetGraph()
{
    for (int i = 0; i < m_vertexAmount; i++)
        m_adj[i].clear();
    //insert to any vertex his father
    for (int i = 0; i < m_vertexAmount; i++)
        m_father[i] = -1;
}

