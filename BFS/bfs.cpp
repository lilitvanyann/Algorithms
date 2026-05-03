#include "bfs.h"
#include <stdexcept>

BFSdata::BFSdata(int n)
{
   color.assign(n, WHITE);
   distance.assign(n, -1);
   parent.assign(n, -1);
}

BFSdata BFS(graph& g, int start) {
    int n = g.getSize();

    if (start < 0 || start >= n) {
        throw std::out_of_range("Invalid start vertex");
    }
    BFSdata data(n);

    std::queue<int> q;
    data.color[start] = GRAY;
    data.distance[start] = 0;

    q.push(start);
    const auto& adj = g.getAdj();

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (data.color[v] == WHITE)
            {
                data.color[v] = GRAY;
                data.distance[v] = data.distance[u] + 1;
                data.parent[v] = u;

                q.push(v);
            }
        }
        data.color[u] = BLACK;
    }
    return data;
}



