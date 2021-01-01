/*
In this question we have to allocate ballot boxes to the people. So first we sort the array of population and apply binary search on it
l=minimum population which can be assigned a ballot box
r=maximum population which can be assigned a ballot box

Then we apply binary search and each time we find the number of ballot boxes corresponding to a particular value of population
If the count is lesser than or equal to b => Number of ballot boxes are greater or equal to the total ballot boxes present and we decrease r as by doing this the value of mid will
decrease and more ballot boxes can be assigned
If the count is greater than b => Number of ballot boxes if lesser so we increase the value of l as by doing this the value of mid will increase and value of b will decrease.
*/

#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
ll binary_search(vector<ll> v,ll n,ll b){
    ll count,ans;
    ll l=1,r=v[n-1];
    while(l<=r){
        count=0;
        ll mid=(l+r)/2;
        for(ll i=0;i<n;i++){
            if(v[i]%mid!=0){
                count=count+(v[i]/mid)+1;
            }
            else if(v[i]%mid==0){
                count=count+(v[i]/mid);
            }
        }
        if(count<=b){
            ans=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return ans;
}
int main(){
    
    while(1){
        ll n,b;
        string s;
        cin>>n>>b;
        if(n==-1&&b==-1){
            break;
        }
        vector<ll> v(n);
        
        for(ll i=0;i<n;i++){
            cin>>v[i];
        }
        
        sort(v.begin(),v.end());
        cout << binary_search(v,n,b) << endl;
        getline(cin,s);
    }
    return 0;
} 
