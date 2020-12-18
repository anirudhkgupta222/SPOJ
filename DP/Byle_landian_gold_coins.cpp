#include<bits/stdc++.h>
using namespace std;

map<long long ,long long> dp;

long long fun(long long n)
{
    // terminating condition
    if(n==0)
    {
        return 0;
    }
    if(dp[n] != 0)
    {
        return dp[n];
    }
    long long ans = fun(n/2) + fun(n/3) + fun(n/4);
    if(ans > n)
    {
        dp[n] = ans;
    }
    else 
    {
        dp[n] = n;
    }
    return dp[n];
}

int main()
{
    long long n=0;
    while(scanf("%lld", &n) == 1)
    {
        cout<<fun(n)<<endl;
    }
}
