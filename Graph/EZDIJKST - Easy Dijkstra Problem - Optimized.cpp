#include<bits/stdc++.h>
using namespace std;
 
#define pii pair<int,int>
 
int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        int n,m;
        cin >> n >> m;
        
        vector<pair<int,int>> adj[n+1];
        
        int a,b,w;
        
        while(m--){
            cin >> a >> b >> w;
            adj[a].push_back({b,w});
            //adj[b].push_back({a,w});
        }
        
        int src,dst;
        cin >> src >> dst;
        
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        
        vector<int> parent(n+1);
        vector<int> dist(n+1,INT_MAX);
        parent[src] = -1;
        pq.push({0,src});
        dist[src] = 0;
        while(!pq.empty()){
            
            int curr = pq.top().second;
            int curr_d = pq.top().first;
            
            pq.pop();
            if(curr_d > dist[curr]){    //Ignore the old pairs
            	continue;
            }
            for(int i = 0; i < adj[curr].size(); i++){
                
                if(curr_d + adj[curr][i].second < dist[adj[curr][i].first]){
                    dist[adj[curr][i].first] = curr_d + adj[curr][i].second;
                    pq.push({dist[adj[curr][i].first],adj[curr][i].first});
                    parent[adj[curr][i].first] = curr;
                }
            }
        }
        if(dist[dst] == INT_MAX) cout << "NO" << endl;
        else cout << dist[dst] << endl;
    }
}
