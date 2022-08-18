#include <bits/stdc++.h>
using namespace std;



typedef long long int lli;


lli pd[85];

lli fib(lli x){
	if(x <= 1) return pd[x] = 1;
	if(pd[x] != -1) return pd[x];
	return pd[x] = fib(x-1) + fib(x-2);
}




int main(){
	int x;
	while(cin >> x and x){
		memset(pd,-1, sizeof(pd));
		cout << fib(x-1) << endl;
		
	}
	
}
