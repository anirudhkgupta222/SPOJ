//Ref: https://www.quora.com/How-do-you-solve-Wine-trading-in-Gergovia-GERGOVIA-on-SPOJ
#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    
    while(1){
        
        int n;
        cin >> n;
        
        if(n == 0){
            break;
        }
        int a[n];
        
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        
        int p1 = 0, p2 = 0;
        
        ll work = 0;
        
        while(1){
            
            while(p1 < n && a[p1] >= 0){
                p1++;
            }
            
            while(p2 < n && a[p2] <= 0){
                p2++;
            }
            
            if(p1 == n || p2 == n){
                break;
            }
            if(a[p2] >= abs(a[p1])){
                a[p2] -= abs(a[p1]);
                work += (ll)(abs(p2-p1))*(abs(a[p1]));
                a[p1] = 0;
                p1++;
                if(a[p2] == 0){
                    p2++;
                }
            }
            else{
                a[p1] = abs(a[p1]);
                work += (ll)(abs(p2-p1))*a[p2];
                a[p1] -= a[p2];
                a[p1] = -1*a[p1];
                a[p2] = 0;
                p2++;
            }
        }
        cout << work << endl;
    }
}
