#include <bits/stdc++.h>
using namespace std;

int dist[27][27];
int pai[27][27];
vector<int> caminho;
vector<pair<int,int> > adjList[27];

void iniciate(int n){
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			dist[i][j] = 1000000;
		}
		dist[i][i] = 0;
	}
	for(int i = 0; i<n; i++){
		for(auto j:adjList[i]){
			pai[i][j.second] = i;
			dist[i][j.second] = j.first;
		}
	}
}


void floydWarshall(int n){
	for(int k = 0; k<n; k++){
		for(int i = 0; i<n; i++){
			for(int j = 0; j<n; j++){
				if(dist[i][j] > dist[i][k] + dist[k][j]){
					dist[i][j] = dist[i][k] + dist[k][j];
					pai[i][j] = pai[k][j];
				}
			}
		}
	}
}

int main(){
	int N, M, w, tam;
	char str1, str2;
    cin >> N >> M;
    for(int i = 0; i<M; i++){
		cin >> str1 >> str2 >> w;
		int x = str1-65;
		int y = str2-65;
		adjList[x].push_back({w,y});
		adjList[y].push_back({w,x});
	}
	memset(pai,-1,sizeof(pai));
    iniciate(N);
	floydWarshall(N);
	cin >> tam;
	char x1, x2;
	for(int i = 0; i<tam; i++){
		cin >> x1 >> x2;
		int x = x1-65;
		int y = x2-65;
		caminho.push_back(y);
		while(pai[x][y]!=-1){
            y=pai[x][y];
            caminho.push_back(y);
        }
        reverse(caminho.begin(),caminho.end());
        for(int j = 0; j<(int)caminho.size(); j++){
			if(j == (int)caminho.size() - 1){
				cout << (char)(caminho[j]+65) << endl;
			}
			else{
				cout << (char)(caminho[j]+65) << " "; 
			}
		}
		caminho.clear();
	}
}
