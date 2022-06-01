#include <bits/stdc++.h>
#define pii pair<pair<int,int>,int>
#define ff first.first
#define fs first.second
#define saida freopen("saida.txt", "w",stdout)
using namespace std;
int N, M;
bool matrix[1010][1010];
bool vis[1010][1010];
int vX[4] = {0,0,1,-1};
int vY[4] = {1,-1,0,0};
bool isValid(int i, int j){
    if(i<0 or i>=N or j<0 or j>=M or matrix[i][j] == true or vis[i][j] == true){
        return false;
    }
    return true;
}

int bfs(int i, int j, int x, int y){
    queue<pair<pair<int,int>,int > >fila;
    vis[i][j] = true;
    fila.push({{i,j},0});
    while(!fila.empty()){
        pii u = fila.front(); fila.pop();
        for(int k = 0; k<4; k++){
            int ax = u.ff+vX[k];
            int ay = u.fs+vY[k];
            if(x == u.ff and y == u.fs){
                return u.second;
            }
            if(isValid(ax,ay)){
                fila.push({{ax,ay},u.second+1});
                vis[ax][ay] = true;
            }
        }

    }

}

int main (){
    int nLinhas, rowBomb, numBomb, columBomb;
    int origem1, origem2, dest1, dest2;
    cin >> N >> M;
    while(N or M){
        cin >> nLinhas;
        for(int i = 0; i< nLinhas; i++){
            cin >> rowBomb >> numBomb;
            for(int j = 0; j<numBomb; j++){
                cin >> columBomb;
                matrix[rowBomb][columBomb] = true;
            }

        }
        cin >> origem1 >> origem2;
        cin >> dest1 >> dest2;
        cout << bfs(origem1,origem2,dest1,dest2) << endl;
        memset(vis,false,sizeof(vis));
        memset(matrix, false, sizeof matrix);
        cin >> N >> M;
    }
}
