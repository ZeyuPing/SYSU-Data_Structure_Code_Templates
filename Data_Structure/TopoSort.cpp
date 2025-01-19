#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool TopoSort(vector<vector<int>>& graph, int n)
{
    vector<int> indgree(n,0);
    stack<int> st;
    int node_count = 0;

    for(int i = 0; i < n; i++)
    {
        for(auto& adj : graph[i])
        {
            indgree[adj]++;
        }
    }

    for(int i = 0; i < n; i++)
    {
        if(indgree[i] == 0)
        {
            st.push(i);
        }
    }

    while(!st.empty())
    {
        int del_node = st.top();
        st.pop();
        node_count++;

        for(auto& adj : graph[del_node])
        {
            indgree[adj]--;
            if(indgree[adj] == 0)
            st.push(adj);
        }
    }

    if(node_count == n) return true;
    else    return false;
}