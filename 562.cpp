#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int M;

int dp[50010][110];
int func(int valor, int pos){
	if(pos == 0) return valor;
	if(dp[valor][pos] != -1) return dp[valor][pos];
	int peguei = func(valor+v[pos-1], pos-1);
	int npeguei = func(abs(valor-v[pos-1]),pos-1);
	return dp[valor][pos] = min(peguei,npeguei);
}





int main(){
	//freopen64("saida.txt","w", stdout);
	int T; cin >> T;
	int coin;
	for(int i = 0; i<T; i++){
		cin >> M;
		for(int i = 0; i<M; i++){
			cin >> coin;
			v.push_back(coin);
		}
		memset(dp,-1,sizeof(dp));
		int ans = func(0,M);
		cout << ans << endl;
		v.clear();
	}
}
