/* Test Case

6 10
0 5
0 1 16
0 2 13
1 2 10
1 3 12
2 1 4
2 4 14
3 2 9
3 5 20
4 3 7
4 5 4

ans = 23

*/

#include <iostream>
#include <limits.h> 
#include <vector>
#include <queue>

using namespace std;

void print(vector<vector<int>> graph , int V);
bool bfs(vector<vector<int>> rGraph , int s , int t , int pathParent[] );
int FordFulkerson(vector<vector<int>> graph , int s , int t , int V);

int main() {
    int V ;
    cin >> V;

    vector<vector<int>> graph ( V , vector<int> (V, 0) ) ;

    int e ;
    cin >> e;

    int s , t;
    cin >> s >> t;

    int u , v , f;
    for(int i=0 ; i < e ; i++) {
        cin >> u >> v >> f;
        graph[u][v] = f;
    }

    //print(graph , V);
    
    cout << endl << "The maximum possible flow is " << FordFulkerson(graph, s, t , V); 

    return 0;
}

void print(vector<vector<int>> graph , int V) {
    cout << endl;
    for(int i=0 ; i < V ; i++) {
        for(int j=0 ; j < V ; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
};

bool bfs(vector<vector<int>> rGraph , int s , int t , int Parent[] , int V) {

    vector<bool> visited (V,0); 

    queue<int> q;
    q.push(s);
    visited[s] = 1;
    Parent[s] = -1;

    while (!q.empty()) 
    { 
        int i = q.front(); 
        q.pop(); 
  
        for (int j=0; j<V; j++) 
        { 
            if (visited[j]==false && rGraph[i][j] > 0) 
            { 
                q.push(j); 
                Parent[j] = i; 
                visited[j] = true; 
            } 
        }
    } 

    return ( visited[t] == 1) ;
}

int FordFulkerson(vector<vector<int>> graph , int s , int t , int V) {
    int i , j ;

    vector<vector<int>> rGraph (V , vector<int> (V, 0) );

    for(i=0 ; i < V ; i++) 
        for(j=0 ; j < V ; j++) 
            rGraph[i][j] = graph[i][j];
        
    int* parent = new int[V];
    int max_flow = 0;
    
    while( bfs(rGraph , s , t , parent , V) ) 
    {
        int minPath_flow = INT_MAX;
    
        for(j=t ; j != s ; j=parent[j]) 
        {
            i = parent[j];
            minPath_flow = min( minPath_flow , rGraph[i][j] );
        }

        for (j=t; j != s; j=parent[j]) 
        { 
            i = parent[j]; 
            rGraph[i][j] -= minPath_flow; 
            rGraph[j][i] += minPath_flow; 
        } 

        max_flow += minPath_flow;
    }
    
    return max_flow;
};