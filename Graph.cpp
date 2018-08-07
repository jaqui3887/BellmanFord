

#include <iostream>
#include "Graph.h"


Graph::Graph(int vertices)
{
	numVertices = vertices;
	//adjacents = new int*[numVertices];
	adjacents = new list<pair<int,int>>[numVertices];
	//for (int i = 0; i < numVertices; i++)
	//{
	//	adjacents[i] = new int[numVertices];
	//	for (int j = 0; j < numVertices; j++)
	//	{
	//		adjacents[i][j] = 0;
	//	}
	//}
}

void Graph::addEdge(int vertex, int adjacentVertex, int weight)
{
	//adjacents[vertex][adjacentVertex] = weight;
	//adjacents[adjacentVertex][vertex] = weight;
	adjacents[vertex].push_back(pair<int,int> (adjacentVertex,weight));
	//adjacents[adjacentVertex].push_back(pair<int,int>(vertex,weight));
}

//void Graph::dijkstra(int src)
//{
//	int* distance = new int[numVertices];
//	bool* pathFound = new bool[numVertices];
//
//	for (int i = 0; i < numVertices; i++)
//	{
//		distance[i] = INT_MAX;
//		pathFound[i] = false;
//	}
//
//	distance[src] = 0;
//	{
//		for (int count = 0; count < numVertices - 1; count++)
//		{
//			int nextIndex = minDistance(distance, pathFound);
//			pathFound[nextIndex] = true;
//
//			for (int vertex = 0; vertex < numVertices; vertex++)
//			{
//				if (!pathFound[vertex] && adjacents[nextIndex][vertex] >0
//					&& distance[nextIndex] != INT_MAX
//					&& distance[nextIndex] + adjacents[nextIndex][vertex] < distance[vertex])
//				{
//					distance[vertex] = distance[nextIndex] + adjacents[nextIndex][vertex];
//				}
//			}
//		}
//	}
//	printSolution(distance);
//}

int Graph::minDistance(int dist[], bool pathFound[])
{
	int min = INT_MAX, minIndex;
	for (int vertex = 0; vertex < numVertices; vertex++)
	{
		if (pathFound[vertex] == false && dist[vertex] <= min)
		{
			min = dist[vertex];
			minIndex = vertex;
		}
	}
	return minIndex;
}

void Graph::printSolution(int distance[])
{
	cout << "Vertex \tDistance from Source" << endl;
	for (int i = 0; i < numVertices; i++)
	{
		cout << i << "\t" << distance[i] << endl;
	}
}
/*
bool Graph::BellmanFord(int start)
{
	int* distance = new int[numVertices];
	int* predecessor = new int[numVertices];
	for (int i = 0; i < numVertices; i++)
	{
		distance[i] = INT_MAX;
		predecessor[i] = 0;
	}

	distance[start] = 0;
	for (int count = 0; count < numVertices; count++)
	{
		for (int currVertex = 0; currVertex < numVertices; currVertex++)
		{
			for (auto adjacentVertex : adjacents[currVertex])
			{
				int edgeWeight = adjacentVertex.second;
				int alternativePathDistance = distance[currVertex] + edgeWeight;
				if (alternativePathDistance < distance[adjacentVertex.first])
				{
					distance[adjacentVertex.first] = alternativePathDistance;
					predecessor[adjacentVertex.first]=currVertex;
				}
			}
		}
	}

	for (int i = 0; i < numVertices; i++)
	{
		cout << "Distance " << i << ": " << distance[i] << endl;
		cout << "Predecessor " << i << ": " << predecessor[i] << endl <<endl;
	}
	for (int currVertex = 0; currVertex < numVertices; currVertex++)
	{
		for (auto adjacentVertex : adjacents[currVertex])
		{
			int edgeWeight = adjacentVertex.second;
			int alternativePathDistance = distance[currVertex] + edgeWeight;
			if (alternativePathDistance < distance[adjacentVertex.first])
			{
				return true;
			}
		}
	}
	return false;
}
*/
//void Graph::BFT(int start)
//{
//	//keep track of visited vertices
//	bool* visited = new bool[numVertices];
//	for (int i = 0; i < numVertices; i++)
//	{
//		visited[i] = false;
//	}
//	//visit start, print start & mark it as visited
//	list <int> queue;
//	queue.push_back(start);
//	visited[start] = true;
//
//	//visit adjacents, print if not visited, mark as visited
//	int current;
//	while (!queue.empty())
//	{
//		current = queue.front();
//		cout << current << " ";
//		queue.pop_front();
//	/*	for (int i = 0; i < numVertices; i++)
//		{
//			if (adjacents[current][i] != 0 && !visited[i])
//			{
//				queue.push_back(i);
//				visited[i] = true;
//			}
//		}*/
//		for (auto vertex : adjacents[current])
//		{
//			if (!visited[vertex])
//			{
//				queue.push_back(vertex);
//				visited[vertex] = true;
//			}
//		}
//
//	}
//}
//
//void Graph::DFT(int start)
//{
//	//keep track of visited vertices
//	bool* visited = new bool[numVertices];
//	for (int i = 0; i < numVertices; i++)
//	{
//		visited[i] = false;
//	}
//	DFT(start, visited);
//}
//
//bool Graph::isCyclic()
//{
//	bool* visited = new bool[numVertices];
//	bool* recursionStack = new bool[numVertices];
//	for (int i = 0; i < numVertices; i++)
//	{
//		visited[i] = false;
//		recursionStack[i] = false;
//	}
//	for (int i = 0; i < numVertices; i++)
//	{
//		if (isCyclic(i, visited, recursionStack))
//		{
//			return true;
//		}
//	}
//	return false;
//}
//
//void Graph::DFT(int vertex, bool visited[])
//{
//	visited[vertex] = true;
//	cout << vertex << " ";
//
//	for (auto adjVertex : adjacents[vertex])
//	{
//		if (!visited[adjVertex])
//		{
//			DFT(adjVertex, visited);
//		}
//	}
//
//}
//
//bool Graph::isCyclic(int vertex, bool visited[], bool recursionStack[])
//{
//	if (visited[vertex] == false)
//	{
//		visited[vertex] = true;
//		recursionStack[vertex] = true;
//
//		for (auto adjVertex : adjacents[vertex])
//		{
//			if (!visited[adjVertex] && isCyclic(adjVertex, visited, recursionStack))
//			{
//				return true;
//			}
//			else if (recursionStack[adjVertex])
//			{
//				return true;
//			}
//		}
//	}
//	recursionStack[vertex] = false;
//	return false;
//}

void Graph::BFTRecursive(int vertex, bool* visited){

	visited[vertex] = true;

	list<pair<int,int>>::iterator i;
	for(i = adjacents[vertex].begin(); i != adjacents[vertex].end() ; i++){
		if(visited[(*i).first] == false)
			BFTRecursive((*i).first, visited);
	}
}

bool Graph::isStronglyConnected(){
	
	bool* visited = new bool[numVertices];
	
	for(int i = 0; i < numVertices ; i++){

		for(int j = 0; j < numVertices ; j++)
			visited[j] = false;

		BFTRecursive(i, visited);

		for(int j = 0 ; j < numVertices; j++)
			if(!visited[j]){
				delete[] visited;
				return false;
			}
	}
	
	delete[] visited;
	return true;
}

bool Graph::isWeaklyConnected(){

	Graph* graph = new Graph(numVertices);

	for(int i = 0 ; i < numVertices; i++)
	{
		list<pair<int, int>> l = adjacents[i];
		list<pair<int,int>>::iterator iter;
		for(iter = l.begin(); iter != l.end(); iter++){
			graph->addEdge(i, (*iter).first, (*iter).second);
			graph->addEdge((*iter).first, i, (*iter).second);
		}
	}

	bool ret = graph->isStronglyConnected();
	delete graph;
	return ret;
}

int Graph::largestWeaklyConnectedSubGraph(){
	
	Graph* graph = new Graph(numVertices);

	for(int i = 0 ; i < numVertices; i++)
	{
		list<pair<int, int>> l = adjacents[i];
		list<pair<int,int>>::iterator iter;
		for(iter = l.begin(); iter != l.end(); iter++){
			graph->addEdge(i, (*iter).first, (*iter).second);
			graph->addEdge((*iter).first, i, (*iter).second);
		}
	}

	int ret = graph->largestStronglyConnectedSubGraph();
	delete graph;
	return ret;
}

int Graph::largestStronglyConnectedSubGraph(){
	
	bool* visited = new bool[numVertices];
	bool* visitedVertices = new bool[numVertices];
	int max = 0;

	for(int j = 0; j < numVertices ; j++)
		visitedVertices[j] = false;
	
	for(int i = 0; i < numVertices ; i++){

		if(visitedVertices[i])
			continue;

		for(int j = 0; j < numVertices ; j++)
			visited[j] = false;

		BFTRecursive(i, visited);

		int count = 0;
		for(int j = 0 ; j < numVertices; j++)
			if(visited[j]){
				visitedVertices[j] = true;
				count++;
			}

		if(count > max)
			max = count;
	}

	delete[] visited;
	delete[] visitedVertices;
	
	return max;
}