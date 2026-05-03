#pragma once
#include <iostream>
#include <vector>
class graph
{
private:
	std::vector<std::vector<int>> adj;
	int n;
public:
	graph(int n);
	void addEdge(int u, int v);
	void printGraph();
	~graph();
	int getSize();
	const std::vector<std::vector<int>>& getAdj() const;
};

