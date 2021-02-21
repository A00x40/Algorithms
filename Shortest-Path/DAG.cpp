/*  Test Case

6 10
0 1 5
0 2 3
1 2 2
1 3 6
2 3 7
2 4 4 
2 5 2
3 4 -1
3 5 1
4 5 -2
1

*/

/* Complexity

O( V + E ) 
Worst Case: E = V^2 -> O(V^2)

*/

#include <iostream>
#include <limits.h>
#include <vector>
#include <stack>

using namespace std;

class adjList
{
    int v , w;
    public:
    adjList(int v , int w){this->v = v ; this->w = w;}
    int getV(){return this->v;}
    int getW() {return this->w;}
};

class Graph { 
    
    int V, E; 
    vector<adjList>* adj;

    public:
    Graph( int V );

    void addEdge( int u , int v , int w );
  
    void TpSortUtil( int vertex , vector<bool>& visited , stack<int>& s ) ;

    void DAG_shortestPath( int src );
};

void printGraph( vector<int> Distance );

int main() {
    int V;
    cin >> V;

    int e;
    cin >> e;

    Graph* graph = new Graph(V);
    
    int u , v , w;
    for(int i=0 ; i < e ; i++) {
        cin >> u >> v >> w;
        graph->addEdge( u , v , w );
    }

    int src;
    cin >> src;

    graph->DAG_shortestPath( src );

    return 0;
}

void printGraph( vector<int> Distance ) {
    cout << "N D" << endl;
    for (int i = 0; i < Distance.size(); i++)
        cout << i << " " << Distance[i] << endl;
}

Graph::Graph(int V ) {
    this->V = V;
    this->adj = new vector<adjList>[V];
}

void Graph::addEdge( int u , int v , int w ) {
    adjList vertex(v , w);
    this->adj[u].push_back(vertex);
}

void Graph:: TpSortUtil( int vertex , vector<bool>& visited , stack<int>& s ) {
    visited[vertex] = true;

    for ( auto i = this->adj[vertex].begin() ; i != this->adj[vertex].end() ; i++)
        if( !visited[i->getV()] )
            TpSortUtil(  i->getV() , visited , s ); 
    s.push(vertex);
}

void Graph::DAG_shortestPath( int src ) {

    stack<int> s;
    vector<bool> visited(V,false);

    for (int i = 0; i < V; i++)
        if(!visited[i]) this->TpSortUtil(i,visited,s);
    
    // Initialize_Src
    vector<int> Distance(this->V,INT_MAX);
    Distance[ src ] = 0;

    while ( !s.empty() )
    {
        int u = s.top();
        s.pop();

        if( Distance[u] != INT_MAX)
            for ( auto i = this->adj[u].begin() ; i != this->adj[u].end() ; i++)
            {
                int v = i->getV();
                int weight = i->getW();
                if ( Distance[v] > Distance[u] + weight ) 
                { 
                    Distance[v] = Distance[u] + weight ;
                }
            }
        
    }
    
    cout << endl;
    printGraph( Distance );
}
