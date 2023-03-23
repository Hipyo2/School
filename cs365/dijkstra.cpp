//Nicholas Ang
//CS365
//Project 1

//Libraries
#include <iostream>
#include <stdio.h>
#include <limits.h>

//Global Variable for Graph Size
#define V 8
using namespace std;

//Function Declarations
int minDistance(int dist[], bool sptSet[]);
void printPath(int prev[], int n, int src);
void dijkstra(int graph[][V], int src, int target);
void printSol(int dist[], int src, int target, int prev[]);

//Minimum Distance function - finds minimum distance and smallest distance adjacent node. 
int minDistance(int dist[], bool set[])
{
	//set variables
	int min = INT_MAX;
	int min_index;
	int i = 0;
	//Check through each node to find the smallest distance
	while(i < V)
	{
		//Checks if the node is visited or not.
		if(set[i] == false)
		{
			//If not visited and the distance is less than the current min, switch min value
			if(dist[i] <= min)
			{
			min = dist[i];
			min_index = i;
			}
		}
		i++;
	}
	//Returns index of node that is smallest distance away
	return min_index;
}

//Print Path Function - prints the path of the traversal - outputs letters of nodes, not index number of nodes
void printPath(int prev[], int n, int src)
{
	//sets up array with all letters of nodes in the graph
	char arr[] = {'a','b','c','d','e','f','g','z'};
	//If the node is the source node, output the source node
	if(prev[n] == -INT_MAX)
	{
		cout << arr[src] << " ";
		return;
	}
	//Outputs the traversal using recursion
	printPath(prev, prev[n], src);
	cout << arr[n] << " ";
}

//Print Solution - prints out the distance of the smallest path from the source node to the target node
//Also calls printPath function to output the path of the traversal
void printSol(int dist[], int src, int target, int prev[])
{
	//Array with all letters of nodes in the graph
	char arr[] = {'a','b','c','d','e','f','g','z'};

	//Output source, target, and distance from source to target
	cout << "Vertex Distance from Source" << endl;
	cout << arr[src] << " to " << arr[target] << ": " << dist[target] << endl << "PATH: ";
	
	//Calls printPath to output path
	printPath(prev, target, src);
	cout << endl;
}

//Dijkstra function - uses dijkstra's algorithm to find the shortest path
void dijkstra(int graph[][V], int src, int target)
{
	//Sets up arrays to hold distances of paths, the set of visited nodes, and the path that the traversal takes
	int dist[V];
	bool set[V];
	int prev[V];
	bool valid;
	int i = 0;
	
	//Initializes arrays with max values
	while(i<V)
	{
		prev[i] = -INT_MAX;
		dist[i] = INT_MAX; 
		set[i] = false;
		i++;
	}
	
	//The distance of the source to the source is 0
	dist[src] = 0;
	int c = 0;
	//Iterates through every path
	while(c < (V-1))
	{
		//Finds the minimum Distance - the first time it is called, u is set to 0
		int u = minDistance(dist,set);
		//Sets the first node to visited since it "traveled" to itself with a path of 0
		set[u] = true;
		int v = 0;
		//Go through the paths to every node on the graph
		while(v<= (V-1))
		{
			//Checks if there is a valid edge, the node is unvisited, and if the distance is valid
			if(!set[v] && graph[u][v] && dist[u] != INT_MAX)
			{
			valid = 1;
			}
			else
			{
			valid = 0;
			}

			if(valid == 1)
			{
				//Checks if the current path distance when adding the edge is less than the distance at the target
				if(dist[v] > dist[u] + graph[u][v])
				{
				prev[v] = u;
				dist[v] = dist[u] + graph[u][v];
				}
			}
			v++;
		}
		c++;
	}
	//Calls printSol Function to print out the shortest path from the source node to the target node
	printSol(dist, src, target, prev);
}

//Main Function
int main()
{
	//Initializes the graph from Exercise 3
	int graph[V][V] = {{0,4,3,0,0,0,0,0},{4,0,2,5,0,0,0,0},{3,2,0,3,6,0,0,0},{0,5,3,0,1,5,0,0},{0,0,6,1,0,0,5,0},{0,0,0,5,0,0,2,7},{0,0,0,0,5,2,0,4},{0,0,0,0,0,7,4,0}};
	//Array of letter nodes in graph, correspond to each row in the graph
	char arr[] = {'a','b','c','d','e','f','g','z'};
	//Input characters
	char v1, v2;
	int i1,i2;

	//Asks the user to input vertices on the graph 
	cout << "Please input a vertex on the graph" << endl;
	cin >> v1;

	cout << "Please input a second vertex on the graph" << endl;
	cin >> v2;
	//Converts the character to a index that can be used in dijkstra
	for(int i = 0; i < V; i++)
	{
		if(v1 == arr[i])
		{
			i1 = i;
		}
	}
	for(int i = 0; i < V; i++)
	{
		if(v2 == arr[i])
		{
			i2 = i;
		}
	}

	//Calls dijkstra function to get smallest path from source to target
	//Prints answer
	dijkstra(graph, i1, i2);
	return 0;
}
