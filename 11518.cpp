#include <bits/stdc++.h>
#define pii pair<pair<int,int>,int>
#define ff first.first
#define fs first.second
#define saida freopen("saida.txt", "w",stdout)
using namespace std;

vector<int>adjList[10010];
vector<int>mao;
bool vis[10010];
int count1 =0;

void dfs(int u){
	vis[u] = true;
	count1++;
	for(int v: adjList[u]){
		if(vis[v] == false){
			dfs(v);
		}
	}
}


int main(){
	int N, V, E, x, y, M,z;
	cin >> N;
	for(int i = 0; i<N; i++){
		cin >> V >> E >> M;
		for(int j = 0; j<E; j++){
			cin >> x >> y;
			x--; y--;
			adjList[x].push_back(y);
		}
		for(int j = 0; j<M; j++){
			cin >> z;
			z--;
			mao.push_back(z);
		}
		int b = mao.size();
		for(int j = 0; j<b; j++){
			if(vis[mao[j]] == false){
				dfs(mao[j]);
			}
		}
		memset(vis,false,sizeof(vis));
		for(int j = 0; j<V; j++){
			adjList[j].clear();
		}
		mao.clear();
		cout << count1 << endl;
		count1 = 0;
	}
}
