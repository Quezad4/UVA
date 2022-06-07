#include <bits/stdc++.h>
#define pii pair<pair<int,int>,int>
#define ff first.first
#define fs first.second
#define saida freopen("saida.txt", "w",stdout)
#define maxint 1000000
using namespace std;


vector<int> adjList[101];
bool vis[101];
vector<int>v;
void dfs(int u){
    for(int v:adjList[u]){
        if(vis[v] == false){
            vis[v] = true;
            dfs(v);
        }
    }
}


int main(){
    int N, x, y, z ,num;
    cin >> N;
    while(N){
        cin >> x;
        while(x){
            cin >> y;
            while(y){
                adjList[x].push_back(y);
                cin >> y;
            }
            cin >> x;
        }
        cin >> num;
        for(int i = 0; i<num; i++){
            v.clear();
            memset(vis,false,sizeof(vis));
            cin >> z;
            dfs(z);
            for(int j = 1; j<=N; j++){
               if(vis[j] == false){
                   v.push_back(j);
               }
            }
            if(v.size() == 0){
                cout << 0 << endl;
            }
            else{
                cout << v.size() << " ";
                for(int j = 0; j<v.size(); j++){
					if(j == v.size() -1){
						cout << v[j] << endl;
					}
					else{
						cout << v[j] << " ";
					}
				}
            }
            
        }
        for(int i = 1; i<=N; i++){
            adjList[i].clear();
        }
        cin >> N;
    }
}
