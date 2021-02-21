// Condition  Directed Acyclic Graph (DAG)

/* Test Case

6 6
2 3
3 1
4 0
4 1
5 0
5 2

*/

// Complexity O( V + E )

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void TpSortUtil( vector<vector<int>> graph , int vertex , int V , vector<bool>& visited , stack<int>& s );
void Topological_Sort( vector<vector<int>> graph , int V );

int main() {
    int V ;
    cin >> V;

    vector<vector<int>> graph ( V , vector<int> (V, 0) ) ;

    int e ;
    cin >> e;

    int u , v ;
    for(int i=0 ; i < e ; i++) {
        cin >> u >> v ;
        graph[u][v] = 1;
    }

    stack<int> s;

    Topological_Sort( graph , V );

    return 0;
}

void TpSortUtil( vector<vector<int>> graph , int vertex , int V , vector<bool>& visited , stack<int>& s ) {
    visited[vertex] = true;

    for (int i = 0; i < V; i++)
        if( !visited[i] && graph[vertex][i] == 1 )
            TpSortUtil( graph , i , V , visited , s); 
    s.push(vertex);
}

void Topological_Sort( vector<vector<int>> graph , int V ) {
    stack<int> s;

    vector<bool> visited ( V , false );

    for (int i = 0; i < V; i++)
        if( !visited[i] )
            TpSortUtil( graph , i , V , visited , s );

    while ( !s.empty() )
    {
        cout << s.top() << " "; 
        s.pop(); 
    }
}