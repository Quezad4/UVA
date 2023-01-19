#include <bits/stdc++.h>
using namespace std;



bool kmp(string s, int valor){
	int n = s.size();
	vector<int> v(n);
	for(int i = 1; i<n; i++){
		int j = v[i-1];
		while(j>0 and s[i] != s[j]){
			j = v[j-1];
		}
		if(s[i] == s[j]){
			j++;
		}
		v[i] = j;
		if(valor == j) return false;
	}
	return true;
	
	
}


int main(){
	int T; cin >> T;
	int q;
	string palavra, querie;
	vector<int> v2;
	for(int i = 0; i<T; i++){
		cin >> palavra;
		cin >> q;
		for(int j = 0; j<q; j++){
			cin >> querie;
			string palavra2 = querie + "#" + palavra;
			bool ok = kmp(palavra2,querie.size());
			if(ok == true) cout << "n" << endl;
			else cout << "y" << endl;
		}
	}
	
}
