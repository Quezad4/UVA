#include <bits/stdc++.h>
using namespace std;

int vet[5] = {50,25,10,5,1};
long long int dp[30010][6]; // dois estados pq eu guardo a soma, e posso ter soma 
//de valores igual, sobrescrevendo a dp

long long int func(int x, int pos){
	if(x == 0) return 1; // deu bom pq eu cheguei em 0 moedas;
	if(pos > 4) return 0; // deu ruim pq a posicao passou daquela q eu queria pegar das moeda
	if(dp[x][pos] != -1) return dp[x][pos]; // se ja calculou nao calcula dnv
	long long int pegou = 0;
	if(x-vet[pos] >= 0) pegou = func(x-vet[pos], pos); //eu posso pegar so quando aquela moeda for possivel pegar
	// se eu peguei vou tirar do total de moedas q eu posso pegar
	long long int npegou = func(x,pos+1); // se eu nao peguei, so passo pra posso moeda
	return dp[x][pos] = pegou+ npegou; // return soma dos resultados 
	
}


int main(){
	int N;
	while(cin >> N){
		memset(dp,-1,sizeof(dp));
		if(func(N,0) == 1){
			cout << "There is only 1 way to produce " << N << " cents change." << endl;
		}
		else{
			cout << "There are " << func(N,0) << " ways to produce " << N << " cents change." << endl; 
		}
		
	} 
}
