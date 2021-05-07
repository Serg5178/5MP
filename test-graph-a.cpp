#include <iostream>
#include <iomanip>
#include "graph-a.h"
using namespace std;


int main()
{
    srand(time(NULL));
    adjacency_list graph;
    pair<size_t, int> edge_array[11] = {
        make_pair(0, 1), make_pair(0, 2), make_pair(0, 3),
        make_pair(0, 4), make_pair(2, 0), make_pair(3, 0),
        make_pair(2, 4), make_pair(3, 1), make_pair(3, 4),
        make_pair(4, 0), make_pair(4, 1)};
    graph.add_vertex(5);
    for (auto i : edge_array)
    {
        graph.add_edge(i.first, make_pair(i.second, 1 + rand() % 10));
    }
    cout << "Graph:\n";
    graph.print();
    vector<bool> visited(graph.get_quantity_vertex());
    vector<int> prev;
    dfs(2, visited, prev, graph);
    cout << "dfs:\n";
    for (auto i : visited)
    {
        cout << i << " ";
    }
    cout << endl;
    for (auto i : prev)
    {
        cout << i << " ";
    }
    cout << endl;

    vector<bool> visited1(graph.get_quantity_vertex());
    vector<int> prev1;
    bfs(2, visited1, prev1, graph);
    cout << "bfs:\n";
    for (auto i : visited1)
    {
        cout << i << " ";
    }
    cout << endl;
    for (auto i : prev1)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "dijkstra:\n";
    for (auto i : dijkstra(0, graph))
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "Floyd Warshall:\n";
    for (auto i : floydWarshall(graph))
    {
        for (auto j : i)
        {
            if (j != 20000000)
                cout << setw(5) << j;
            else
                cout << setw(5) << "inf";
        }
        cout << endl;
    };
    cout << "Kruskal:\n";
    auto krus = kruskal(graph);
    krus.print();
    krus.print_for_website();
    cout << "Prim:\n";
    for(auto i : prim(graph)){
        cout << i.first << " " << i.second << endl; 
    }
    return 0;
}