#include <bits/stdc++.h>
using namespace std;

int dp[7500][6];
int vet[5] = {1,5,10,25,50};

int conta(int x, int pos){
	if(pos > 4) return 0;
	if(x == 0) return 1;
	if(dp[x][pos] != -1) return dp[x][pos];
	int sum = 0;
	if(x-vet[pos] >= 0) sum+= conta(x-vet[pos], pos);
	sum+=conta(x, pos+1);
	return dp[x][pos] = sum;
	
}


int main(){
	int N;
	ios_base::sync_with_stdio(false);
	 cin.tie(NULL);
	while(cin >> N){
		for(int i = 0; i <=N; i++){
			for(int j = 0; j<6; j++){
				dp[i][j] = -1;
			}
		}
		cout << conta(N,0) << endl;
	}
}
