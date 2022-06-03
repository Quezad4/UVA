#include <bits/stdc++.h>
#define pii pair<pair<int,int>,int>
#define ff first.first
#define fs first.second
#define saida freopen("saida.txt", "w",stdout)
#define int_MAX 10000007
using namespace std;

vector<pair<int,int> >adjList[102];
set<int> s;
int dist[102];



 void dijkstra(int u){
	priority_queue< pair<int,int>, vector<pair<int,int> >,greater<pair<int,int> > > fila;
	fila.push({0,u});
	dist[u] = 0;
	while(!fila.empty()){
		int u = fila.top().second;
		int w = fila.top().first;
		fila.pop();
		if(w > dist[u]) continue; 
		for(auto x:adjList[u]){
			int aux = w+x.first;
			if(dist[x.second] > aux){
				dist[x.second] = aux;
				fila.push({aux,x.second});
			}
		}
	}
	 
}


int main(){
	int T, V, E, tempo, a, b, w, M, count = 0;
	string esp;
	cin >> T;
	
	for(int i = 0; i<T; i++){
		if(i == 0){
			cin.ignore();
			getline(cin,esp);
			
		}
		else{
			getline(cin,esp);
		}
		cin >> V >> E >> tempo;
		cin>> M;
		for(int j = 0; j<M; j++){
			cin >> a >> b >> w;
			adjList[a].push_back({w,b});
		}
		for(int aaa = 1; aaa<=V; aaa++){
			for(int j = 1; j<=V; j++){
				dist[j] = 100000;
			}
			dijkstra(aaa);
			if(dist[E] <= tempo and dist[E] != 0){
				count++;
			}
			
		}
		if(i == T-1){
			cout << count+1 << endl;
		}
		else{
			cout << count+1 << endl;
			cout << endl;
		}
		count = 0;
		for(int aaa = 1; aaa<=V; aaa++){
			adjList[aaa].clear();
		}
	}
}
