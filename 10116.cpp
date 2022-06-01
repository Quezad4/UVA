#include <bits/stdc++.h>
#define pii pair<pair<int,int>,int>
#define ff first.first
#define fs first.second
#define saida freopen("saida.txt", "w",stdout)
using namespace std;
int N, M;
char matrix[11][11];
int vis[11][11];
int count1 = 0;
bool contador = true;
bool isValid(int i, int j){
    if(i<0 or i>=N or j<0 or j>=M){
        return false;
    }
    if(vis[i][j] == 1 and contador){
		vis[i][j] = 2;
		contador = false;
		return false;
	}
	if(vis[i][j] == 1 or vis[i][j] == 2){
		return false;
	}
    return true;
}


void dfs(int i, int j){
    vis[i][j] = true;
    count1 ++;
    if(matrix[i][j] == 'W' and isValid(i,j-1)){
        dfs(i,j-1);
    }
    if(matrix[i][j] == 'S' and isValid(i+1,j)){
        dfs(i+1,j);
    }
    if(matrix[i][j] == 'N' and isValid(i-1,j)){
        dfs(i-1,j);
    }
    if(matrix[i][j] == 'E' and isValid(i,j+1)){
        dfs(i,j+1);
        
    }
    
}

int main(){
	int ans1 = 0;
    int origem;
    cin >> N >> M>> origem;
    while(N or M or origem){
        memset(vis,false,sizeof(vis));
        for(int i = 0; i<N; i++){
            for(int j = 0; j<M; j++){
                cin >> matrix[i][j];
            }
        }
        dfs(0,origem-1);
        ans1 = count1;
        count1 =0;
        for(int i = 0; i<N; i++){
            for(int j = 0; j<M; j++){
                if(vis[i][j] == 2){
					memset(vis,false,sizeof(vis));
					dfs(i,j);
					i = N;
					j = M;
				}
            }
        }
        if(contador == true){
			cout << ans1 << " step(s) to exit" << endl;
		}
		else{
			cout << abs(count1-ans1) << " step(s) before a loop of " << count1 <<" step(s)" << endl; 
		}
        count1 = 0;
        cin >> N >> M >> origem;
		contador = true;
    }
}
