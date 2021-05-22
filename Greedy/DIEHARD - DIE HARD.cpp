//Ref: https://www.quora.com/How-do-I-solve-the-SPOJ-DIEHARD-problem
//Greedy Approach 
//Can be done using DP also
#include<bits/stdc++.h>
using namespace std;
 
int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        
        int h,a;
        cin >> h >> a;
        
        int timer = 1;
        h += 3;
        a += 2;
        
        while(1){
            
            if(timer % 2 != 0){
                int h1 = h - 5, a1 = a - 10;
                int h2 = h - 20, a2 = a + 5;
                
                if(h1 > 0 && a1 > 0){
                    h = h1;
                    a = a1;
                }
                else if(h2 > 0 && a2 > 0){
                    h = h2;
                    a = a2;
                }
                else{
                    break;
                }
            }
            else{
                h += 3;
                a += 2;
            }
            timer++;
        }
        
        cout << timer << endl;
    }
} 
