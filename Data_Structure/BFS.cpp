#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(int start, const vector<vector<int>>& graph, int n)
{
    bool visited[n] = {false};
    queue<int> q;

    // Initialize
    q.push(start);
    visited[start] = true;

    // traverse
    while(!q.empty()) 
    {
        int curr = q.front();
        q.pop();

        for(auto& adj_node : graph[curr])
        {
            if(!visited[adj_node])
            {
                q.push(adj_node);
                visited[adj_node] = true;
            }
        }
    }
}