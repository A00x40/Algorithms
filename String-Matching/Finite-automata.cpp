/*

Complexity

Pre Processing -> Finding Symbols S
               -> State Machine O(m * S)

Algo -> O(n)

Worst Case : 
    Unique Text (S = n) , Patern = Text (m = n) -> O(n^2)

Test Case

abababacaba
ababaca

*/

#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

bool isSuffix(string s1, string s2) ;
vector<vector<int>> Compute_Transition(string patern , vector<char> symbols);

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

    vector<vector<int>> State_Machine = Compute_Transition( patern , symbols_vec );
        

    int n = text.size() , m = patern.size();
    
    int q = 0;

    for (int i=0 ; i < n; i++)
    {
        q = State_Machine[q][ text[i] ];
        if( q == m )
            cout << "Patern found at position " << i-m+1 << endl;
    }
    
    return 0;
}

bool isSuffix(string s1, string s2) 
{ 
    int n1 = s1.length(), n2 = s2.length(); 
    if (n1 > n2) 
        return false; 
    for (int i=0 ; i<n1 ; i++) 
        if (s1[n1 - i - 1] != s2[n2 - i - 1]) 
           return false; 
    return true; 
} 

vector<vector<int>> Compute_Transition(string patern , vector<char> symbols) {
    int m = patern.size();

    vector<vector<int>> State_Machine ( m+1 , (vector<int> (symbols.size() , 0) ) );

    int k = 0;
    for (int state=0; state < m+1 ; state++)
    {
        for (int i=0 ; i < symbols.size() ; i++)
        {
            k = min( m+1 , state+2 );

            string s1 , s2 ;
            do
            {
                k--;
                s1 = patern.substr(0,k);
                s2 = patern.substr(0,state) + symbols[i];

            } while ( !isSuffix(s1,s2) );

            State_Machine[ state ][ symbols[i] ] = k;
        }
    }
    
    return State_Machine;
}