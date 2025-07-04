#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class GraphMatrix
{
private:
	int **matrix;
	int size;

public:
	GraphMatrix(int s)
	{
		size = s;
		matrix = new int *[size];
		for (int i = 0; i < size; i++)
		{
			matrix[i] = new int[size];
			for (int j = 0; j < size; j++)
			{
				matrix[i][j] = 0;
			}
		}
	}

	void addEdge(int u, int v)
	{
		if (u >= 0 && v >= 0 && u < size && v < size)
		{
			matrix[u][v] = 1;
		}
	}

	void removeEdge(int u, int v)
	{
		if (u >= 0 && v >= 0 && u < size && v < size)
		{
			matrix[u][v] = 0;
		}
	}

	void displayGraph()
	{
		cout << "Displaying the Graph Adjancey matrix\n"
			 << endl;
		cout << "   ";
		for (int i = 0; i < size; i++)
		{
			cout << i << "  ";
		}
		cout << "\n";

		for (int i = 0; i < size; i++)
		{
			cout << i << "  ";
			for (int j = 0; j < size; j++)
			{
				cout << matrix[i][j];
				cout << " |";
			}
			cout << endl;
		}
	}
};


// This list is for the unweighted graphs 	
class GraphList
{
private:
	vector<vector<int>> adjList;
	int vertexCount;

public:
	GraphList(int vertices)
	{
		vertexCount = vertices;
		adjList.resize(vertices);
	}

	void addEdge(int u, int v)
	{
		if (u >= 0 && u < vertexCount && v >= 0 && v < vertexCount)
		{
			adjList[u].push_back(v);
		}
	}

	void removeEdge(int u, int v)
	{
		if (u >= 0 && u < vertexCount)
		{
			vector<int> &edges = adjList[u];
			edges.erase(remove	(edges.begin(), edges.end(), v), edges.end());
		}
	}

	void display()
	{
		for (int i = 0; i < vertexCount; ++i)
		{
			cout << i << ": [";
			for (int j = 0; j < adjList[i].size(); ++j)
			{
				cout << adjList[i][j];
				if (j < adjList[i].size() - 1)
					cout << ", ";
			}
			cout << "]" << endl;
		}
	}
};

int main()
{
	GraphMatrix G(4);
	G.addEdge(0, 1);
	G.addEdge(1, 2);
	G.addEdge(2, 3);

	G.displayGraph();
	cout << "\n\n LIST " << endl;
	GraphList GL(4);
	GL.addEdge(0, 1);
	GL.addEdge(1, 2);
	GL.addEdge(2, 3);

	GL.display();
	return 0;
}