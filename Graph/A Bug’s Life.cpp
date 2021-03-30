#include<bits/stdc++.h>
using namespace std;
 
bool dfs(int node,int color,vector<vector<int>> &arr,vector<int> &vis,vector<int> &col){
    
    vis[node] = 1;
    col[node] = color;
    
    
    for(int i = 0; i < arr[node].size(); i++){
        
        if(vis[arr[node][i]] == 0){
            bool res = dfs(arr[node][i],1^color,arr,vis,col);
            if(res == false){
                return false;
            }
        }
        else{
            if(col[node] == col[arr[node][i]]){
                return false;
            }
        }
    }
    return true;
}
int main(){
    
    int t;
    cin >> t;
    
    for(int i = 1; i <= t; i++){
        
        int n,m;
        cin >> n >> m;
        
        vector<vector<int>> arr(n+1,vector<int>());
        
        int a,b;
        while(m--){
            cin >> a >> b;
            arr[a].push_back(b);
            arr[b].push_back(a);
        }
        
        vector<int> vis(n+1,0);
        
        bool flag = true;
        
        vector<int> col(n+1,0);
        
        for(int i = 1; i <= n; i++){
            
            if(vis[i] == 0){
                bool res = dfs(i,0,arr,vis,col);
                if(res == false){
                    flag = false;
                }
            }
        }
        
        cout << "Scenario #" << i << ":" << endl;
        if(flag == false){
            cout << "Suspicious bugs found!" << endl;
        }
        else{
            cout << "No suspicious bugs found!" << endl;
        }
    }
    return 0;
} 
