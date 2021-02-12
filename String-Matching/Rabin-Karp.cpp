/*

Complexity

Pre Processing -> m

Loop -> n-m+1
Same Hash Comparisons -> Cm

O( (n-m+1) + Cm )

Same Worst Case for Naive Algo
Average Case Better than Naive Algo 

*/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// d is the number of characters in the input alphabet 
#define d 256;

void Rabin_Karp( string text , string patern , const int power) ;

int main() {
    string text , patern;
    cout << "Enter Text: ";
    cin >> text;
    cout << endl;

    cout << "Enter Patern: ";
    cin >> patern;
    cout << endl;

    const int power = 10;

    Rabin_Karp(text , patern , power);


    return 0;
}

void Rabin_Karp( string text , string patern , int power) {
    int n = text.size() , m = patern.size();
    int h = 1;
    
    // The value of h would be "pow(d, m-1)%q"  
    for (int i=0; i < m-1; i++)  
        h = (h * power) % d; 

    // Hash Values for pattern and First window 
    int p = 0, t = 0; 
    for (int i = 0; i < m; i++)
    {
        p += (p*power + patern[i]) % d;
        t += (t*power + text[i]) % d;
    }

    // Slide Window
    for (int s=0 ; s <= n-m ; s++)  
    {
        if( p == t )
            if( patern == text.substr(s,m) )
                cout << "Patern found at position " << s << endl;

        // Calculate next hash in constant time
        if( s < n-m )
        {
            t =  ( t - text[i]*h ) power + text.substr(s.m) % d;

            // We might get negative value of t, converting it to positive  
            if (t < 0)  
                t = (t + q);
        }     
    }
}