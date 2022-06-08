#include <bits/stdc++.h>
#define pii pair<pair<int,int>,int>
#define ff first.first
#define fs first.second
#define saida freopen("saida.txt", "w",stdout)
#define maxint 1000000
using namespace std;


vector<int> adjList[210];
bool cor[210];
bool vis[210];

bool dfs(int u){
	for(int v:adjList[u]){
		if( vis[v] == false){
			cor[v] = !cor[u];
			vis[v] = true;
			if(dfs(v) == false){
				return false;
			}
		}
		else{
			if(cor[u] == cor[v]){
				return false;
			}
		}
	}
	return true;
}



int main(){
	int N,M,x,y; cin >> N;
	while(N){
		cin >> M;
		for(int i = 0; i<M; i++){
			cin >> x >> y;
			adjList[x].push_back(y);
			adjList[y].push_back(x);
		}
		vis[0] = true;
		if(dfs(0) == false){
			cout << "NOT BICOLORABLE." << endl;
		}
		else{
			cout << "BICOLORABLE." << endl;
		}
		for(int i = 0; i<N; i++){
			adjList[i].clear();
		}
		memset(vis,false,sizeof(vis));
		memset(cor,false,sizeof(cor));
		cin >> N;
	}
    
}
