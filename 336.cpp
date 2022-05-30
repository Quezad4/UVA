#include <bits/stdc++.h>
#define pii pair<pair<int,int>,int>
#define ff first.first
#define fs first.second
#define saida freopen("saida.txt", "w",stdout)
using namespace std;
unordered_set<int> s;
vector<vector<int> > adjList (100000);
int save;


int bfs(int origem,int l){
	int dist[100000];
	memset(dist,-1,sizeof(dist));
    queue<int> fila;
    int count1=0;
    save=s.size()-1;
    dist[origem] = 0;
    fila.push(origem);
    while(!fila.empty()){
        int u = fila.front();
        fila.pop();
		for(int j = 0; j<adjList[u].size(); j++){
			if(dist[adjList[u][j]] == -1){
				dist[adjList[u][j]] = dist[u]+1;
				fila.push(adjList[u][j]);
				if(dist[adjList[u][j]] > l){
					count1++;
				}
				save--;
				
			}
		}

        
    }
    return count1;
    
}

int main(){
    //saida;
    int k,l,x,y,N;
    int num = 0;
    cin >>N;
    while(N){
        int i;
        adjList = vector<vector<int> > (100000);
        for(i = 0; i<N; i++){
            cin >> x >> y;
            adjList[x].push_back(y);
            adjList[y].push_back(x);
            s.insert(x);
            s.insert(y);
        }
        cin >> k >> l;
        while(k or l ){
            num++;
            cout << "Case " << num << ": " << bfs(k,l)+save << " nodes not reachable from node " << k << " with TTL = " << l <<"."<< endl;
            
            cin >> k >> l;
        }
        
        s.clear();
        cin >> N;
    }
}
