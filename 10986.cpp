#include <bits/stdc++.h>
#define pii pair<pair<int,int>,int>
#define ff first.first
#define fs first.second
#define saida freopen("saida.txt", "w",stdout)
#define int_MAX 10000007
using namespace std;

int N, M;
int dist[20010];
vector<pair<int,int> > adjList[20010];

void dijkstra(int u){
     priority_queue<pair<int,int>, vector<pair<int,int> > , greater<pair<int,int> > > fila;
	fila.push({0,u});
	dist[u] = 0;
    while(!fila.empty()){
        int u = fila.top().second;
        int w = fila.top().first;
        fila.pop();
        if(w > dist[u]) continue;
        for(auto x: adjList[u]){
            int aux = w + x.first;
            if(dist[x.second] > aux){
                dist[x.second] = aux;
                fila.push({aux,x.second});
            }
        }
    }
	 
}


int main(){
    int num, N, M , S, T, x, y , w; 
    cin >> num;
    for(int i = 0; i<num; i++){
        cin >> N >> M >> S >> T;
        for(int j = 0; j<M; j++){
            cin >> x >> y >> w;
            adjList[x].push_back({w,y});
            adjList[y].push_back({w,x});
        }
        for(int j = 0; j<N; j++){
            dist[j] = 1000000;
        }
        dijkstra(S);
        for(int j = 0; j<N; j++){
            adjList[j].clear();
        }
        if(dist[T] == 1000000){
            cout << "Case #" << i+1 << ": " << "unreachable" << endl;
        }
        else{
            cout << "Case #" << i+1 << ": " << dist[T] << endl;
        }
        
    }

}
