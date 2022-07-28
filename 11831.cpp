#include <bits/stdc++.h>
#define pii pair<pair<int,int>,int>
#define ff first.first
#define fs first.second
#define saida freopen("saida.txt", "w",stdout)
#define entrada freopen("entrada.txt", "r", stdin)
#define maxint 1000000
using namespace std;


int x,y;
char matrix[110][110];
vector<char> v;


int vx[] = {-1,0,1,0};
int vy[] = {0,1,0,-1};



int main(){
	int z;
	int posi, posj;
	char aux;
	int cabeca, contador = 0;
	cin >> x >> y >> z;
	while(x and y and z){
		for(int i = 0; i<x; i++){
			for(int j = 0; j<y; j++){
				cin >> matrix[i][j];
			}
		}
		for(int k = 0; k<z; k++){
			cin >> aux;
			v.push_back(aux);
		}
		for(int k = 0; k<x; k++){
			for(int l = 0; l<y; l++){
				if(matrix[k][l] == 'N'){
					cabeca = 0;
					posi = k;
					posj = l; 
				}
				if(matrix[k][l] == 'S'){
					cabeca = 2;
					posi = k;
					posj = l;  
				}
				if(matrix[k][l] == 'L'){
					cabeca = 1;
					posi = k;
					posj = l;  
				} 
				if(matrix[k][l] == 'O'){
					cabeca = 3;
					posi = k;
					posj = l;  
				} 
			}
		}
		for(int k = 0; k<v.size(); k++){
			if(v[k] == 'D'){
				cabeca = (cabeca+1)%4;
			}
			if(v[k] == 'E'){
				cabeca = (cabeca-1);
				if(cabeca<0) cabeca+=4;
			}
			if(v[k] == 'F'){
				if(isValid(posi+vx[cabeca], posj+vy[cabeca])){
					posi += vx[cabeca];
					posj += vy[cabeca];
					if(matrix[posi][posj] == '*'){
						contador++;
					}
					matrix[posi][posj] = '.';
				}
			}
		}
		//~ for(int k = 0; k<x;k++){
			//~ for(int l =0; l<y; l++){
				//~ cout << matrix[k][l];
			//~ }
			//~ cout << endl;
		//~ }
		cout << contador << endl;
		contador =0;
		v.clear();
		cin >> x >> y >> z;
	}
		
}

