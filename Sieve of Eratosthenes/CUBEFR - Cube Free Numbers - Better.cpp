#include <bits/stdc++.h>
using namespace std;
 
#define N 1000000
#define ll long long
 
int main() {
    
    vector<int> a(N+1,1);
    
    for(int i = 2; i*i*i <= N; i++){
        a[i*i*i] = 0;
    }
    
    int j = 1;
    
    for(int i = 1; i <= N; i++)
    {
        if(a[i] == 0)
        {
            for(int j = 2*i; j <= N; j += i)
            {
                a[j] = 0;
            }
        }
        else
        {
            a[i] = j;
            j++;
        }
    }
    
    int t;
    cin >> t;
    
    for(int i = 1; i <= t; i++){
        
        int n;
        cin >> n;
        cout << "Case " << i << ": ";
        
        if(a[n]){
            cout << a[n] << endl;
        }
        else{
            cout << "Not Cube Free" << endl;
        }
    }
    return 0;
}
