/*
0^1=1 and 1^0=1 only pair of 0,1 gives XOR value 1 so we will find all the 1's according to the 
position and then find the number of pairs
*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
    int n;
    cin>>n;
    
    ll arr[n],bit[30]={0};
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(n==1){
        cout << arr[0] << endl;
        return 0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<20;j++){
            if((arr[i]>>j)&1){
                bit[j]++;
            }
        }
    }
    ll ans=0;
    for(int i=0;i<20;i++){
        ans=ans+(bit[i])*(n-bit[i])*(1<<i);  //ans=ans+(Number of 1's)*(Number of 0's)*(Position Value)
    }
    cout << ans << endl;
    return 0;
}
