#include <bits/stdc++.h>
using namespace std;

vector<int> v;

bool func(int k){
	for(int i = 0; i+1<(int)v.size(); i++){
		
		if(v[i+1]- v[i] > k or k <0) return false;
		
		if(v[i+1] - v[i] == k) 
			k--;
		
	}
	return true;
}

int main(){
	//~ freopen("saida.txt", "w", stdout);
	
	int N, valor;
	int T; cin >> T;
	for(int i = 0; i<T; i++){
		cin >> N;
		v.push_back(0);
		for(int j = 0; j<N; j++){
			cin >> valor;
			v.push_back(valor);
		}
		int l= 1, r = 1e9;
		while(l<r){
			int mid = (l+r)/2;
			if(func(mid)){ // meu valor é grande demais, posso ir pra esquerda
				r = mid;
			}
			else{
				l = mid+1;
			} 
			//~ cout << l << "  " << r << endl;
		}
		cout << "Case " << i+1 << ": " << r << endl;
		v.clear();
	}
}
