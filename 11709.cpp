#include <bits/stdc++.h>
#define pii pair<pair<int,int>,int>
#define ff first.first
#define fs first.second
#define saida freopen("saida.txt", "w",stdout)
#define maxint 1000000
using namespace std;


map<string,vector<string> > adjList, adjList2;
map<string,vector<string> >::iterator it;
map<string, bool > vis;
stack<string> s;
set<string> se;
set<string>::iterator its;



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
	for(auto v:adjList2[x]){
		if(vis[v] == false){
			dfs2(v);
		}
	}
}

int main(){
	int count =0;
	int P, T, ans= 0;
	string str, str2;
	cin >> P >> T;
	while(P or T){
		cin.ignore();
		for(int i = 0; i<P; i++){
			getline(cin,str);
			se.insert(str);
		}
		for(int i = 0; i<T; i++){
			getline(cin,str); 
			getline(cin,str2); 
			adjList[str].push_back(str2);
			adjList2[str2].push_back(str);
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
			string a = s.top(); s.pop();
			if(vis[a] == false){
				count ++;
				dfs2(a);
			}
		}
		for(its = se.begin(); its != se.end(); its++){
			if(adjList.find(*its) == adjList.end()){
				ans++;
			}
		}
		cout << count+ans << endl; // resṕosta
		//zerando a porra toda
		for(its = se.begin(); its != se.end(); its++){
			vis[*its] = false;
		}
		adjList.clear();
		adjList2.clear(); 
		count = ans = 0;
		se.clear();
		cin >> P >> T;
	}
}
