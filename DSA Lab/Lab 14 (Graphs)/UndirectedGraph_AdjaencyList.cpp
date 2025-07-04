#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

class GraphList
{
private:
    int vertices;
    vector<vector<int>> adjList;

public:
    GraphList(int vertex)
    {
        vertices = vertex;
        adjList.resize(vertex);
    }

    void Add_Edge(int u, int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void Display_List()
    {
        for (int i = 0; i < vertices; i++)
        {
            cout << i << " : [";
            for (int j = 0; j < adjList[i].size(); j++)
            {
                cout << adjList[i][j];
                if (j != adjList[i].size() - 1)
                {
                    cout << " , ";
                }
            }
            cout << "]\n";
        }
        cout << endl;
    }

    void Remove_Edge(int u, int v)
    {
        vector<int> &edges_u = adjList[u];
        edges_u.erase(remove(edges_u.begin(), edges_u.end(), v), edges_u.end());

        vector<int> &edges_v = adjList[v];
        edges_v.erase(remove(edges_v.begin(), edges_v.end(), u), edges_v.end());
    }

    void BFS_Traversal(int starting_node)
    {
        queue<int> q;
        vector<bool> visited(vertices, false);
        vector<int> answer;

        q.push(starting_node);
        visited[starting_node] = true;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            answer.push_back(node);

            for (int i = 0; i < adjList[node].size(); i++)
            {
                int neighbor = adjList[node][i];
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        // Print BFS traversal result
        cout << "The BFS traversal of this graph is: ";
        for (int i = 0; i < answer.size(); i++)
        {
            cout << answer[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int vertices;

    cout << "Enter the vertices of the graph: ";
    cin >> vertices;

    GraphList g(vertices);

    // Adding edges to the graph
    g.Add_Edge(0, 1);
    g.Add_Edge(0, 2);
    g.Add_Edge(1, 2);
    g.Add_Edge(1, 7);
    g.Add_Edge(2, 3);
    g.Add_Edge(3, 4);
    g.Add_Edge(4, 9);

    // Display the adjacency list
    g.Display_List();

    // Perform BFS traversal starting from node 0
    g.BFS_Traversal(0);

    return 0;
}