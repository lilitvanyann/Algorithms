#pragma once
#include <queue>
#include "graph.h"

enum Color { WHITE, GRAY, BLACK };

struct BFSdata {
    std::vector<Color> color;
    std::vector<int> distance;
    std::vector<int> parent;

    BFSdata(int n);
};

BFSdata BFS(graph& g, int start);



