#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int cont = 0;

int dp[210][25];
int func(int valor, int pos){
	if(pos == 0) return valor;
	if(dp[valor][pos] != -1) return dp[valor][pos];
	int peguei = func(valor+v[pos-1],pos-1);
	int npeguei = func(abs(valor-v[pos-1]),pos-1);
	return dp[valor][pos] = min(peguei,npeguei);
}


int main(){
	freopen("saida.txt","w",stdout);
	int N; cin >> N;
	string str, str2;
	for(int i = 0; i <N; i++){
		cont = 0;
		if(i == 0) cin.ignore();
		getline(cin,str);
		stringstream ss(str);
		while(ss>>str2){
			v.push_back(stoi(str2));
			cont++;
		}
		memset(dp,-1,sizeof(dp));
		int ans = func(0,cont);
		if(ans != 0) cout << "NO" << endl;
		else cout << "YES" << endl;
		v.clear();
	}
}
