#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class UnionFindSet
{
    private:
        vector<int> parent;
        vector<int> rank;

    public:
        UnionFindSet(int n)
        {
            parent.resize(n);
            rank.resize(n, 0);
            for(int i = 0; i < n; i++)
                parent[i] = i;
        }

        int find(int x)
        {
            if(parent[x] != x)
            {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }

        void Unite(int x, int y)
        {
            int rootX = find(x);
            int rootY = find(y);

            if(rootX != rootY)
            {
                if(rank[rootX] > rank[rootY])
                {
                    parent[rootY] = rootX;
                }
                else if(rank[rootX] < rank[rootY])
                {
                    parent[rootX] = rootY;
                } 
                else
                {
                    parent[rootY] = rootX;
                    rootX++;
                }   
            }
        }
};

int Kruskal(int n, priority_queue<edge>& edge_set)
{
    UnionFindSet Tree(n);
    int tree_length = 0;
    int edge_count = 0;

    while(!edge_set.empty() && edge_count < n-1)
    {
        edge target_edge = edge_set.top();
        edge_set.pop();
        if(Tree.find(target_edge.x) != Tree.find(target_edge.y))
        {
            Tree.Unite(target_edge.x, target_edge.y);
            tree_length += target_edge.d;
            edge_count++;
        }
    }

    return tree_length;
}

struct edge
{
    int x, y, d;
    edge(int x, int y, int d) : x(x), y(y), d(d){}

    bool operator< (const edge& other) const
    {
        return d > other.d;     // > for MST
    }
};