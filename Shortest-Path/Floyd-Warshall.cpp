/*  Test Case

5 9
0 1 3
0 2 8
0 4 -4
1 3 1
1 4 7 
2 1 4
3 0 2
3 2 -5
4 3 6

*/

/* Complexity 

O( V^3 )

*/

#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

void FloyedWarshall( vector<vector<int>> graph , int V );

int main() {
    int V;
    cin >> V;

    int E;
    cin >> E;

    vector<vector<int>> graph (V , vector<int>(V,INT_MAX) );
    
    int u , v , w;
    for(int i=0 ; i < E ; i++) {
        cin >> u >> v >> w;
        graph[u][v] = w;
    }

    for (int i = 0 ; i < V ; i++) 
           graph[i][i] = 0;
    cout << "\nGraph\n\n";
    for (int i = 0; i < V; i++) 
    {
        for (int j = 0; j < V; j++) 
            if (graph[i][j] == INT_MAX) 
                cout<<"I"<<" "; 
            else
                cout<< graph[i][j]<<" "; 
        cout << endl;
    }

    cout << "\nSolution\n\n";
    FloyedWarshall( graph , V );

    return 0;
}


void FloyedWarshall(vector<vector<int>> graph , int V ) { 

    // W ( D0 ) 
    vector<vector<int>> Distance (V , vector<int>(V,0) );

    int i , j , k;
    for (int i = 0 ; i < V ; i++) 
        for (int j = 0 ; j < V ; j++) 
           Distance[i][j] = graph[i][j];

    for ( k = 0; k < V; k++)
    {
        for ( i = 0; i < V; i++)
            for ( j = 0; j < V; j++)
            {
                if( Distance[i][k] != INT_MAX && Distance[k][j] != INT_MAX && 
                    Distance[i][k] + Distance[k][j] < Distance[i][j]) 
                    Distance[i][j] = Distance[i][k] + Distance[k][j]; 
            
            }
    }

    for (int i = 0; i < V; i++) 
    {
        for (int j = 0; j < V; j++) 
            if (Distance[i][j] == INT_MAX) 
                cout<<"INF"<<"     "; 
            else
                cout<< Distance[i][j]<<"     "; 

        cout<<endl;  
    }   
}
