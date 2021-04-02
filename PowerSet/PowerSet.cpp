#include <iostream>

using namespace std;

// S = {a, b, c}
int main() {
    string set;
    cin >> set;

    for (int i = 0; i < 1 << set.size(); i++)
    {
        for (int j = 0; j < set.size() ; j++)
        {
            if( i & 1 << j)  {
                
                cout << set[j];
            }
        }
        cout << endl;
    }

}