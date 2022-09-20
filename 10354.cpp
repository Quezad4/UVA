#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int> > adjList[110];
int dist[110][110];
int dist2[110][110];
bool distbool[110];
vector<int> caminhoboss;

void floydWarshall(int N){
    for(int k = 1; k<=N; k++){
        for(int i = 1; i<=N; i++ ){
            for(int j = 1; j<=N; j++){
                if(dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}


void floydWarshall2(int N){
    for(int k = 1; k<=N; k++){
        for(int i = 1; i<=N; i++ ){
            for(int j = 1; j<=N; j++){
                if(dist2[i][k] + dist2[k][j] < dist2[i][j] and !distbool[k] and !distbool[i] and !distbool[j]){
                    dist2[i][j] = dist2[i][k] + dist2[k][j];
                }
            }
        }
    }
}



void iniciate(int N){
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=N; j++){
            dist[i][j] = 1000000;
              
        }
        dist[i][i] = 0;
    }
    for(int u = 1; u<=N; u++){
        for(auto v: adjList[u]){
            dist[u][v.second] = v.first;
        }
    }
}

void iniciate2(int N){
	memset(distbool,false,sizeof(distbool));
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=N; j++){
            dist2[i][j] = 1000000;
                
        }
        dist2[i][i] = 0;
    }
    for(int u = 1; u<=N; u++){
        for(auto v: adjList[u]){
            dist2[u][v.second] = v.first;
        }
    }
}

int main(){
	//freopen("saida.txt", "w", stdout);
	//freopen("entrada.txt", "r", stdin);
    int p, r, bh, of, yh, m;
    int x, y, w;
    while(cin >> p >> r >> bh >> of >> yh >> m){
        for(int i = 0; i < r; i++){
            cin >> x >> y >> w;
            adjList[x].push_back({w,y});
            adjList[y].push_back({w,x});
        }
        iniciate(p);
        floydWarshall(p);
		iniciate2(p);
        distbool[bh] = true;
        distbool[of] = true;
        for(int k = 1; k<=p; k++){
			if(dist[bh][of] == dist[bh][k] + dist[k][of]){
				distbool[k] = true;
			}
		}
		floydWarshall2(p);
		if(dist2[yh][m] == 1000000 or distbool[yh] or distbool[m]){
			cout << "MISSION IMPOSSIBLE." << endl;
		}
		else{
			cout << dist2[yh][m] << endl;
		}
        for(int k = 0; k<=p; k++){
			adjList[k].clear();
		}
        caminhoboss.clear();     
    }
}
