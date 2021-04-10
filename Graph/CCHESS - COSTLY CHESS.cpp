//Dijkstra's Algorithm on 2D Grid
#include<bits/stdc++.h>
using namespace std;
 
#define ppi pair<int,pair<int,int>>
 
int dx[8] = {-2,-2,-1,-1,1,1,2,2};
int dy[8] = {-1,1,-2,2,-2,2,-1,1};
 
bool isValid(int x, int y, vector<vector<int>> &vis){
    
    if(x < 0 || x >=8 || y < 0 || y >= 8){
        return false;
    }
    
    if(vis[x][y] == 1){
        return false;
    }
    return true;
}
int bfs(int srcx, int srcy, int dstx, int dsty){
    
    priority_queue<ppi, vector<ppi>, greater<ppi>> pq;
    
    pq.push({0,{srcx,srcy}});
    
    vector<vector<int>> dist(8,vector<int>(8,INT_MAX));
    vector<vector<int>> vis(8,vector<int>(8,0));
    
    dist[srcx][srcy] = 0;
    
    while(!pq.empty()){
        
        int currx = pq.top().second.first, curry = pq.top().second.second, currd = pq.top().first;
        
        pq.pop();
        
        vis[currx][curry] = 1;
        
        for(int i = 0; i < 8; i++){
            
            int newx = currx + dx[i], newy = curry + dy[i];
            
            if(isValid(newx,newy,vis)){
                    
                if(currd + currx*newx + curry*newy < dist[newx][newy]){
                    
                    dist[newx][newy] = currd + currx*newx + curry*newy;
                    pq.push({dist[newx][newy],{newx,newy}});
                }
            }
        }
    }
    return dist[dstx][dsty];
}
int main(){
    
    while(1){
        
        int a,b,c,d;
        a = -1;
        cin >> a >> b >> c >> d;
        
        if(a == -1) break;
    
        cout << bfs(a,b,c,d) << endl;
    }
    
} 
