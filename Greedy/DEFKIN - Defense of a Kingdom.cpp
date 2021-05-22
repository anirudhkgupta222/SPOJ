#include<bits/stdc++.h>
using namespace std;
 
int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        
        int w,h,n;
        cin >> w >> h >> n;
        
        vector<int> x;
        vector<int> y;
        
        int a,b;
        for(int i = 0; i < n; i++){
            cin >> a >> b;
            x.push_back(a);
            y.push_back(b);
        }
        
        x.push_back(w+1);
        y.push_back(h+1);
        
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        
        int max_x = x[0] - 1;
        int max_y = y[0] - 1;
        
        for(int i = 1; i < x.size(); i++){
            max_x = max(max_x,x[i]-x[i-1]-1);
            max_y = max(max_y,y[i]-y[i-1]-1);
        }
        
        cout << max_x*max_y << endl;
    }
} 
