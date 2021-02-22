/*  Test Case

FloydWarshall
1
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

Transitive Closure
2
4 4
0 1
0 3
1 2
2 3
0 1

*/

/* Complexity 

O( V^3 )

*/

#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

void FloyedWarshall( vector<vector<int>> graph , int V );
bool TransitiveClosure( vector<vector<int>> graph , int V ,int l , int m);

int main() {
    cout << "Enter 1 for Floyd Warshall , 2 for TransitiveClosure\n";
    int algo;
    cin >> algo;

    int V;
    cin >> V;

    int E;
    cin >> E;

    int u , v , w;

    if( algo == 1 )
    {
        vector<vector<int>> graph (V , vector<int>(V,INT_MAX) );
        for(int i=0 ; i < E ; i++) {
            cin >> u >> v >> w;
            graph[u][v] = w;
        }

        for (int i = 0 ; i < V ; i++) 
            graph[i][i] = 0;

        cout << "\nFloyd Warshall Solution\n\n";
        FloyedWarshall( graph , V );
    }

    else if ( algo == 2 )
    {
        vector<vector<int>> graph (V , vector<int>(V,0) );
        for(int i=0 ; i < E ; i++) {
            cin >> u >> v ;
            graph[u][v] = 1;
        }

        cout << "\nEnter 2 Vertecies to Check Path\n";

        int l , m;
        cin >> l >> m;

        cout << "\nTransitiveClosure Solution\n\n";
        bool sol = TransitiveClosure( graph , V , l , m);
        if (sol) cout << "A Path Exists between " << l << " " << m;
        else cout << "NO Path between " << l << " " << m;;
    }

    else {
        cout << "ALgo Number isn't 1 or 2";
        exit(-1);
    }

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

bool TransitiveClosure( vector<vector<int>> graph , int V ,int l , int m) {
    vector<vector<int>> T (V , vector<int>(V,0) );

    int i , j , k;
    for (int i = 0 ; i < V ; i++) 
        for (int j = 0 ; j < V ; j++) 
            if( graph[i][j] == 1 || i == j ) T[i][j] = 1;

    for ( k = 0; k < V; k++)
        for ( i = 0; i < V; i++)
            for ( j = 0; j < V; j++)
                T[i][j] = T[i][j] || T[i][k] && T[k][j]; 

    for ( i = 0; i < V; i++)
    {
        for ( j = 0; j < V; j++)
            cout << T[i][j] << " ";
        cout << endl;
    }

    return ( T[l][m] == 1 || T[l][m] == 1);
}