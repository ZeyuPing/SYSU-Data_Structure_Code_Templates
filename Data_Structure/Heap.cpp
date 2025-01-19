#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct edge
{
    int x, y, weight;
    edge(int x, int y, int weight) : x(x), y(y), weight(weight){}

    bool operator< (const edge& other) const
    {
        return weight > other.weight;     // > for MST
    }
};

// 小根堆
struct Compare
{
    bool operator()(const edge& a, const edge& b) const
    {
        return a.weight > b.weight;
    }
};

priority_queue<edge, vector<edge>, Compare> min_heap;

// 默认大根堆
priority_queue<int> max_heap;