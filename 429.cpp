#include <bits/stdc++.h>
#define pii pair<pair<int,int>,int>
#define ff first.first
#define fs first.second
#define saida freopen("saida.txt", "w",stdout)
#define maxint 1000000
using namespace std;


vector<string> v;
map<string,bool> vis;
map<string,bool>::iterator it;

int bfs(string origem, string destino){
	queue<pair<string,int> > fila;
	fila.push({origem,0});
	vis[origem] = true;
	int count = 0;
	while(!fila.empty()){
		auto u = fila.front(); fila.pop();
		if(u.first == destino){
			return u.second;
		}
		for(int i = 0; i<v.size(); i++){
			if(u.first.size() != v[i].size()) continue;
			else{
				for(int k = 0; k<v[i].size(); k++){
					if(u.first[k] != v[i][k]){
						count++;
					}
				}
				if(count == 1 and vis[v[i]] == false){
					fila.push({v[i],u.second+1});
					vis[v[i]] = true;
				}
				count = 0;
			}
		}
	}
	return -1;
	
}





int main(){
	int N;
	cin >> N;
	string a, c, origem , destino, palavra,cacete;
	cin.ignore();
	for(int i = 0; i<N; i++){
		if (i ==0){
			getline(cin, c);
		}
		cin >> palavra;
		while(palavra != "*"){
			v.push_back(palavra);
			cin >> palavra;
			
		}
		cin.ignore();
		getline(cin,cacete);
		while(cacete != "\0"){
			string conca = "";
			for(int j = 0; j<cacete.size(); j++){
				if(cacete[j] == ' '){
					origem = conca;
					conca = "";
				}
				else{
					conca += cacete[j];
				}
			}
			vis.clear();
			destino = conca;
			cout << origem << " " << destino << " " << bfs(origem,destino) << endl;
			getline(cin,cacete);
		}
		if(i != N-1){
			cout << endl;
		}
		v.clear();
	}
}
