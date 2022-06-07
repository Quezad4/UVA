#include <bits/stdc++.h>
#define pii pair<pair<int,int>,int>
#define ff first.first
#define fs first.second
#define saida freopen("saida.txt", "w",stdout)
#define maxint 1000000
using namespace std;

vector <int> adjList[100010];
vector<int> adjList2[100010];
bool vis[100010];
stack <int> s;


void dfs1(int u){
    vis[u] = true;
    for(int v: adjList[u]){
        if(vis[v] == false){
            dfs1(v);
        }
    }
    s.push(u);
}

void dfs2(int u){
    vis[u] = true;
    for(int v: adjList[u]){
        if(vis[v] == false){
            dfs2(v);
        }
    }
}

int main(){
    int N,M,T; cin >> T;
    int x, y, count = 0;
    string str;
    for(int i = 0; i<T; i++){
        cin >> N >> M;
        for(int j = 0;j<M; j++){
            cin >> x >> y;
            adjList[x].push_back(y);
            adjList2[y].push_back(x);
        }
        if(i == 0){
            cin.ignore();
            getline(cin,str);
        }
        else{
            getline(cin,str);
        }
        for(int j = 1; j<=N; j++){
            if(vis[j] == false){
                dfs1(j);
            }
        }
        memset(vis,false,sizeof(vis));
        while(!s.empty()){
            int aux = s.top(); s.pop();
            if(vis[aux] == false){
                count++;
                dfs2(aux);
            }
        }

        cout << "Case " << i+1 << ": " << count << endl;
        count = 0;
        for(int j = 1; j<=N; j++){
            adjList2[j].clear();
            adjList[j].clear();
        }
        memset(vis,false,sizeof(vis));
    }

}
