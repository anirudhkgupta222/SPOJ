#include <bits/stdc++.h>
using namespace std;

#define N 1000000
#define ll long long

int main() {
    
    int t;
    cin >> t;
    
    vector<ll> a(N,1);
    a[0] = 0;
    a[1] = 0;
    
    for(ll p = 2; p < N; p++)
    {
        for(ll i = 2*p; i < N; i+=p)
        {
            a[i] = a[i] + p;
        }
    }
    for(int i = 2; i < N; i++)
    {
        a[i] = a[i-1] + a[i];
    }
    
    while(t--){
        
        int n;
        cin >> n;
        cout << a[n] << endl;
        
    }
    return 0;
}
