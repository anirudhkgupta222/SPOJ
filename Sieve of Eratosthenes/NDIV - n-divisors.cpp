#include <bits/stdc++.h>
using namespace std;
 
#define N 31623
 
int main() {
	
	int primes[N] = {0};
	
	for(int i = 2; i *i < N; i++)
	{
		if(primes[i] == 0)
		{
			for(int p = i *i ; p < N; p += i)
				primes[p] = 1;
		}
	}
	
	int a,b,n,ans = 1, count,res = 0;
	cin >> a >> b >> n;
	
	for(int i = a; i <= b; i++){
		
		ans = 1;
		int temp = i;
		for(int j = 2; j * j <= i; j++){
			
			count = 0;
			
			if(primes[j] == 0 && temp % j == 0){
					
					while(temp % j == 0){
						count++;
						temp /= j;
					}
			}
			
			ans = ans*(count+1);
		}
		
		if(temp != 1){
			ans = ans*2;
		}
		if(ans == n){
			res++;
		}
		
	}
	cout << res << endl;
	
	return 0;
} 
