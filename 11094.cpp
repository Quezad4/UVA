#include <bits/stdc++.h>
#define pii pair<pair<int,int>,int>
#define ff first.first
#define fs first.second
using namespace std;
vector<int>ans;
char matrix[21][21];
bool vis[21][21];
int vetX[4] = {1,-1,0, 0};
int vetY[4] = {0, 0, 1, -1};
int N, M;
char a;
int count1 = 0;
bool isValid(int i, int j){
	if(i<0 or j<0 or j>=M or i>=N or vis[i][j] == true or matrix[i][j] != a){
		return false;
	}
	return true;
}
void dfs(int i, int j){
	vis[i][j] = true;
	count1++;
	/*for(int n = 0; n<N; n++){
		for(int m = 0; m<M; m++){
			cout << vis[n][m];
		}
		cout << endl;
		
	}
	cout << "---------------------" << "COUNT : " << count1 <<endl;
	*/
	for(int k = 0; k<4; k++){
		if(j+vetY[k]<0){
			j= M;
		}
		if(isValid(i+vetX[k], j+vetY[k])){
			dfs(i+vetX[k], j+vetY[k]);
		}
	}
}

int main(){
	//freopen("saida.txt", "w", stdout);
	//freopen("entrada.txt", "r", stdin);
	int x, y;
	while(cin >> N >> M){
		memset(vis,false,sizeof(vis));
		for(int i = 0; i<N; i++){
			for(int j = 0; j<M; j++){
				cin >> matrix[i][j];
			}
		}
		cin >> x >> y;
		a = matrix[x][y];
		dfs(x,y);
		ans.clear();
		count1 = 0;
		for(int i = 0; i<N; i++){
			for(int j = 0; j<M; j++){
				if(matrix[i][j] == a and vis[i][j] == false){
					dfs(i,j);
					ans.push_back(count1);
					count1 = 0;
				}
			}
		}
		sort(ans.rbegin(), ans.rend());
		if(ans.empty()){
			cout << 0 << endl;
		}
		else{
			cout << ans[0] << endl;
		}
		ans.clear();
		
	}
	
}
