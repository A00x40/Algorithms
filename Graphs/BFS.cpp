/* Test Case

4 6
0 1
0 2
1 2
2 0
2 3
3 3
2

*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void graphBFS( vector<vector<int>> graph , int V , int src ) ;

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

    int src;
    cin >> src;

    graphBFS( graph , V , src );

    return 0;
}

void graphBFS( vector<vector<int>> graph , int V , int src ) {
    vector<bool> visited ( V , false );
    queue<int> q;
    q.push(src);
    visited[src] = true;

    cout << "BFS Starting from " << src << endl;
    while (!q.empty()) 
    { 
        int i = q.front(); 
        q.pop(); 

        cout << i << " ";

        for (int j = 0; j < V; j++)
            if ( !visited[j] && graph[i][j]==1 )
            {
                visited[j] = true;
                q.push(j);
            }
    } 
}