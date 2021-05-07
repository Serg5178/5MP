#include "graph-a.cpp"
//Поиск в глубину
void dfs(size_t start, vector<bool> &visited, vector<int> &prev, adjacency_list g);

//Поиск в ширину
void bfs(size_t start, vector<bool> &visited, vector<int> &prev, adjacency_list g);

//Алгоритм Дейкстры
vector<int> dijkstra(size_t start, adjacency_list g);
//Алгоритм Флойда-Уоршала
vector<vector<int>> floydWarshall(adjacency_list g);

//Алгоритм Крускала
adjacency_list kruskal(adjacency_list g);

//Алгоритм Прима
vector<pair<size_t, size_t>> prim(adjacency_list graph);
