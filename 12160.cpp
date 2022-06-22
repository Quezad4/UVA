#include <bits/stdc++.h>
#define pii pair<pair<int,int>,int>
#define ff first.first
#define fs first.second
#define saida freopen("saida.txt", "w",stdout)
#define maxint 1000000
using namespace std;

vector<int> v;
bool vis[100010];


int bfs(int o, int d){
	queue<pair<int,int> > fila; 
	fila.push({o,0});
	vis[o] = true;
	while(!fila.empty()){
		auto u = fila.front();
		fila.pop();
		//cout << u.first << "  ASHDJKASDASDJH" << endl;
		if(u.first == d){
			return u.second;
		}
		for(int i = 0; i<v.size(); i++){
			int a = u.first + v[i];
			if(vis[a] == false){
				if(a > 9999){
					a -= 10000;
					fila.push({a,u.second+1});
					vis[a] = true;
				}
				else{
					fila.push({a,u.second+1});
					vis[a] = true;
				}
			}
		}
	}
	return -1;
}





int main(){
	int caso = 1;
	int origem, destino, num, x;
	cin >> origem >> destino >> num;
	while(origem or destino or num){
		memset(vis,false,sizeof(vis));
		for(int i = 0; i<num; i++){
			cin >> x;
			v.push_back(x);
		}
		int valor = bfs(origem,destino);
		if(valor == -1){
			cout << "Case " << caso <<":" << " Permanently Locked" << endl;
		}
		else{
			cout << "Case " << caso <<": " << valor << endl;
		}
		cin >> origem >> destino >> num;
		v.clear();
		caso++;
	}
}
