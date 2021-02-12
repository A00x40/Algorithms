/*
    No PreProcessing
    O( ( n-m+1 )m )
    Worst Case m = floor(n/2) -> O(n^2)
*/

#include <iostream>
#include <string>

using namespace std;


int main() {
    string text , patern;
    cout << "Enter Text: ";
    cin >> text;
    cout << endl;

    cout << "Enter Patern: ";
    cin >> patern;
    cout << endl;

    int n = text.size() , m = patern.size() ;

    for(int s=0 ; s < n-m+1 ; s++) 
        if( patern == text.substr(s,m) )
            cout << "Patern found at position " << s << endl;

    return 0;
}