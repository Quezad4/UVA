#include <bits/stdc++.h>
using namespace std;

vector<int> coins;
pair<int,int> dp[10010][101][21];
int target;

pair<int,int > func(int valor, int pos, int count){
	if(pos<0) return{(int)1e9,(int)1e9};
	if(valor >= target) return {valor,count};
	if(dp[valor][pos][count].first != -1 and dp[valor][pos][count].second != -1) return dp[valor][pos][count];
	pair<int,int > pegar=func(valor+coins[pos-1],pos-1,count+1); 
	pair<int,int > passar=func(valor,pos-1,count);
	//~ cout << "Passar : " <<passar.first << " " << passar.second << endl;
	if(pegar.first > passar.first){
		dp[valor][pos][count] = passar;
	}
	else{
		if(pegar.first < passar.first){
			dp[valor][pos][count] = pegar;
		}
		else{
			if(passar.second > pegar.second){
				dp[valor][pos][count] = pegar;
			}
			else{
				dp[valor][pos][count] = passar;
			}
		}
	}
	return dp[valor][pos][count];
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	//~ freopen("saida.txt","w", stdout);
	//~ freopen("entrada.txt", "r", stdin);
	int N, M, coin;
	cin >> N;
	for(int i = 0 ; i<N; i++){
		cin >> target;
		cin >> M;
		for(int j = 0; j<M; j++){
			cin >> coin;
			coins.push_back(coin);
		}
		for(int j = 0; j<10010; j++){
			for(int k = 0; k<101; k++){
				for(int l = 0; l<21; l++){
					dp[j][k][l]={-1,-1};
				}
				
			}
		}
		pair<int,int> v = func(0,M,0);
		cout << v.first << " " << v.second << endl;
		coins.clear();
	}
}
