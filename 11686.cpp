#include <bits/stdc++.h>
#define pii pair<pair<int,int>,int>
#define ff first.first
#define fs first.second
#define saida freopen("saida.txt", "w",stdout)
using namespace std;
vector<int> adjList[1000001];
bool vis[1000001];
bool recStack[1000001];
set<int>fodasse;
stack<int>s;



bool isCycle(int u){
	if(vis[u] == false){
		vis[u] = true;
		recStack[u] = true;
	}
	for(int v:adjList[u]){
		if(!vis[v] and isCycle(v)){
			return true;
		}
		else if(recStack[v]){
			return true;
		}
	}
	recStack[u] = false;
	return false;
}

void tSort(int i){
	vis[i] = true;
	for(int v:adjList[i]){
		if(vis[v] == false){
			tSort(v);
		}
	}
	s.push(i);
	
}

int main(){
	int x, y, N, M;
	cin >> N >> M;
	while(N or M){
		memset(vis,false,sizeof(vis));
		memset(recStack,false,sizeof(recStack));
		for(int i = 0; i<M; i++){
			cin >> x >> y;
			adjList[x].push_back(y);
		}
		for(int i = 1; i<=N; i++){
			if(!vis[i] and isCycle(i)){
				fodasse.insert(1);
			}
			else{
				fodasse.insert(0);
			}
		}
		if(fodasse.size() == 2){
			cout << "IMPOSSIBLE" <<endl;
		}
		else{
			memset(vis,false,sizeof(vis));
			for(int j = 1; j<=N; j++){
				if(vis[j] == false){
					tSort(j);
				}
			
			}
			while(!s.empty()){
				cout << s.top() << endl;
				s.pop();
			}
		}
		for(int df = 0; df<=N; df++){
			adjList[df].clear();
		}
		fodasse.clear();
		cin >> N >> M;
	}
	cout << endl;
}
