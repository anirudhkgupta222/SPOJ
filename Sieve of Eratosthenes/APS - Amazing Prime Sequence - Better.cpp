#include <bits/stdc++.h>
using namespace std;
 
#define N 10000000
#define ll long long
 
int main() {
    
    int t;
    cin >> t;
    
    ll a[N] = {0};
    a[0] = 0;
    a[1] = 0;
    for(ll p = 2; p < N; p++){
        if(a[p] == 0){
            a[p] = p;
            for(ll i = p*p; i < N; i+=p){       //ll should be used o/w there will be error
                if(a[i] == 0){
                    a[i] = p;
                }
            }
        }
    }
    for(ll i = 2; i <= N; i++){
        a[i] = a[i-1] + a[i];
    }
    while(t--){
        
        int n;
        cin >> n;
        cout << a[n] << endl;
        
    }
    return 0;
}
