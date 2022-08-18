#include <bits/stdc++.h>
using namespace std;

int pd[11];



int fat(int x){
	if(x <= 1) return pd[x] = 1;
	if(pd[x] != -1) return pd[x];
	return pd[x] = x * fat(x-1); 
}




int main(){
	int x, count = 0;
	memset(pd,-1,sizeof(pd));
	fat(10);
	pd[0] = 1;
	while(cin >> x){
		int i = 9;
		while(x>0){
			if(x>= pd[i]){
				x -= pd[i];
				count++;
			}
			else{
				i--;
			}
		}
		cout << count << endl;
		count = 0;
	}
	
}
