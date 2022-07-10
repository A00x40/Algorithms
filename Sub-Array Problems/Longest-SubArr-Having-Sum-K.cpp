#include <bits/stdc++.h>

#define maxn 1e5+5
#define ll long long

#define vec(arr) vector<ll> arr(maxn);
#define ht(um) unordered_map<ll, ll> um;

#define lp(i,n) for(ll i=0;i<n;i++)
#define declp(i,n) for(ll i=n;i>0;i--)

using namespace std;

int main()
{
    ll n, k;
    cin >> n >> k;

    vec(arr)

    lp(i,n) {
        cin >> arr[i];
    }

    ht(um)

    ll sum = 0, maxlen = 0;

    lp(i,n) {
        sum += arr[i];

        if(sum == k) maxlen = i+1; 

        if (um.find(sum) == um.end())
            um[sum] = i;
 
        
        if (um.find(sum - k) != um.end()) {
 
            if (maxlen < (i - um[sum - k]))
                maxlen = i - um[sum - k];
        }
            
    }

    cout << maxlen;
}