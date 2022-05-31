#include <bits/stdc++.h>
#define pii pair<pair<int,int>,int>
#define ff first.first
#define fs first.second
#define saida freopen("saida.txt", "w",stdout)
using namespace std;
bool vis[100001];
vector<int> adjList[100001];
stack<int> s;


void dfs(int u){
	vis[u] = true;
	for(int v:adjList[u]){
		if(vis[v] == false){
			dfs(v);
		}
	}
	s.push(u);
}

void dfs2(int u){
	vis[u] = true;
	for(int v:adjList[u]){
		if(vis[v] == false){
			dfs2(v);
		}
	}
}

int main(){
	int NUM, V, E,x ,y, count = 0;
	cin >> NUM;
	for(int i = 0; i<NUM; i++){
		memset(vis,false,sizeof(vis));
		cin>> V >> E;
		for(int j = 0; j<E; j++){
			x--;y--;
			cin >> x >> y;
			adjList[x].push_back(y);
		}
		for(int k =0; k<=V; k++){
			if(vis[k] == false){
				dfs(k);
			}
		}
		memset(vis,false,sizeof(vis));
		while(!s.empty()){
			int u = s.top();
			s.pop();
			if(vis[u] == false){
				dfs2(u);
				count++;
			}
		}
		cout << count-1<< endl;
		for(int fg = 0; fg<=V; fg++){
			adjList[fg].clear();
		}
		count = 0;
	}
}
