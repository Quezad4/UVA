#include <bits/stdc++.h>
using namespace std;

int dist1[10010][10010];
int dist2[10010][10010];


void floydWarshall(int tam){
	for(int k = 0; k<tam; k++){
		for(int i = 0; i<tam; i++){
			for(int j = 0; j<tam; j++){
				if(dist1[i][j] > dist1[i][k] + dist1[k][j]){
					dist1[i][j] = dist1[i][k] + dist1[k][j];
				}
			}
		}
	}
}



void iniciate(int N){
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            dist1[i][j] = 1000000;
        }
        dist1[i][i] = 0;
	}
       
}

int main(){
    int N,tam, tam2;
    string blankspace;
    char str1, str2;
    cin >> N;
    cin.ignore();
	getline(cin,blankspace);
    for(int k = 0; k<N; k++){
		cin >> tam;
		iniciate(tam);
		for(int i = 0; i<tam; i++){
			cin >> str1 >> str2;
			int x = str1-65;
			int y = str2-65;
			dist1[x][y] = 1;
		}
		floydWarshall(tam);
		cin >> tam2;
		bool ok = true;
		for(int i = 0; i<tam2; i++){
			cin >> str1 >> str2;
			int x = str1-65;
			int y = str2-65;
			if(dist1[x][y] == 1000000){
				ok = false;
			}
		}
		if(tam2 == 0){
			ok = false;
		}
		if(ok == true){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl; 
		}
		if(k<tam-1){
			cout << endl;
		}
	}
}
