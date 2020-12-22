#include<bits/stdc++.h>
using namespace std;
 
#define ll  long long
ll x=100001;
ll arr[100001][11];
 
void sieve(){
    arr[0][0]=1;
    for(ll i=2;i*i<x;i++){
        for(ll p=i*i;p<x;p+=i*i){
            arr[p][10]=-1;
        } 
    }
    for(ll i=1;i<x;i++){
        if(arr[i][10]!=-1){
            int temp=i;
            while(temp!=0){
                arr[i][temp%10]=1;
                temp=temp/10;
            }
            for(int j=0;j<=9;j++)
            {
                arr[i][j]+=arr[i-1][j];
            }
        }
        else{
            for(int j=0;j<=9;j++)
            {
                arr[i][j]=arr[i-1][j];
            }
        }
    }
}
 
int main(){
    ll t;
    cin>>t;
    sieve();
    for(ll i=0;i<t;i++){
        ll a,b,d;
        cin>>a>>b>>d;
        ll count=0;
        cout << arr[b][d]-arr[a-1][d] << endl;
    }
    return 0;
} 
