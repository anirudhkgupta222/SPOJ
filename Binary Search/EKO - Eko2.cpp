#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
ll woodcut(ll trees[],ll h,ll n){
    
    ll cut = 0;
    
    for(ll i = 0; i < n; i++){
        if(trees[i] > h){
            cut += trees[i]-h;
        }
    }
    return cut;
}
int main(){
    
    ll n,m;
    cin >> n >> m;
    
    ll trees[n],l = 0, r = INT_MIN;
    
    for(ll i = 0; i < n; i++){
        cin >> trees[i];
        r = max(r,trees[i]);
    }
    ll ans;
    while(l <= r){
        
        ll mid = (l+r)/2;
        
        if(woodcut(trees,mid,n) == m){
            ans = mid;
            break;
        }
        else if(woodcut(trees,mid,n) > m){
            ans = mid;
            l = mid + 1;
        }
        else if(woodcut(trees,mid,n) < m){
            r = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
} 
