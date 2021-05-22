//Ref: https://www.quora.com/How-do-I-solve-the-SPOJ-DIEHARD-problem
#include<bits/stdc++.h>
using namespace std;
 
int solve(int h, int a, vector<vector<int>> &dp){
    
    if(h <= 0 || a <= 0){
        return -1;
    }
    
    if(dp[h][a] != -1){
        return dp[h][a];
    }
    
    return dp[h][a] = max(solve(h-2,a-8,dp) + 2, solve(h-17,a+7,dp) + 2);
}
int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        
        int h,a;
        cin >> h >> a;
        
        vector<vector<int>> dp(2001,vector<int>(2001,-1));
        
        cout << solve(h,a,dp) << endl;
    }
} 
