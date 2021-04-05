#include<bits/stdc++.h>
using namespace std;
 
void kahn(int n, vector<int> al[], vector<int> &in, vector<int> &res){
    
    priority_queue<int,vector<int>,greater<int>> pq;
    
    for(int i = 1; i <= n; i++){
        
        if(in[i] == 0){
            pq.push(i);
        }
    }
    
    while(!pq.empty()){
        
        int curr = pq.top();
        res.push_back(curr);
        
        pq.pop();
        
        for(int i = 0; i < al[curr].size(); i++){
            
            int child = al[curr][i];
            in[child]--;
            
            if(in[child] == 0){
                pq.push(child);
            }
        }
    }
}
int main(){
    
    int n,m;
    cin >> n >> m;
    
    std::vector<int> al[n+1];
    vector<int> in(n+1,0);
    int x,y;
    while(m--){
        cin >> x >> y;
        al[x].push_back(y);
        in[y]++;
    }
    vector<int> res;
    kahn(n, al, in, res);
    
    if(res.size() == n){
        for(int i = 0; i < n; i++){
            cout << res[i] << " ";
        }
        cout << endl;
    }
    else{
        cout << "Sandro fails." << endl;
    }
} 
