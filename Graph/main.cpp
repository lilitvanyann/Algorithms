#include "graph.h"
int main()
{
	graph g(11);
	g.addEdge(8, 2);
	g.addEdge(8, 5);
	g.addEdge(8, 7);
	g.addEdge(7, 2);
	g.addEdge(7, 5);
	g.addEdge(6, 5);
	g.addEdge(5, 2);
	g.addEdge(9, 3);
	g.addEdge(1, 4);
	g.addEdge(1, 2);
	g.addEdge(4, 3);
	g.addEdge(2, 3);
	g.addEdge(3, 10);

	g.printGraph();
}
