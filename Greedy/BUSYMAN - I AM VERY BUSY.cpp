#include<bits/stdc++.h>
using namespace std;
 
 
bool cmp(pair<int,int> p1,pair<int,int> p2){
    return p1.second<p2.second;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            int start,end;
            cin>>start>>end;
            v.push_back(make_pair(start,end));
        }
        sort(v.begin(),v.end(),cmp);
        int count=0,last=-1;
        for(int i=0;i<n;i++){
            if(v[i].first>=last){
                count++;
                last=v[i].second;
            }
            if(v[i].second<last){
                last=v[i].second;
            }
        }
        cout << count << endl;
    }
    return 0;
}
