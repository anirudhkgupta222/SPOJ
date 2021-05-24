//Ref: https://www.youtube.com/watch?v=9DckVBRzuQU
#include<bits/stdc++.h>
using namespace std;
 
int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        
        int m,n;
        cin >> m >> n;
        
        int arr1[m-1];
        int arr2[n-1];
        
        for(int i = 0; i < m - 1; i++){
            cin >> arr1[i];
        }
        for(int j = 0; j < n - 1; j++){
            cin >> arr2[j];
        }
        
        sort(arr1,arr1+m-1,greater<int>());
        sort(arr2,arr2+n-1,greater<int>());
        
        int p1 = 0, p2 = 0;
        
        int ans = 0, hzcnt = 1, vrtcnt = 1;
        
        while(p1 < m - 1 && p2 <  n - 1){
            
            if(arr1[p1] > arr2[p2]){
                ans += arr1[p1]*vrtcnt;
                hzcnt++;
                p1++;
            }
            else{
                ans += arr2[p2]*hzcnt;
                vrtcnt++;
                p2++;
            }
        }
        
        while(p1 < m - 1){
            ans += arr1[p1]*vrtcnt;
            p1++;
        }
        while(p2 < n - 1){
            ans += arr2[p2]*hzcnt;
            p2++;
        }
        cout << ans << endl;
    }
} 
