#include <bits/stdc++.h>
using namespace std;


vector<int> v;

int quant,N;


struct struczera{
	int v  = -1;
	
};





int func(int at, int w, int valor, int divisor, unordered_map<int,unordered_map<int,unordered_map<int,struczera> > > &dp ){
	if(at < 0 or w >quant) return dp[valor][at][w].v = 0;
	if(w == quant and valor%divisor == 0){
		return dp[valor][at][w].v = 1;
	}
	if(dp[valor][at][w].v != -1){
		return dp[valor][at][w].v;
	} 
	int pega = func(at-1,w+1,(valor+v[at-1])%divisor, divisor,dp);
	int npega = func(at-1,w,valor,divisor,dp);
	return dp[valor][at][w].v = pega+npega;
}

int main(){
	//freopen("saida.txt","w",stdout);
	int Q, num, D;
	int cont = 0;
	while(cin >> N >> Q and N and Q){
		cont++;
		for(int i = 0; i<N; i++){
			cin >> num;
			v.push_back(num);
		}
		cout << "SET " << cont << ":" << endl; 
		for(int i = 0; i<Q; i++){
			cin >> D >> quant;
			 unordered_map<int, unordered_map<int, unordered_map<int,struczera> > > dp; 
			cout << "QUERY " << i+1<< ": "<<func(N,0,0,D,dp) << endl;
		}
		v.clear();
	}
}
