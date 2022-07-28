#include <bits/stdc++.h>
#define pii pair<pair<int,int>,int>
#define ff first.first
#define fs first.second
#define saida freopen("saida.txt", "w",stdout)
#define entrada freopen("entrada.txt", "r", stdin)
#define maxint 1000000
using namespace std;


int N,M;
bool matrix[110][110];
int caralho[110][110];
bool vis[110][110];
set<pair<int,int> > s;
set<pair<int,int> >::iterator it;
int contador = 0;
int par = 0, impar = 0;



bool isValid(int i, int j){
	if(i<0 or i>=N or j<0 or j>=M or matrix[i][j]){
		return false;
	}
	return true;
}


void bfs(int i, int j){
	queue<pair<int,int> > fila;
	fila.push({i,j});
	vis[i][j] = true;                     
	while(!fila.empty()){
		auto x = fila.front(); fila.pop();
		for(it = s.begin(); it!= s.end(); it++){
			int ax = x.first + it->first;
			int ay = x.second + it->second;
			if(isValid(ax,ay)){
				if(!vis[ax][ay]){
					fila.push({ax,ay});
					vis[ax][ay] = true;
				}
				contador++;
			}
		}
		if(contador%2 == 0){
			par++;
		}
		else{
			impar++;
		}
		contador = 0;
	}
}


int main(){
	//saida;
	int t; cin >> t;
	int x,y;
	int buracos,buracoi,buracoj;
	for(int j = 0; j<t; j++){
		memset(matrix,false,sizeof(matrix));
		cin >> N >> M >> x >> y;
		s.insert({x,y});
		s.insert({x,-y});
		s.insert({-x,y});
		s.insert({-x,-y});
		s.insert({y,x});
		s.insert({y,-x});
		s.insert({-y,x});
		s.insert({-y,-x});
		//cout << s.size();
		cin >> buracos;
		for(int i = 0; i<buracos; i++){
			cin >> buracoi >> buracoj;
			matrix[buracoi][buracoj] = true;
		}
		if(x == 0 and y ==0){
			cout << "Case " << j+1 << ": " << 0 << " "<< 0 << endl;
		}
		else{
			bfs(0,0);
			cout << "Case " << j+1 << ": " << par << " "<< impar << endl;
		}
		par = impar = 0;
		s.clear();
		memset(vis,false,sizeof(vis));	
			
	}
}

