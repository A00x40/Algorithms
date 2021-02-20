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

*/

/* Complexity

O( V^2 ) Simple

Modification in min Key Extraction

Using Binary Heap: O( V log V + E log V ) = O(E log V)
Using Fibonacci heaps: O(E + V log V)

*/

#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

void printMST( vector<int> Parent, vector<vector<int>> graph , int V );
int minKey( vector<int> Key , int V , vector<bool> mstSet );
void MST_Prim( vector<vector<int>> graph , int V );

int main() {
    int V ;
    cin >> V;

    vector<vector<int>> graph ( V , vector<int> (V, 0) );
    vector<bool> mstSet(V, 0);

    int e ;
    cin >> e;

    int u , v , w;
    for(int i=0 ; i < e ; i++) {
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w;
    }

    MST_Prim( graph , V );

    return 0;
}

void printMST( vector<int> Parent, vector<vector<int>> graph , int V ) {
    cout << endl << "P  C  W  \n";
    for (int i = 1; i < V; i++)
    {
        cout << Parent[i] << "  " << i << "  " << graph[i][Parent[i]] << endl;
    }
}

int minKey( vector<int> Key , int V , vector<bool> mstSet) {
    int min = INT_MAX , minIdx;
    for (int i = 0; i < V; i++)
        if ( Key[i] < min && mstSet[i] == false)
            min = Key[i] , minIdx= i;

    return minIdx;
}

void MST_Prim( vector<vector<int>> graph , int V) {

    vector<bool> mstSet(V,false);
    vector<int> Key(V,INT_MAX);
    vector<int> Parent(V,-1);

    Key[0] = 0;
    Parent[0] = -1;

    for (int i = 0; i < V; i++)
    {
        int mK = minKey( Key , V , mstSet);
        mstSet[mK] = true;

        for (int j = 0; j < V; j++) 
            if( graph[mK][j] ) 
                if( mstSet[j] == false && graph[mK][j] < Key[j] )
                    Key[j] = graph[mK][j] , Parent[j] = mK;
    }

    printMST(Parent, graph , V); 
}