#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int Prim(vector<vector<int>>& graph, int n)
{
    int min_length = 0;
    int edge_count = 0;
    vector<int> dist(n, INT_MAX);
    vector<bool> visited(n, false);

    // Add the first node
    visited[0] = true;
    for(int i = 0; i < n; i++)
    {
        if(dist[i] > graph[0][i])
        dist[i] = graph[0][i];
    }

    while(edge_count < n-1){
        edge_count++;
        // Choose the vertex with the minimum weight
        int target_vertex = -1;
        int min_weight = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
            {
                if(dist[i] < min_weight)
                {
                    min_weight = dist[i];
                    target_vertex = i;
                }
            }
        }

        if(target_vertex == -1) return -1;
        min_length += min_weight;

        // Unite target vertex
        visited[target_vertex] = true;
        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
            {
                if(dist[i] > graph[target_vertex][i])
                dist[i] = graph[target_vertex][i];
            }
        }
    }

    return min_length;
}