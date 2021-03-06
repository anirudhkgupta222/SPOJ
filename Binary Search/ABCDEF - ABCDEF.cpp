#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    
    int a[n];
    
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    vector<int> sum1, sum2;
    int temp = 0;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                
                sum1.push_back(a[i]*a[j]+a[k]);
                
                if(a[k]!=0)
                sum2.push_back(a[k]*(a[i] + a[j]));
            }
        }
    }
    sort(sum2.begin(),sum2.end());
    
    int count = 0;
    
    for(int i = 0; i < sum1.size(); i++){
        count += upper_bound(sum2.begin(),sum2.end(),sum1[i]) - lower_bound(sum2.begin(),sum2.end(),sum1[i]);
    }
    cout << count << endl;
} 
