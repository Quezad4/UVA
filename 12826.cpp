#include <bits/stdc++.h>
#define pii pair<pair<int,int>,int>
#define ff first.first
#define fs first.second
#define saida freopen("saida.txt", "w",stdout)
#define maxint 1000000
using namespace std;

int N, M;
bool matrix[9][9];
bool vis[9][9];
int vx[] = {1,-1,0,0,-1,-1,1,1}, vy[] = {0,0,1,-1,1,-1,1,-1};

bool isValid(int i, int j){
    if(i<0 or i>=8 or j<0 or j>=8 or matrix[i][j] == true or vis[i][j] == true){
        return false;
    }
    return true;
}

int bfs(int i, int j, int o1, int o2){
    queue<pair<pair<int,int>, int> > fila;
	 vis[i][j] = true;
    fila.push({{i,j},0});
    while(!fila.empty()){
        pii u = fila.front();
        fila.pop();
        for(int k = 0; k<8; k++){
            int ax = u.first.first+vx[k];
            int ay = u.first.second+vy[k];
            if(o1 == u.first.first and o2 == u.first.second){
                return u.second;
            }
            if(isValid(ax,ay)){
                fila.push({{ax,ay},u.second+1});
                vis[ax][ay] = true;
            }
        }
    }
}


int main(){
    int r1,r2,r3,c1,c2,c3;
    int num = 0;
    while(cin >> r1  >> c1 >> r2  >> c2 >> r3 >> c3){
        num++;
        memset(vis,false,sizeof(vis));
        memset(matrix,false,sizeof(matrix));
        matrix[r3-1][c3-1] = true;
        cout << "Case " << num << ": " << bfs(r1-1,c1-1,r2-1,c2-1) << endl;
        
    }
}
