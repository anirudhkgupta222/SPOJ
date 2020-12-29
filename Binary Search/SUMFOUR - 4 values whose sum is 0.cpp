#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
ll numberofwoodscut(ll arr[],ll mid,ll n){
    ll sum=0,x=0;
    for(ll i=0;i<n;i++){
        sum=sum+max(x,arr[i]-mid);
    }
    return sum;
}
 
ll binary_search(ll arr[],ll n,ll m){
    ll l=0,r=1000000002,ans;
    
    while(l<=r){
        ll mid=(l+r)/2;
        if(numberofwoodscut(arr,mid,n)>m){
            l=mid+1;
            ans=mid;
        }
        else if(numberofwoodscut(arr,mid,n)==m){
            return mid;
        }
        else{
            r=mid-1;
        }
    }
    return ans;
}
int main(){
    ll n,m;
    cin>>n>>m;
    
    ll arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    cout << binary_search(arr,n,m) << endl;
    
    return 0;
} 
