#include "graph.h"

	graph::graph(int n) {
		this->n = n;
		adj.resize(n);
	}
	void graph::addEdge(int u, int v)
	{
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	void graph::printGraph() {

		for (int i = 0; i < n; ++i) {
			std::cout << i << ":";

			for (int j = 0; j < adj[i].size(); ++j)
				std::cout << adj[i][j] << " ";
			std::cout << std::endl;

		}

	}
	int graph::getSize() {
		return n;
	}

	const std::vector<std::vector<int>>& graph::getAdj() const {
		return adj;
	}
	graph::~graph() {}
