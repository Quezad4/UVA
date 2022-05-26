#include <bits/stdc++.h>
#define pii pair<pair<int,int>,int>
#define ff first.first
#define fs first.second
using namespace std;
char matrix[110][110];
int N, M, count1 = 0;
bool isValid(int i, int j){
	
	if(i<0 or i>=M or j<0 or j>=M or matrix[i][j] == '.'){
		return false;
	}
	return true;
}
void dfs(int i, int j){
	if(matrix[i][j] == '@' or matrix[i][j] == 'x'){
		matrix[i][j] = '.';
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
	cin >> N;
    for(int i = 0; i<N; i++){
		cin >> M;
		//memset(matrix, '.', sizeof matrix);
		for(int j = 0; j<M; j++){
			for(int k = 0; k<M; k++){
				cin >> matrix[j][k];
			}
		}
		for(int j = 0; j<M; j++){
			for(int k = 0; k<M; k++){
				if(matrix[j][k] == 'x'){
					dfs(j,k);
					count1++;
				}
			}
		}
		cout << "Case " << i+1 << ": " << count1 << endl; 
		count1 = 0;
		
		
	}
    
}
