#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <climits>
#include <queue>
#include <stack>
#include <numeric>
#include <unordered_map>

using namespace std;

struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2> &pair) const {
        return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
    }
};

int n, m, start, finish; // number of vertices
vector<pair<int, int>> graph[10010];
int paths[10010] = {
    0,
};
bool visited[10010] = {
    false,
};
int dist[10010];
stack<int> s;

void dfs(int index)
{
    visited[index] = true;
    for (auto neighbour : graph[index])
    {
        if (!visited[neighbour.first])
        {
            dfs(neighbour.first);
        }
    }
    s.push(index);
}

void topoSort()
{
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }
}

void init() {
    int from, to, time;
    cin >> n >> m;
    fill(dist, dist + n, INT_MIN);

    for (size_t i = 0; i < m; i++)
    {
        cin >> from >> to >> time;
        graph[from].push_back({to, time});
    }

    cin >> start >> finish;
}

pair<int,int> longest(int start) {
    pair<int,int> result = {0,0};
    
    topoSort();
    
    dist[start] = 0;
    paths[start] = 1;
    while (!s.empty())
    {
        int u = s.top();
        s.pop();

        if (dist[u] != INT_MIN)
        {
            for (auto neighbour : graph[u])
            {
                if (dist[neighbour.first] < dist[u] + neighbour.second)
                {
                    dist[neighbour.first] = dist[u] + neighbour.second;
                    paths[neighbour.first] = paths[u];
                }
                else if (dist[neighbour.first] == dist[u] + neighbour.second)
                {
                    paths[neighbour.first] = paths[neighbour.first] + paths[u];
                }
            }
        }
    }
    

    result.first = dist[finish];
    result.second = paths[finish];
    return result;
}

int main() {
    init();
    pair<int, int> p = longest(start);
        
    printf("%d %d", p.first, p.second);
}
/*
6 8
3 4 2
3 0 1
0 2 1
3 2 4
4 2 2
1 3 5
0 5 1
5 2 2
3 2

6 10
3 4 2
3 0 1
0 2 1
3 2 4
4 2 2
0 5 1
5 2 2
1 2 10
3 1 5
1 0 59
3 2


6 11
3 4 2
3 0 1
0 2 1
3 2 4
4 2 2
0 5 1
5 2 2
1 2 10
3 1 5
1 0 59
1 4 65
3 2
*/