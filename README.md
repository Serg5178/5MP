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
0 (1,4) (2,7) (3,4) (4,7) 
1 
2 (0,4) (4,5) 
3 (0,2) (1,7) (4,7) 
4 (0,8) (1,9) 
print for https://csacademy.com/app/graph_editor/
0 1 4
0 2 7
0 3 4
0 4 7
2 0 4
2 4 5
3 0 2
3 1 7
3 4 7
4 0 8
4 1 9
dfs:
1 1 1 1 1 
2 0 1 3 4 
bfs:
1 1 1 1 1 
2 0 4 1 3 
dijkstra:
0 4 7 4 7 
Floyd Warshall:
    0    4    4    2    8
    4    0    8    6    9
    4    8    0    6    5
    2    6    6    0    7
    8    9    5    7    0
Kruskal:
0 (1,4) 
1 
2 (0,4) (4,5) 
3 (0,2) 
4 
print for https://csacademy.com/app/graph_editor/
0 1 4
2 0 4
2 4 5
3 0 2
Prim:
1 0
3 0
2 0
4 2
```