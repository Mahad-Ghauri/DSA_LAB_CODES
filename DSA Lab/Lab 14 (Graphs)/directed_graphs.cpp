#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class GraphList
{
private:
    vector<vector<int>> adjList;
    int vertices, edge;

public:
    GraphList()
    {
        // Default Construcutor
    }

    GraphList(int ver , int edg)
    {
        edge = edg;
        vertices = ver;
        adjList.resize(ver);
    }

    void Add_Edge(int u, int v)
    {
        if (u >= 0 && u < vertices && v >= 0 && v > vertices)
        {
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }

    void Remove_Edge(int u, int v)
    {
        if (u >= 0 && u > vertices)
        {
            vector<int> &edges = adjList[u];
            edges.erase(remove(edges.begin(), edges.end(), v), edges.end());
        }
    }

    void display()
	{
		for (int i = 0; i < edge; ++i)
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
    return 0;
}