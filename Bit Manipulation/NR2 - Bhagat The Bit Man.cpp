#include<bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
    int n;
    cin>>n;
    
    ll arr[n],bits[64]={0};
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<64;j++){
            if((arr[i]>>j)&1){
                bits[j]++;
            }
        }
    }
    ll ans=0;
    for(int i=0;i<64;i++){
        if(bits[i]!=n&&bits[i]!=0){
            ans=ans+(1LL<<i);
        }
    }
    cout << ans << endl;
    return 0;
}
