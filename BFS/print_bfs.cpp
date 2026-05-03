#include "print_bfs.h"
void printBFSResult(const BFSdata& data, int n, int start)
{
    std::cout << "Root (start vertex): " << start << "\n\n";

    // 1. Distance
    std::cout << "1. Tree Distance:\n\n";
    for (int i = 0; i < n; i++)
        std::cout << i << " -> " << data.distance[i] << "\n";

    std::cout << "\n";

    // 2. Parent edges
    std::cout << "2. Tree Structure:\n\n";
    for (int i = 0; i < n; i++)
    {
        if (data.parent[i] != -1)
            std::cout << data.parent[i] << " -> " << i << "\n";
    }

    std::cout << "\n";

    // 3. BFS Tree print
    printTreeBFS(data, n, start);
}

// =====================
// BFS Tree (level order print)
// =====================

void printTreeBFS(const BFSdata& data, int n, int start)
{
    std::vector<std::vector<int>> children(n);

    // build children from parent[]
    for (int i = 0; i < n; i++)
    {
        if (data.parent[i] != -1)
        {
            children[data.parent[i]].push_back(i);
        }
    }

    std::queue<int> q;
    q.push(start);

    std::cout << "3. BFS Tree (by levels):\n\n";

    while (!q.empty())
    {
        int levelSize = q.size();

        for (int i = 0; i < levelSize; i++)
        {
            int u = q.front();
            q.pop();

            std::cout << u << " ";

            for (int v : children[u])
                q.push(v);
        }

        std::cout << "\n";
    }
}
