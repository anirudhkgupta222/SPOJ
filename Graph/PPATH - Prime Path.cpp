//Very good application of Graph
#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n){
    
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}
//Function to check whether the two prime numbers differ in one digit or not
bool isValid(int a, int b){
    
    int count = 0;
    
    while(b){
        
        if(a % 10 != b % 10){
            count++;
        }
        a /= 10;
        b /= 10;
    }
    
    if(count == 1){
        return true;
    }
    return false;
}
void bfs(int src, vector<int> &vis, vector<int> &dist, vector<int> al[]){
    
    vis[src] = 1;
    dist[src] = 0;
    
    std::queue<int> q;
    q.push(src);
    
    while(!q.empty()){
        
        int curr = q.front();
        q.pop();
        
        for(int i = 0; i < al[curr].size(); i++){
            
            int child = al[curr][i];
            
            if(vis[child] == 0){
                vis[child] = 1;
                q.push(child);
                dist[child] = dist[curr] + 1;
            }
        }
    }
}
int main(){
    
    int t;
    cin >> t;
    
    vector<int> primes;
    
    for(int i = 1000; i <= 9999; i++){
        
        if(isPrime(i)){
            primes.push_back(i);
        }
    }
    
    vector<int> al[10000];
    
    for(int i = 0; i < primes.size(); i++){
        for(int j = i + 1; j < primes.size(); j++){
            
            int a = primes[i], b = primes[j];
            
            if(isValid(a,b)){
                al[a].push_back(b);
                al[b].push_back(a);
            }
        }
    }
    while(t--){
        
        int a,b;
        cin >> a >> b;
        
        vector<int> vis(10000,0);
        vector<int> dist(10000, -1);
        
        bfs(a,vis,dist,al);
        
        if(dist[b] == -1){
            cout << "Impossible" << endl;
        }
        else{
            cout << dist[b] << endl;
        }
    }
}
