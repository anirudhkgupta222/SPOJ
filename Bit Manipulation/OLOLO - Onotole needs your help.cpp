#include<bits/stdc++.h>
using namespace std;


int main(){
   int n;
   cin>>n;
   int ans=0,x;
   for(int i=0;i<n;i++){
       cin>>x;
       ans=ans^x;
   }
   cout << ans << endl;
   return 0;
}
