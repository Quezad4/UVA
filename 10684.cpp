#include <bits/stdc++.h>
using namespace std;





int main(){
	int x, num;
	int maior = -1, soma = 0;
	while(cin >> x and x){
		int vet[x];
		for(int i = 0; i<x; i++){
			cin >> num;
			vet[i] = num;
		}
		for(int i = 0; i<x; i++){
			soma += vet[i];
			if(soma> maior) maior = soma;
			if(soma<0) soma = 0; 
		}
		if(maior>0) cout << "The maximum winning streak is " << maior << "." << endl;
		else cout << "Losing streak." << endl;
		maior = -1;
		soma = 0;
		
	}
}
