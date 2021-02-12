/*

Complexity

Pre Processing -> Finding Symbols S
               -> Table m

Algo -> O(n)

Test Case

abababacaba
ababaca

*/

#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> Compute_Transition(string patern , vector<char> symbols);

int main() {
    string text , patern;
    cout << "Enter Text: ";
    cin >> text;
    cout << endl;

    cout << "Enter Patern: ";
    cin >> patern;
    cout << endl;

    set<char> symbols;
    for (int i = 0; i < text.size(); i++)
    {
        symbols.insert( text[i] );
    }

    vector<char> symbols_vec;
    for(auto it= symbols.begin() ; it != symbols.end() ; it++) {
        symbols_vec.push_back(*it);
    }

    vector<int> Table = Compute_Transition( patern , symbols_vec );      

    int n = text.size() , m = patern.size() ;
    
    int k = 0;
    for (int i=0 ; i < n ; i++)
    {
        while(k > 0 && text[i] != patern[k])
            k = Table[k];

        if(text[i] == patern[k])
            k++;

        if( k == m )
        {
            cout << "Patern found at position " << i-m+1 << endl;   
            k = Table[k];
        }  
    }

    return 0;
}



vector<int> Compute_Transition(string patern , vector<char> symbols) {
    int m = patern.size();

    vector<int> Table( m ,  0 ) ;

    int k = 0;

    for (int state=1 ; state < m ; state++)
    {
        while(k > 0 && patern[state] != patern[k])
            k = Table[k];

        if(patern[state] == patern[k])
            k++;

        Table[state] = k;        
    }
    
    return Table;
}