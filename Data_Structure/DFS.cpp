#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void DFSTraverse(int start, const vector<vector<int>>& graph, bool visited[]);
void DFS(int start, const vector<vector<int>>& graph, bool visited[]);

// 递归方式实现
void DFSTraverse(int start, const vector<vector<int>>& graph, bool visited[])
{
    int n = graph.size();
    bool visited[n] = {false};
    
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        DFS(start, graph, visited);
    }
}

void DFS(int start, const vector<vector<int>>& graph, bool visited[])
{
    visited[start] = true;

    for(auto& neighbor : graph[start])
    {
        if(!visited[neighbor])
        {
            DFS(neighbor, graph, visited);
        }
    }
}

// 用栈
void DFS_stack(int start, const vector<vector<int>>& graph, int n) {
    vector<bool> visited(n, false); // 标记数组
    stack<int> st;

    // 初始化
    visited[start] = true;
    st.push(start);

    while (!st.empty()) {
        int curr = st.top(); // 获取当前节点
        st.pop(); // 弹出当前节点

        cout << curr << " "; // 访问当前节点

        // 遍历当前节点的所有邻居
        for (auto it = graph[curr].rbegin(); it != graph[curr].rend(); ++it) {
            if (!visited[*it]) {
                st.push(*it);         // 邻居节点入栈
                visited[*it] = true; // 标记为已访问
            }
        }
    }
}