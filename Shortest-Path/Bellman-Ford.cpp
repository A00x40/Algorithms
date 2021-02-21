/*  Test Case

5 10
0 1 6
0 2 7
1 2 8
1 3 5
1 4 -4
2 3 -3
2 4 9
3 1 -2
4 0 2
4 3 7
0

*/

/* Complexity

O( V^E ) 
Worst Case: E = V^2 -> O(V^3)

*/

#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

// a structure to represent a weighted edge in graph 
struct Edge { 
    int src, dest, weight; 
}; 

// a structure to represent a connected, directed and 
// weighted graph 
struct Graph { 
    // V-> Number of vertices, E-> Number of edges 
    int V, E; 
  
    // graph is represented as an array of edges. 
    struct Edge* edge; 
};


void printGraph( vector<int> Distance , vector<int> Parent );
void BellmanFord( Graph* graph , int src );

int main() {
    int V;
    cin >> V;

    int e;
    cin >> e;

    Graph* graph = new Graph;
    graph->V = V;
    graph->E = e;
    graph->edge = new Edge[e];

    int u , v , w;
    for(int i=0 ; i < e ; i++) {
        cin >> u >> v >> w;
        graph->edge[i].src = u;
        graph->edge[i].dest = v;
        graph->edge[i].weight = w;
    }

    int src;
    cin >> src;

    BellmanFord( graph , src );

    return 0;
}

void printGraph( vector<int> Distance , vector<int> Parent ) {
    cout << "P N D" << endl;
    for (int i = 1; i < Parent.size(); i++)
        cout << Parent[i] << " " << i << " " << Distance[i] << endl;
}

void BellmanFord( Graph* graph , int src ) {

    // Initialize_Src
    vector<int> Distance(graph->V,INT_MAX);
    vector<int> Parent(graph->V,-1);
    Distance[0] = 0;
    
    for (int i = 1; i <= graph->V-1; i++)
    {
        for (int j = 0; j < graph->E; j++)
        {
            int u = graph->edge[j].src; 
            int v = graph->edge[j].dest; 
            int weight = graph->edge[j].weight; 

            // Relax
            if( Distance[u] != INT_MAX && ( Distance[v] > Distance[u] + weight ) )
            { 
                Distance[v] = Distance[u] + graph->edge[j].weight ;
                Parent[v] = u;
            }
        }
    }
    
    for (int i = 0; i < graph->E; i++) { 
        int u = graph->edge[i].src; 
        int v = graph->edge[i].dest; 
        int weight = graph->edge[i].weight; 
        if ( Distance[u] != INT_MAX && Distance[v] > Distance[u] + weight ) { 
            cout << "\nGraph contains negative weight cycle\n"; 
            return;
        }
    }

    cout << endl;
    printGraph( Distance , Parent );
}
