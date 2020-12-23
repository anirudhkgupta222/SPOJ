#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
int main(){
    
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        int flag=0;
        
        for(ll i=0;i*i<=n;i++){
            if(sqrt(n-i*i)==ceil(sqrt(n-i*i))){
                cout << "Yes" << endl;
                flag=1;
                break;
            }
        }
        if(flag==0){
            cout << "No" << endl;
        }
    }
    return 0;
} 
