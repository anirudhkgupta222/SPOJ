#include <bits/stdc++.h>
using namespace std;
 
void dfs(int node, vector<int> &vis, vector<int> al[]){
    
    vis[node] = 1;
    
    for(int i = 0; i < al[node].size(); i++){
        
        int child = al[node][i];
        if(vis[child] == 0){
            dfs(child,vis,al);
        }
    }
}
int main() {
    
    int t;
    cin >> t;
    
    while(t--){
        
        int n,e;
        cin >> n >> e;
        
        std::vector<int> al[n];
        
        int a,b;
        while(e--){
            cin >> a >> b;
            al[a].push_back(b);
            al[b].push_back(a);
        }
        
        vector<int> vis(n,0);
        int cc_count = 0;
        for(int i = 0; i < n; i++){
            
            if(vis[i] == 0){
                cc_count++;
                dfs(i,vis,al);
            }
        }
        cout << cc_count << endl;
    }
	return 0;
}
