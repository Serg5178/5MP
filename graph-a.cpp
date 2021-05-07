#include <vector>
#include <queue>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <ctime>
#include <set>
#include "graph.h"
using namespace std;

//Поиск в глубину
void dfs(size_t start, vector<bool> &visited, vector<int> &prev, adjacency_list g)
{
    visited[start] = true;
    prev.push_back(start);
    for (auto i : g.get()[start])
    {
        if (!visited[i.first])
        {
            dfs(i.first, visited, prev, g);
        }
    }
}

//Поиск в ширину
void bfs(size_t start, vector<bool> &visited, vector<int> &prev, adjacency_list g)
{
    queue<size_t> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty())
    {
        size_t vertexTemp = q.front();
        prev.push_back(vertexTemp);
        q.pop();
        for (auto i : g.get()[vertexTemp])
        {
            if (!visited[i.first])
            {
                visited[i.first] = true;
                q.push(i.first);
            }
        }
    }
}

//Алгоритм Дейкстры
vector<int> dijkstra(size_t start, adjacency_list g)
{
    const size_t infty = 20000000;
    auto graph = g.get();
    size_t size = g.get_quantity_vertex();
    vector<int> D(size, infty);
    vector<size_t> P(size);
    vector<bool> U(size, false);
    D[start] = 0;
    for (size_t i = 0; i < size; i++)
    {
        size_t v = 100000000;
        for (size_t j = 0; j < size; j++)
        {
            if (!U[j] && (v == 100000000 || D[j] < D[v]))
                v = j;
        }
        if (D[v] == infty)
            break;
        U[v] = true;
        auto beg = graph[v].begin();
        auto end = graph[v].end();
        while (beg != end)
        {
            auto to = beg->first;
            auto whight = beg->second;
            if (D[v] + whight < D[to])
            {
                D[to] = D[v] + whight;
                P[to] = v;
            }
            beg++;
        }
    }
    return D;
}

//Алгоритм Флойда-Уоршала
vector<vector<int>> floydWarshall(adjacency_list g)
{
    auto matrix = g.toMatrix();
    for (size_t i = 0; i < matrix.size(); i++)
    {
        for (size_t j = 0; j < matrix.size(); j++)
        {
            for (size_t k = 0; k < matrix.size(); k++)
            {
                matrix[j][k] = min(matrix[j][k], matrix[j][i] + matrix[i][k]);
            }
        }
    }
    return matrix;
}

//Алгоритм Крускала
adjacency_list kruskal(adjacency_list g)
{
    auto edges = g.get_edges();
    sort(edges.begin(), edges.end(),
         [](auto T1, auto T2) {
             return get<2>(T1) < get<2>(T2);
         });
    auto size = g.get_quantity_vertex();
    adjacency_list result(size);
    vector<size_t> tree_id(size);
    for (size_t i = 0; i < size; i++)
    {
        tree_id[i] = i;
    }
    for (size_t i = 0; i < size; i++)
    {
        size_t out = get<0>(edges[i]), to = get<1>(edges[i]);
        int wight = get<2>(edges[i]);
        if (tree_id[out] != tree_id[to])
        {
            result.add_edge(edges[i]);
            size_t old_id = tree_id[to], new_id = tree_id[out];
            for (size_t j = 0; j < size; j++)
            {
                if (tree_id[j] == old_id)
                {
                    tree_id[j] = new_id;
                }
            }
        }
    }
    return result;
}

//Алгоритм Прима
vector<pair<size_t, size_t>> prim(adjacency_list graph)
{
    const size_t infty = 20000000;
    auto size = graph.get_quantity_vertex();
    auto g = graph.get();
    vector<pair<size_t, size_t>> result;
    vector<size_t> min_e(size, infty), parent(size, -1);
    min_e[0] = 0;
    set<pair<int, int>> q;
    q.insert(make_pair(0, 0));
    for (size_t i = 0; i < size; ++i)
    {
        if (q.empty())
        {
            return vector<pair<size_t, size_t>>();
        }
        size_t v = q.begin()->second;
        q.erase(q.begin());

        if (parent[v] != -1)
            result.push_back(make_pair(v, parent[v]));

        for (size_t j = 0; j < g[v].size(); ++j)
        {
            int to = g[v][j].first,
                cost = g[v][j].second;
            if (cost < min_e[to])
            {
                q.erase(make_pair(min_e[to], to));
                min_e[to] = cost;
                parent[to] = v;
                q.insert(make_pair(min_e[to], to));
            }
        }
    }
    return result; 
}