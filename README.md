Лабораторная работа №5а – Алгоритмы на графах

Kernel: 4.19.128-microsoft-standard

OS: Ubuntu 20.04.1 LTS on Windows 10 x86_64

gcc version 9.3.0 (Ubuntu 9.3.0-17ubuntu1~20.04)

Компилирование

```linux
g++ test-graph-a.cpp graph-a.h
```

Вывод

```linux
Graph:
0 (1,4) (2,3) (3,3) (4,6) 
1 
2 (0,9) (4,3) 
3 (0,1) (1,1) (4,7) 
4 (0,7) (1,7) 
dfs:
1 1 1 1 1 
2 0 1 3 4 
bfs:
1 1 1 1 1 
2 0 4 1 3 
dijkstra:
0 4 3 3 6 
Floyd Warshall:
    0    4    3    3    6
  inf    0  inf  inf  inf
    9   10    0   12    3
    1    1    4    0    7
    7    7   10   10    0
Kruskal:
0 (2,3) 
1 
2 (4,3) 
3 (0,1) (1,1) 
4 
print for https://csacademy.com/app/graph_editor/
0 2 3
2 4 3
3 0 1
3 1 1
Prim:
2 0
3 0
1 3
4 2
```