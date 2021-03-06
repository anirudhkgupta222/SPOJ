#include<bits/stdc++.h>
using namespace std;
 
#define ll long long

//Function to check if ballot boxes are left after assigning it to the population
bool isBallotLeft(ll a[],ll n,ll p,ll b){
    
    for(ll i = 0; i < n; i++){
        if(a[i] % p == 0){
            b -= a[i]/p;
        }
        else{
            b = b - (a[i]/p + 1);
        }
    }
    
    if(b>=0){
        return true;
    }
    return false;
}
int main(){
    
    while(1){
        
        ll n,b;
        cin >> n >> b;
        
        if(n == -1 && b == -1){
            break;
        }
        
        ll a[n], l = 1, r = INT_MIN, ans;
        
        for(ll i = 0; i < n; i++){
            cin >> a[i];
            if(a[i] > r){
                r = a[i];
            }
        }
        
        while(l<=r){
            ll mid = (l+r)/2;             //Mid value => Population per ballot box
            
            if(isBallotLeft(a,n,mid,b)){  //If for a particular population the ballot boxes are left then we will decrease the population 
                ans = mid;                //to check if at a lower population value sufficient ballot boxes are there or not
                r = mid - 1;   
            }
            else{
                l = mid + 1;
            }
        }
        cout << ans << endl;
    }
} 
