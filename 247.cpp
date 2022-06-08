#include <bits/stdc++.h>
#define pii pair<pair<int,int>,int>
#define ff first.first
#define fs first.second
#define saida freopen("saida.txt", "w",stdout)
#define maxint 1000000
using namespace std;
map<string,vector<string> > adjList, adjList2;
map<string,vector<string> >::iterator it;
map<string,bool> vis;
stack<string> s;
vector<string> v;
vector<vector<string> > ans;


void dfs1(string x){
    vis[x] = true;
    for(auto v:adjList[x]){
        if(vis[v] == false){
            dfs1(v);
        }
    }
    s.push(x);
}


void dfs2(string x){
    vis[x] = true;
    v.push_back(x);
    for(auto v:adjList2[x]){
        if(vis[v] == false){
            dfs2(v);
        }
    }
}

int main(){
	saida;
    int N, M, count = 0, num = 1;
    string str1, str2;
    cin >> N >> M;
    bool flag=false;
    while(N or M){
		if(flag) cout<<endl;
        for(int i = 0; i<M; i++){
            cin >> str1 >> str2;
            adjList[str1].push_back(str2);
            adjList2[str2].push_back(str1);
        }
        for(it = adjList.begin(); it != adjList.end(); it++){
            if(vis[it->first] == false){
                dfs1(it->first);
            }
        }
        for(it = adjList.begin(); it != adjList.end(); it++){
            vis[it->first] = false;
        }
        while(!s.empty()){
            string a = s.top();
            s.pop();
            if(vis[a] == false){
                count++;
                dfs2(a);
                ans.push_back(v);
                v.clear();
            }
        }
        cout << "Calling circles for data set " << num <<":" << endl;
        for(int i = 0; i<count; i++){
            for(int j = 0; j<ans[i].size(); j++){
                if(ans[i].size() == 1){
                    cout << ans[i][j] << endl;
                }
                else{
                    if(j == ans[i].size() -1){
                        cout << ans[i][j] << endl;
                    }
                    else{
                        cout << ans[i][j] << ", ";
                    }
                    
                }
            }
        }
        for(int i = 0; i<count; i++){
            ans.clear();
        }
        for(it = adjList.begin(); it != adjList.end(); it++){
            vis[it->first] = false;
        }
        adjList.clear();
        adjList2.clear();
        v.clear();
        num++;
        flag=true;
        count = 0;
        cin >> N >> M;
    }
    
}
