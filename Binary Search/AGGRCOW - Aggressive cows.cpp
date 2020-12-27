#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
ll numberofcowsplaced(ll arr[],ll n,ll mid){
    ll count=1,prev=arr[0];
    for(ll i=1;i<n;i++){
        if(arr[i]-prev>=mid){
            prev=arr[i];
            count++;
        }
    }
    return count;
}
ll binary_search(ll arr[],ll n,ll c){
    ll l=1,r=arr[n-1]-arr[0],ans;
    
    while(l<=r){
        ll mid=(l+r)/2;
        if(numberofcowsplaced(arr,n,mid)>=c){
            ans=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    return ans;
}
int main(){
    ll t;
    cin>>t;
    
    while(t--){
        ll n,c;
        cin>>n>>c;
        ll arr[n];
        for(ll i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        
        cout << binary_search(arr,n,c) << endl;
    }
    return 0;
} 
