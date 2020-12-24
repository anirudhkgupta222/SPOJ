#include<bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ll ans=n,temp=n;
        for(int i=2;i*i<=n;i++){
            if(temp%i==0){
                while(temp%i==0&&temp!=0){
                    temp=temp/i;
                }
                ans=(ans*(i-1))/i;
                if(temp==0) break;
            }
        }
        if(temp>1){
            ans=(ans*(temp-1))/temp;
        }
            cout << ans << endl;
    }
    return 0;
}
