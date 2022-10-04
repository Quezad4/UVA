#include <bits/stdc++.h>
using namespace std;

int vet[11] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};
long long int dp[30010][12];


long long func(int x, int pos){
	if(x == 0) return 1;
	if(pos > 10) return 0;
	if(dp[x][pos] != -1) return dp[x][pos];
	long long int pegou = 0;
	if(x-vet[pos] >= 0) pegou = func(x-vet[pos], pos);
	long long int npegou = func(x,pos+1);
	return dp[x][pos] = pegou + npegou;
}


int main(){
	freopen("saida.txt", "w" , stdout);
	long double N;
	cin >> N;
	while(N != 0.00){
		memset(dp,-1,sizeof(dp));
		cout.precision(2);
		cout<<fixed;
		cout<<setw(6)<<setfill(' ')<<N;
		N = N*10000;
		N = N/100;
		cout<<setw(17)<<setfill(' ')<<func(N,0) << endl;
		cin >> N;
	}
	
	
	
}
