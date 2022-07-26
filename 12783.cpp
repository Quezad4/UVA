#include <bits/stdc++.h>
#define pii pair<pair<int,int>,int>
#define ff first.first
#define fs first.second
#define saida freopen("saida.txt", "w",stdout)
#define maxint 1000000
using namespace std;



vector<int> adjList[1010];
bool vis[1010];
int timer[1010];
int low[1010];
int tps = 0;

set<pair<int,int> > ans;
set<pair<int,int> >::iterator it;




void dfs(int u, int p = -1){
	vis[u] = true;
	timer[u] = low[u] = tps++;
	for(int v:adjList[u]){
		if(!vis[v]){
			dfs(v,u);
			low[u] = min(low[u],low[v]);
			if(timer[u]< low[v]){
				ans.insert({min(u,v), max(u,v)});
			}
		}
		else if(v!= p){
			low[u] = min(low[u], timer[v]);
		}
	}
}

int main(){
	//saida;
	int N, M,x,y;
	cin >> N >> M;
	while(N and M){
		memset(vis,false,sizeof(vis));
		tps = 0;
		for(int i = 0; i<N; i++){
			adjList[i].clear();
		}
		ans.clear();
		for(int i = 0; i<M; i++){
			cin >> x >> y;
			adjList[x].push_back(y);
			adjList[y].push_back(x);
		}
		for(int i = 0; i<N; i++){
			if(!vis[i]){
				dfs(i);
			} 
		}
		cout << ans.size();
		int i = 0;
		for(it = ans.begin(); it!= ans.end(); it++, i++){
			cout << " " << it->first << " " << it->second;
		}
		cout << endl;
		cin >> N >> M;
	}
}
