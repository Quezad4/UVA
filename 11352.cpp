#include <bits/stdc++.h>
#define pii pair<pair<int,int>,int>
#define ff first.first
#define fs first.second
#define saida freopen("saida.txt", "w",stdout)
using namespace std;
int N,M;
bool vis[101][101];
char matrix[101][101];
int vx[] = {1,-1,0,0,-1,-1,1,1}, vy[] = {0,0,1,-1,1,-1,1,-1};
int vetorCX[8] = {2,-2,1,-1,2,-2,1,-1};
int vetorCY[8] = {-1,1,-2,2,1,-1,2,-2};

bool isValidCavalo(int i, int j){
	if(i<0 or i>=N or j<0 or j>=M or matrix[i][j] == 'A' or matrix[i][j] == 'B' or matrix[i][j] == 'Z'){
		return false;
	}
	return true;
}
void posCavalo(int i, int j){
	for(int k = 0; k<8; k++){
		int ax = i+vetorCX[k];
		int ay = j+vetorCY[k];
		if(isValidCavalo(ax,ay)){
			matrix[ax][ay] = 'x';
		}
	}

}

bool isValidRei(int i, int j){
	if(i<0 or i>=N or j<0 or j>=M or matrix[i][j] == 'x' or vis[i][j] == true ){
		return false;
	}
	return true;
}

int bfs(int i, int j, int d1, int d2){
	queue<pair<pair<int,int>,int> >fila;
	fila.push({{i,j},0});
	vis[i][j] = true;
	while(!fila.empty()){
		pii u = fila.front();
		fila.pop();
		for(int k = 0; k<8; k++){
			int ax = u.ff+vx[k];
			int ay = u.fs+vy[k];
			if(d1 == u.ff and d2 == u.fs){
				return u.second;
			}
			if(isValidRei(ax,ay)){
				fila.push({{ax,ay},u.second+1});
				vis[ax][ay] = true;
			}
		}
	}
	return -1;
	
	
	
}

int main(){
	int reiAi, reiAj;
	int reiBi, reiBj;
	int T; cin>> T;
	for(int k = 0; k<T; k++){
		memset(vis,false,sizeof(vis));
		cin >> N >> M;
		for(int i = 0; i<N; i++){
			for(int j =0; j<M; j++){
				cin >> matrix[i][j];
			}
		}
		for(int i = 0; i<N; i++){
			for(int j =0; j<M; j++){
				if(matrix[i][j] == 'Z'){
					matrix[i][j]='x';
					posCavalo(i,j);
				}
				if(matrix[i][j] == 'A'){
					reiAi = i;
					reiAj = j;
				}
				if(matrix[i][j] == 'B'){
					reiBi = i;
					reiBj = j;
				}
			}
		}
		int L = bfs(reiAi,reiAj,reiBi,reiBj);
		if(L==-1){
			cout << "King Peter, you can't go now!" <<endl;
		}
		else{
			cout << "Minimal possible length of a trip is " << L << endl;
		}
		
	}
}
