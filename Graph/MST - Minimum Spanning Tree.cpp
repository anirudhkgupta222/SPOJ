#include <bits/stdc++.h>
using namespace std;
 
#define pii pair<int,int>
#define ll long long

void prims(int n,vector<pair<int,int>> al[]){
 
    vector<int> vis(n+1,0);
    vector<int> dist(n+1,INT_MAX);
    
    dist[1] = 0;
    
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    
    pq.push({0,1});
    
    while(!pq.empty()){
        
        int curr = pq.top().second;
        pq.pop();
        
        vis[curr] = 1;
        for(int i = 0; i < al[curr].size(); i++){
            
            int child = al[curr][i].first, w = al[curr][i].second;
            
            if(vis[child] == 0 && w < dist[child]){
                dist[child] = w;
                pq.push({dist[child],child});
            }
        }
    }
    
    ll min_wt = 0;
    
    for(int i = 1; i <= n; i++){
        min_wt += dist[i];
    }
    cout << min_wt << endl;
}
int main() {
    
    int n,m;
    cin >> n >> m;
    
    std::vector<pair<int,int>> al[n+1];
    
    int a,b,w;
    
    while(m--){
        cin >> a >> b >> w;
        al[a].push_back({b,w});
        al[b].push_back({a,w});
    }
    
    prims(n,al);
	return 0;
}
 
