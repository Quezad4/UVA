#include <bits/stdc++.h>
using namespace std;


long long int dp[10010][22];
int vet[21] = {1,8,27,64,125,216,343,512,729,1000,1331,1728,2197,2744,3375,4096,4913,5832,6859,8000,9261};


long long int func(int x, int pos){
	if(x == 0) return 1;
	if(pos > 20) return 0;
	if(dp[x][pos] != -1) return dp[x][pos];
	long long int pegou = 0;
	if(x - vet[pos] >= 0) pegou = func(x-vet[pos], pos);
	long long int npegou = func(x,pos+1);
	return dp[x][pos] = pegou + npegou;
	
}

int main(){
	int N;
	while(cin >> N){
		memset(dp,-1,sizeof(dp));
		cout << func(N,0) << endl;
	}
}
