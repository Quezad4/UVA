#include <bits/stdc++.h>
#define pii pair<pair<int,int>,int>
#define ff first.first
#define fs first.second
#define saida freopen("saida.txt", "w",stdout)
#define maxint 1000000
using namespace std;


vector<pair<int,int> > adjList[110];
set<int> num;
int dist[110][110];
int maior = -1;


void floydWarshal(){
    for(int k = 1; k<=maior; k++){
        for(int i = 1; i<=maior; i++){
            for(int j = 1; j<=maior; j++){
                if(dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

void iniciate(){
    for(int i = 1; i<=maior; i++){
        for(int j = 1; j<=maior; j++){
            dist[i][j] = 1000000;
        }
    }
    for(int i = 1; i<=maior; i++){
        for(auto j: adjList[i]){
            dist[i][j.second] = j.first;
        }
    }
}




int main(){
    int X,Y,x,y;
    int caso = 1, soma = 0;
    cin >> X >> Y;
    while(X or Y){
        if(maior < X) maior = X;
        if(maior < Y) maior = Y;
        num.insert(X); num.insert(Y);
        adjList[X].push_back({1,Y});
        cin >> x >> y;
        while(x or y){
            if(maior < x) maior = y;
            if(maior < y) maior = y;
            num.insert(x); num.insert(y);
            adjList[x].push_back({1,y});
            cin >> x >> y;
        }
        iniciate();
        floydWarshal();
        for(int i = 1; i<=maior; i++){
            for(int j = 1; j<=maior; j++){
                if(i == j){
                    dist[i][j] = 0;
                }
            }
        }
        for(int i = 1; i<=maior; i++){
            for(int j = 1; j<=maior; j++){
                if(dist[i][j] != 1000000){
                    soma += dist[i][j];
                }
               
            }
        }
        cout << fixed;
        cout.precision(3);
        cout << "Case " << caso << ": average length between pages = " << (float)soma/(num.size() * (num.size()-1)) << " clicks" << endl;
        caso++;
        for(int i = 0; i<=maior; i++){
            adjList[i].clear();
        }
        soma = 0;
        maior = -1;
        num.clear();
        cin >> X >> Y;
    }
}
