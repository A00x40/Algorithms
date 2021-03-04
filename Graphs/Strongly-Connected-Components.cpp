/* Test Case

5 5
0 2
0 3
1 0
2 1
3 4


*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void fillOrder( vector<vector<int>> graph , int V , int idx , vector<bool>& visited , stack<int>& s) ;
vector<vector<int>> getTranspose( vector<vector<int>> g , int V) ;
void DFS_Util( vector<vector<int>> graph , int V , int idx , vector<bool>& visited ) ;
void SCC( vector<vector<int>> graph , int V ) ;

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

    SCC( graph , V );

    return 0;
}

void fillOrder( vector<vector<int>> graph , int V , int idx , vector<bool>& visited , stack<int>& s) {
    visited[idx] = true; 

    for(int i=0 ; i < V ; i++) 
        if( !visited[i] && graph[idx][i] == 1 ) 
            fillOrder(graph , V , i, visited, s); 
   
    s.push(idx); 
}

vector<vector<int>> getTranspose( vector<vector<int>> g , int V) { 
    vector<vector<int>> gTranspose(V , vector<int>(V,0) ); 
    for (int u = 0 ; u < V ; u++)  
        for(int v = 0 ; v < V ; v++) 
            if( g[u][v] == 1 ) gTranspose[v][u] = 1;
    return gTranspose; 
} 
  
void DFS_Util( vector<vector<int>> graph , int V , int idx , vector<bool>& visited ) {
    visited[idx] = true; 

    cout << idx << " ";

    for(int i=0 ; i < V ; i++) 
        if( visited[i] == false && graph[idx][i] == 1 ) 
            DFS_Util(graph , V , i, visited); 
}

void SCC( vector<vector<int>> graph , int V ) {
    vector<bool> visited(V,false);

    stack<int> S;

    for (int i = 0; i < V; i++)
        if( !visited[i] ) fillOrder( graph , V , i , visited , S);
    
    vector<vector<int>> gTranspose = getTranspose( graph , V );
    for (int i = 0; i < V; i++) visited[i] = false;

    while ( !S.empty() )
    {
        int idx = S.top(); 
        S.pop();

        if (visited[idx] == false) 
        { 
            DFS_Util(gTranspose , V ,  idx , visited); 
            cout << endl; 
        } 
    } 
}