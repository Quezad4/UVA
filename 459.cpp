#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#define pii pair<pair<int,int>,int>
#define ff first.first
#define fs first.second
using namespace std;
int N,M,L;
bool vis[10000];
vector<int>adjList[10000];
vector<int>mao;
int count1 =0;

void dfs(int u){
    vis[u] = true;
    for(int v:adjList[u]){
        if(vis[v] == false ){
            dfs(v);
        }
    }
}



int main(){
    //freopen("saida.txt", "w", stdout);
    //freopen("entrada.txt", "r", stdin);
    int N, count =0; cin >> N;
    char nV;
    string a, b;
    for(int i = 0; i<N; i++){
        memset(vis,false,sizeof(vis));
        if (i == 0){
            getline(cin, a);
        }
        cin >> nV;
        cin.ignore();
        getline(cin, b);
        while(b != ""){
            adjList[b[0]-65].push_back(b[1]-65);
            adjList[b[1]-65].push_back(b[0]-65);
            getline(cin, b);
        }
        for(int j = 0; j<nV-64; j++){
            if(vis[j] == false){
                dfs(j);
                count++;
            }
        }
        cout << count << endl;
        if(i < N-1){
            cout << endl;
        }
        count = 0; 
        for(int j = 0; j<nV-64; j++){
            adjList[j].clear();
        }
    }
}
