#include <bits/stdc++.h>
#define pii pair<pair<int,int>,int>
#define ff first.first
#define fs first.second
#define saida freopen("saida.txt", "w",stdout)
using namespace std;
vector<int> adjList[110];
stack<int> s;
bool vis[110];


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
		for(int i = 0; i<M; i++){
			cin >> x >> y;
			adjList[x].push_back(y);
		}
		for(int j = 1; j<=N; j++){
			if(vis[j] == false){
				tSort(j);
			}
			
		}
		int b = s.size();
		for(int j = 0; j<b; j++){
			if(j == b-1){
				cout << s.top() << endl;
				s.pop();
			}
			else{
				cout << s.top() << " ";
				s.pop();
			}
		}
		cin >> N >> M;
	}
}
