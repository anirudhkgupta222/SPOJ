#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int  t;
    cin >> t;
    
    while(t--){
        
        int n;
        cin >> n;
        
        int arr[n];
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        
        sort(arr,arr+n);
        
        int j = 0;
        
        while(j < n){
            if(arr[j] == 1){
                cout << 1 << " ";
                j++;
            }
            else{
                break;
            }
        }
        
        if(j == n-2 && arr[j] == 2 && arr[j+1] == 3){
            cout << "2 3" << endl;
        }
        else{
            for(int k = n - 1; k >= j; k--){
                cout << arr[k] << " ";
            }
        }
        cout << endl;
    }
}
