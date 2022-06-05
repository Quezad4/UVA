#include <bits/stdc++.h>
#define pii pair<pair<int,int>,int>
#define ff first.first
#define fs first.second
#define saida freopen("saida.txt", "w",stdout)
#define int_MAX 10000007
using namespace std;

int N, M;
int matrix[1001][1001];
int dist[1001][1001];
int vx[] = {1,-1,0,0}, vy[] = {0,0,-1,1};

bool isValid(int i, int j){
    if(i<0 or i>= N or j<0 or j>= M){
        return false;
    }
    return true;

}

 void dijkstra(int i, int j){
	priority_queue< pair<int,pair<int,int> >, vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > > fila;
	fila.push({0,{i,j}});
	dist[i][j] = 0;
	while(!fila.empty()){
		int i2 = fila.top().second.first;
        int j2 = fila.top().second.second;
		int w = fila.top().first;
		fila.pop();
		if(w != dist[i2][j2]) continue; 
		for(int k = 0; k<4; k++){
            int ax = i2+vx[k];
            int ay = j2+vy[k];
            if(isValid(ax,ay)){
                int aux = w + matrix[ax][ay];
                if(dist[ax][ay] > aux){
                    dist[ax][ay] = aux;
                    fila.push({aux,{ax,ay}});
			    }
            }
		}
	}
	 
}


int main(){
	int T; cin >> T;
    for(int i = 0; i<T; i++){
        cin >> N >> M;
        for(int j = 0; j<N; j++){
            for(int k = 0; k<M; k++){
                cin >> matrix[j][k];
            }
        }
        for(int j = 0; j<N; j++){
            for(int k = 0; k<M; k++){
                dist[j][k] = 1000000;
            }
        }
        dijkstra(0,0);
        if(N == 1 and M == 1){
            cout << matrix[0][0] << endl;
        }
        else{
            cout << dist[N-1][M-1] + matrix[0][0] << endl;
        }
        
    }

}
