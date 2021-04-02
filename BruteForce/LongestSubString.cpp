/*

Complexity n^3 ( n outerLoop * n InnerLoop * n Comparing)

*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    int subStrCount = 0 , maxLen = 0 ;

    for( int i=0 ; i< s.size() ; i++ ) 

        for(int j=i+1;j<s.size();j++) {
            
            int k = 0;

            while( s[i+k] == s[j+k] ) k++;
            maxLen = max(maxLen,k);
        }
    cout << maxLen;

    return 0;
}