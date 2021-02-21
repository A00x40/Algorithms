/*  Test Case

9 14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 5 4
2 8 2
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7
0

*/

/* Complexity Same as Prim's MST algo

O( V^2 ) Array

Modification in Representaion

Using Binary Heap: O( V log V + E log V ) = O(E log V)
Using Fibonacci heaps: O(E + V log V)

*/

#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

void printGraph( vector<int> Distance );
int minKey( vector<int> Distance , vector<bool> visited );
void Dijkstra( vector<vector<int>> graph , int V , int src );

int main() {
    int V;
    cin >> V;

    int e;
    cin >> e;

    vector<vector<int>> graph (V , vector<int>(V,0) );
    
    int u , v , w;
    for(int i=0 ; i < e ; i++) {
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w;
    }

    int src;
    cin >> src;

    Dijkstra( graph , V , src);

    return 0;
}

void printGraph( vector<int> Distance ) {
    cout << "N D" << endl;
    for (int i = 0; i < Distance.size(); i++)
        cout << i << " " << Distance[i] << endl;
}



int minKey( vector<int> distance , vector<bool> visited) {
    int min = INT_MAX , minIdx;
    for (int i = 0; i < distance.size(); i++)
        if ( distance[i] < min && !visited[i])
            min = distance[i] , minIdx= i;
    
    return minIdx;
}

void Dijkstra(vector<vector<int>> graph , int V , int src) {    
    
    vector<int> Distance(V,INT_MAX);
    vector<bool> visited(V,false);
    Distance[src] = 0;

    for (int i = 0; i < V-1; i++)
    {
        int u = minKey( Distance , visited );
        visited[u] = true;

        for ( int v = 0 ; v < V ; v++)
        {
            if( !visited[v] && Distance[u] != INT_MAX && graph[u][v] && Distance[v] > Distance[u] + graph[u][v] ) 
            { 
                Distance[v] = Distance[u] + graph[u][v] ;
            }
        }   
    }
    
    cout << endl;
    printGraph( Distance );
}
