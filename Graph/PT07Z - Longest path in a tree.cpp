//Diameter of tree
//https://www.spoj.com/problems/PT07Z/
#include<bits/stdc++.h>
using namespace std;
 
void dfs(int node,int d, vector<int> &dist, vector<int> &vis, vector<int> al[]){
    
    vis[node] = 1;
    dist[node] = d;
    
    for(int i = 0 ; i < al[node].size(); i++){
        int child = al[node][i];
        
        if(vis[child] == 0){
            dfs(child, dist[node] + 1, dist, vis, al);
        }
    }
    
}
int main(){
    
    int n;
    cin >> n;
    
    std::vector<int> al[n+1];
    int a,b;
    
    for(int i = 1; i <= n - 1; i++){
        cin >> a >> b;
        al[a].push_back(b);
        al[b].push_back(a);
    }
    
    vector<int> dist(n+1,0);
    vector<int> vis(n+1,0);
    
    dfs(1,0,dist,vis,al);
    
    int far = INT_MIN, x;
    
    for(int i = 1; i <= n; i++){
        
        if(dist[i] > far){
            far = dist[i];
            x = i;
        }
    }
    
    for(int i = 1; i <= n; i++){
        dist[i] = 0;
        vis[i] = 0;
    }
    dfs(x,0,dist,vis,al);
    
    far = INT_MIN;
    for(int i = 1; i <= n; i++){
        
        if(dist[i] > far){
            far = dist[i];
        }
    }
    cout << far << endl;
} 
