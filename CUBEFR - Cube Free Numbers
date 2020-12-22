#include<bits/stdc++.h>
using namespace std;
 
#define ll  long long
ll x=1000001;
ll a[1000001];
 
void sieve(){
    for(ll i=2;i*i*i<x;i++){
        for(ll p=i*i*i;p<x;p+=i*i*i){
            a[p]=-1;
        } 
    }
    ll j=1;
    for(ll i=1;i<x;i++){
        if(a[i]!=-1){
            a[i]=j;
            j++;
        }
    }
}
 
int main(){
    ll t;
    cin>>t;
    sieve();
    for(ll i=0;i<t;i++){
        ll n;
        cin>>n;
        cout << "Case " << i+1 << ": ";
        if(a[n]==-1){
            cout << "Not Cube Free" << endl;
        }
        else{
            cout << a[n] << endl;
        }
    }
    return 0;
} 
Source code | Plain text | Copy to submit
