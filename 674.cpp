#include <iostream>

int dp[7500][6];
int vet[5] = {50,25,10,5,1};

int conta(int x, int pos){
	if(x == 0) return 1;
	if(pos > 4) return 0;
	if(dp[x][pos] != -1) return dp[x][pos];
	int sum = 0;
	if(x-vet[pos] >= 0) sum+= conta(x-vet[pos], pos);
	sum+=conta(x, pos+1);
	return dp[x][pos] = sum;
	
}


int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int N;
	while(std::cin >> N){
		for(int i = 0; i <=N; i++){
			for(int j = 0; j<6; j++){
				dp[i][j] = -1;
			}
		}
		std::cout << conta(N,0) << std::endl;
	}
}
