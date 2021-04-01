#include <bits/stdc++.h>
using namespace std;
 
bool bfs(int node,int c, vector<int> &col, vector<int> &vis, vector<int> al[], int &n){
    
    vis[node] = 1;
    col[node] = c;
    
    queue<int> q;
    q.push(node);
    
    while(!q.empty()){
        
        int ele = q.front();
        q.pop();
        
        for(int i = 0; i < al[ele].size(); i++){
            
            int child = al[ele][i];
            
            if(vis[child] == 1){
                if(col[ele] == col[child]){
                    return false;
                }
            }
            else{
                vis[child] = 1;
                q.push(child);                                                                                      
                col[child] = 1 - col[ele];
            }
        }
    return true;
}
int main() {
    
    int t;
    cin >> t;
    
    for(int i = 1; i <= t; i++){
        
        int n,m;
        
        cin >> n >> m;
        
        vector<int> al[n+1];
        
        int a,b;
        
        while(m--){
            cin >> a >> b;
            al[a].push_back(b);
            al[b].push_back(a);
        }
        
        vector<int> col(n+1);
        vector<int> vis(n+1,0);
        
        bool flag = true;
        
        for(int i = 1; i <= n; i++){
            
            if(vis[i] == 0){
                
                if(bfs(i,0,vis,col,al,n) == false){
                    flag = false;
                    break;
                }
            }
        }
        cout << "Scenario #" << i << ":" << endl;
        
        if(!flag){
            cout << "Suspicious bugs found!" << endl;
        }
        else{
            cout << "No suspicious bugs found!" << endl;
        }
    }
	return 0;
}
