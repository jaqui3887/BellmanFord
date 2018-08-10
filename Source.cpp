


#include <iostream>
#include "Graph.h"

using namespace std;

int main()
{
	const int NUM_VERTICES = 23;
	Graph graph(NUM_VERTICES);
	graph.addEdge(0, 0, 4);
	graph.addEdge(0, 7, 8);
	graph.addEdge(1, 7, 11);
	graph.addEdge(1, 2, 8);
	graph.addEdge(7, 8, 7);
	graph.addEdge(7, 6, -20);
	graph.addEdge(2, 8, 2);
	graph.addEdge(2, 5, 4);
	graph.addEdge(2, 3, 7);
	graph.addEdge(8, 6, 6);
	graph.addEdge(6, 5, 2);
	graph.addEdge(3, 4, 9);
	graph.addEdge(3, 5, 14);
	graph.addEdge(5, 4, 10);

	graph.addEdge(10, 11, 10);
	graph.addEdge(11, 12, 10);
	graph.addEdge(12, 13, 10);
	graph.addEdge(14, 15, 10);
	graph.addEdge(16, 17, 10);
	graph.addEdge(17, 18, 10);
	graph.addEdge(18, 19, 10);
	graph.addEdge(19, 20, 10);
	graph.addEdge(20, 21, 10);
	graph.addEdge(21, 22, 10);
	graph.addEdge(10, 22, 10);

	cout << "Strongly: " << graph.isStronglyConnected() << endl;
	cout << "Weakly: "   << graph.isWeaklyConnected() << endl;
	cout << "Weakly connected max number: " << graph.largestWeaklyConnectedSubGraph() << endl;
	cout << "Strongly connected max number: " << graph.largestStronglyConnectedSubGraph() << endl;


	/*if (graph.BellmanFord(0))
	{
		cout << "Has a negative weight cycle." << endl;
	}
	else
	{
		cout << "DOES NOT have a negative weight cycle." << endl;
	}*/
	//graph.dijkstra(0);
	//graph.addEdge(0, 2);
	//graph.addEdge(0, 1);
	////graph.addEdge(2, 0);
	//graph.addEdge(2, 3);
	////graph.addEdge(3, 3);
	////graph.addEdge(3, 0);

	///*cout << "Where do you want the transversal to start (0 through " << NUM_VERTICES << "): ";
	//int start;
	//cin >> start;
	//graph.BFT(start);*/
	//if (graph.isCyclic())
	//{
	//	cout << "The graph is cyclic" << endl;
	//}
	//else
	//{
	//	cout << "The graph is acyclic" << endl;
	//}
	system("PAUSE");
	return 0;
}