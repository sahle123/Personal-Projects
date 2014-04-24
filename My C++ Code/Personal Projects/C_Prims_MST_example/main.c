/*
*    Http://www.geeksforgeeks.org/greedy-algorithms-set-5-prims-minimum-spanning-tree-mst-2/
*    Date: May 3rd, 2013
*
*    A C / C++ program for Prim's Minimum Spanning Tree (MST) algorithm.
*    The program is for adjacency matrix representation.
*
*   Time Complexity = O(v^2)
*
*   CODE WILL NOT COMPILE PROPERLY. NEEDS TO BE CHECKED
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* Number of verticies in the graph */
const unsigned int V = 5;

/* A utility function to find the vertex with minimum key value, from the set
    of verticies not yet included in MST. */
int minKey(int key[], bool mstSet[]);

// A utility function to print the constructed MST stored in parent[].
int printMST(int parent[], int n, int graph[5][5]);

// Function to construct and print MST for a graph represented using adjacency
// matrix representation.
void primMST(int graph[5][5]);

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

int main()
{
          /* Let us create the following graph.
                2     3
           (0)--(1)---(2)
            |    /   \    |
          6|  8/     \5 |7
            | /         \ |
            (3)-------(4)
                    9          */

                                    // Vertex: 0, 1, 2, 3, 4 and all their edges
        int graph[5][5] = {{0, 2, 0, 6, 0},
                                      {2, 0, 3, 8, 5},
                                      {0, 3, 0, 0, 7},
                                      {6, 8, 0, 0, 9},
                                      {0, 5, 7, 9, 0}
                                      };

        // Print solution
        primMST(graph);

        return 0;
}

//----------------------------------------------------------------------------

int minKey(int key[], bool mstSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index; // <--- Not sure what is meant by here.
    int v = 0;

    for(v = 0; v < V; ++v)
    {
        if(mstSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

        return min_index;
    }
}

int printMST(int parent[], int n, int graph[5][5])
{
    printf("Edge   Weight\n");
    for(int i = 1; i < V; ++i)
        printf("%d  - %d    %d \n", parent[i], i, graph[i][parent[i]]);
}

void primMST(int graph[5][5])
{
    int parent[V];     // Array to store constructed MST.
    int key[V];          // Key values used to pick minimum weight edge in cut
    bool mstSet[V];   // To represent set of vertices not yet included in MST.

    // Initialize all keys as INFINITE
    for(int i = 0; i < V; ++i)
        key[i] = INT_MAX, mstSet[i] = false;

    // Always include first 1st vertex in MST.
    key[0] = 0;       // Make key 0 so that this vertex is picked as first vertex.
    parent[0] = -1; // First node is always root of MST

    // The MST will have V vertices
    for(int count = 0; count < V-1; ++count)
    {
        // Pick the minimum key vertex from the set of vertices
        // not yet included in MST
        int u = minKey(key, mstSet);

        // Add the puced vertex to the MST set
        mstSet[u] = true;

        // Update key value parent index of the adjacent vertices of
        // the picked vertex. Consider only those vertices which are not yet
        // included in MST
        for(int v = 0; v < V; ++v)
        {
            // graph[u][v] is non zero only for adjacent vertices of m
            // mstSet[v] is false for vertices not yet included in MST
            // Update the key only if graph[u][v] is smaller than key[v]
            if(graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the constructed MST
    printMST(parent, V, graph);
}
