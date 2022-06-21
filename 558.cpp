#include <bits/stdc++.h>
#define pii pair<pair<int,int>,int>
#define ff first.first
#define fs first.second
#define saida freopen("saida.txt", "w",stdout)
#define maxint 1000000000
using namespace std;

int N,M;
vector<pair<int,int> > adjList[10100];
int dist[10100];



bool belmanFord(){
	for(int i = 0; i<N-1; i++){
		for(int u = 0; u<N; u++){
			for(auto j : adjList[u]){
				if(dist[u] + j.second < dist[j.first]){
					dist[j.first] = dist[u] + j.second;
				}
			}
		}
	}
	for(int u = 0; u<N; u++){
		for(auto j : adjList[u]){
			if(dist[u] + j.second < dist[j.first]){
				return false;
			}
		}
	}
	return true;
}


int main(){
	//saida;
	int T; cin >> T;
	int x, y, w;
	for(int i = 0; i<T;i++){
		cin >> N >> M;
		for(int j = 0; j<M; j++){
			cin >> x >> y >> w;
			adjList[x].push_back({y,w});
		}
		for(int j = 0; j<N; j++){
			dist[i] = maxint;
		}
		if(belmanFord() == false){
			cout << "possible" << endl;
		}
		else{
			cout << "not possible" << endl;
		}
		for(int j = 0; j<N; j++){
			adjList[j].clear();
		}
	}
}
