#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int Dijkstra(vector<vector<int>>& graph, int n)
{
    int min_length = 0;
    int edge_count = 0;
    vector<int> dist(n, INT_MAX);
    vector<bool> visited(n, false);
    
    // {weight, vertex}
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> min_edge_set; 
    //注意此处的greater是STL自带的，也可选择自己定义Compare结构体
    

    // Add the first node
    dist[0] = 0;
    min_edge_set.emplace(0,0);

    while(!min_edge_set.empty()){

        // Choose the vertex with the minimum weight
        auto [min_weight, target_vertex] = min_edge_set.top();
        min_edge_set.pop();
        
        // Unite target vertex
        if(visited[target_vertex]) continue;
        visited[target_vertex] = true;


        for(int i = 0; i < n; i++)
        {
            if(!visited[i] && graph[target_vertex][i] != INT_MAX)
            {
                if(dist[target_vertex] + graph[target_vertex][i] < dist[i] )
                {
                    dist[i] = dist[target_vertex] + graph[target_vertex][i];
                    min_edge_set.emplace(dist[i], i);
                }
            }
        }                 
    }
}