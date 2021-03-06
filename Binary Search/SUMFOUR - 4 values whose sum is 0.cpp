#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
int main(){
    
    ll n;
    cin >> n;
    
    ll a[n][4];
    
    for(ll i = 0; i < n; i++){
        cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3];
    }
    
    ll sum1[n*n], sum2[n*n];
    ll temp = 0;
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++){
            sum1[temp] = a[i][0] + a[j][1];
            temp++;
        }
    }
    temp = 0;
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++){
            sum2[temp] = -1*(a[i][2] + a[j][3]);
            temp++;
        }
    }
    
    sort(sum2,sum2 + n*n);
    ll count = 0;
    for(ll i = 0; i < n*n; i++){
        count += upper_bound(sum2,sum2+n*n,sum1[i]) - lower_bound(sum2,sum2+n*n,sum1[i]);
    }
    cout << count << endl;
} 
