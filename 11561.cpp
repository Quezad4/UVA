#include <bits/stdc++.h>
#define pii pair<pair<int,int>,int>
#define ff first.first
#define fs first.second
using namespace std;
char matrix[51][51];
bool vis[51][51];
int N, M, count1 = 0;
bool isValid(int i, int j){
	if(i<0 or i>=M or j<0 or j>=N or matrix[i][j] == '#' or matrix[i][j] == 'T' or vis[i][j] == true){
		return false;
	}
	return true;
}
bool tADJ(int i, int j){
	if(matrix[i][j+1] == 'T' or matrix[i][j-1] == 'T' or matrix[i+1][j] == 'T' or matrix[i-1][j] == 'T'){
		return true;
	}
	return false;
}
void dfs(int i, int j){
	vis[i][j] = true;
	if(matrix[i][j] == 'G'){
		count1++;
	}
	if(tADJ(i,j) == true){
		return;
	}
	if(isValid(i,j+1)){
		dfs(i,j+1);
	}
	if(isValid(i,j-1)){
		dfs(i,j-1);
	}
	if(isValid(i+1,j)){
		dfs(i+1,j);
	}
	if(isValid(i-1,j)){
		dfs(i-1,j);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin >> N >> M){
		memset(vis,false,sizeof(vis));
		for(int i = 0; i<M; i++){
			for(int j = 0; j<N; j++){
				cin >> matrix[i][j];
			}
		}
		for(int i = 0; i<M; i++){
			for(int j = 0; j<N; j++){
				if(matrix[i][j] == 'P'){
				dfs(i,j);
				}
			}
		}
		cout << count1<< endl;
		count1 =0;
	}
    
}
