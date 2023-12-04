#include <stdio.h>
#define MAX 100

/* If you want to improve the time complexity, you can use more advanced data structures and algorithms.
For example, you can use a Depth-First Search (DFS) with backtracking and a visited array to store the path information.
This approach has a time complexity of O(V+E) where V is the number of vertices and E is the number of edges.*/




int n;    // Number of vertices
int adj[MAX][MAX]; // Adjacency Matrix
int visited[MAX];  // Visited array

void create_graph();
void DFS(int v);

int main()
{
    create_graph();

    for(int i=0; i<n; i++)
        visited[i] = 0;

    printf("Enter start vertex for Depth First Search: ");
    int v;
    scanf("%d", &v);
    DFS(v);

    return 0;
}

void DFS(int v)
{
    printf("%d ", v);
    visited[v] = 1;

    for(int i=0; i<n; i++)
    {
        if(adj[v][i] == 1 && visited[i] == 0)
        {
            DFS(i);
        }
    }
}

void create_graph()
{
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix of the graph:\n");
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d", &adj[i][j]);
}
/*This code performs a DFS on the graph and prints the vertices in the order they are visited.
The visited array is used to keep track of whether a vertex has been visited or not.
This approach is much more efficient than the Hamiltonian cycle approach for large graphs.
However, it doesn’t guarantee to find a solution if it exists.
It only explores as much of the graph as possible from the given start vertex.
If you want to explore the entire graph, you can run the DFS from all vertices one by one (like a loop).*/

