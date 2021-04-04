#include <bits/stdc++.h>
using namespace std;
 
set<int> AP;
void dfs(int node, int par, vector<int> &vis, vector<int> &disc, vector<int> &low, vector<int> al[], int &timer, int &ap){
    
    vis[node] = 1;
    disc[node] = low[node] = timer;
    timer++;
    int children = 0;
    
    for(int i = 0; i < al[node].size(); i++){
        
        int child = al[node][i];
        
        if(child == par) continue;
        
        if(vis[child] == 1){
            low[node] = min(low[node], disc[child]);
        }
        else{
            children++;
            dfs(child, node, vis, disc, low, al, timer, ap);
            
            if(low[child] >= disc[node] && par != -1){
                AP.insert(node);
            }
            low[node] = min(low[node],low[child]);
        }
    }
    if(children > 1 && par == -1){
        ap++;
    }
}
int main() {
    
    while(1){
        
        int n,m;
        cin >> n >> m;
        
        if(n == 0 && m == 0){
            break;
        }
        
        std::vector<int> al[n+1];
        int a,b;
        
        while(m--){
            cin >> a >> b;
            al[a].push_back(b);
            al[b].push_back(a);
        }
        
        vector<int> vis(n + 1, 0);
        vector<int> disc(n+1);
        vector<int> low(n+1);
        int timer = 0, ap = 0;
        
        AP.clear();  
        for(int i = 1; i <= n; i++){
        	if(vis[i] == 0)
                dfs(i, -1, vis, disc, low, al, timer, ap);
        }
        cout << AP.size() << endl;
    }
	return 0;
}
