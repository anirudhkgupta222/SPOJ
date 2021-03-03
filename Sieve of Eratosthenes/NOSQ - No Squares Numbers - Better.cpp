#include <bits/stdc++.h>
using namespace std;
 
#define N 100000
 
int main() {
    
    vector<int> sq(N+1,1);
    sq[1] = 1;
    
    for(int i = 2; i*i <= N; i++){
        sq[i*i] = 0;
    }
    
    for(int i = 2; i <= N; i++)
    {
        if(sq[i] == 0)
        {
            for(int j = 2*i; j <= N; j += i){
                sq[j] = 0;
            }
        }
    }
    
    int digit[N+1][10];
    memset(digit,0,sizeof(digit));
    
    for(int i = 1; i <= N; i++){
        
        int temp = i;
        while(temp != 0){
            digit[i][temp%10]++;
            temp /= 10;
        }
    }
    
    int t;
    cin >> t;
    
    for(int i = 1; i <= t; i++){
        
        int a,b,d;
        cin >> a >> b >> d;
        
        int count = 0;
        
        for(int i = a; i <= b; i++){
            
            if(sq[i] && digit[i][d]){
                count++;
            }
        }
        
        cout << count << endl;
    }
    return 0;
}
