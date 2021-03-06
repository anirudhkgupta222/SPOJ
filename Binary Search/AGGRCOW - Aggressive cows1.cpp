#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
bool isPossible(ll stalls[],ll d,ll n,ll c){
    
    c--;
    ll prev = 0;
    for(ll i = 1; i < n; i++){
        
        if(stalls[i] - stalls[prev] >= d){
            c--;
            prev = i;
        }
    }
    
    if(c > 0){
        return false;
    }
    return true;
    
}
int main(){
    
    ll t;
    cin >> t;
    
    while(t--){
        
        ll n,c;
        cin >> n >> c;
        
        ll stalls[n];
        
        for(ll i = 0; i < n; i++){
            cin >> stalls[i];
        }
        sort(stalls,stalls+n);
        
        ll l = 1, r = stalls[n-1]-stalls[0];
        ll ans;
        
        while(l <= r){
            
            ll mid = (l+r)/2;
            
            if(isPossible(stalls,mid,n,c)){
                ans = mid;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
            
        }
        cout << ans << endl;
    }
    return 0;
} 
