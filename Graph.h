#ifndef GRAPH_H
#define GRAPH_H
#include <list>
#include <map>
using namespace std;

class Graph
{
public:
	Graph(int vertices);
	void addEdge(int vertex, int adjacentVertex, int weight);
	/*void BFT(int start);
	void DFT(int start);
	bool isCyclic();*/
	//void dijkstra(int src);
	int minDistance(int dist[], bool pathFound[]);
	void printSolution(int distance[]);
	bool BellmanFord(int start);

	void BFTRecursive(int vertex, bool* visited);
	bool isStronglyConnected();
	bool isWeaklyConnected();
	int largestWeaklyConnectedSubGraph();
	int largestStronglyConnectedSubGraph();

private:
	/*void DFT(int vertex, bool visited[]);
	bool isCyclic(int vertex, bool visited[], bool recursionStack[]);*/
	int numVertices;
	//int** adjacents;
	list<pair<int,int>>* adjacents;
};
#endif // !GRAPH_H