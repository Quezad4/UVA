#include <bits/stdc++.h>
#define pii pair<pair<int,int>,int>
#define ff first.first
#define fs first.second
#define saida freopen("saida.txt", "w",stdout)
#define entrada freopen("entrada.txt", "r", stdin)
#define maxint 1000000
using namespace std;


map<string,int> grauV;
vector<string> palavras;
map<string,vector<string> > adjList;
vector<string> ans;
int N;


bool topologicalSort(){
    for(int i = 0; i<N; i++){
        grauV[palavras[i]] = 0;
    }
    for(int i = 0; i<N; i++){
        for(string x: adjList[palavras[i]]){
            grauV[x]++;
        }
    }
    priority_queue<string, vector<string>, greater<string>> q;
    for(int i = 0; i<N; i++){
        if(grauV[palavras[i]] == 0){
            q.push(palavras[i]);
        }
    }
    int count = 0;
    while(!q.empty()){
        string u = q.top();
        q.pop();
        ans.push_back(u);
        for(string x: adjList[u]){
            if(--grauV[x] == 0){
                q.push(x);
            }
        }
        count ++;
    }
    if(count != N) return false;
    return true;
    


}


int main(){
    //entrada;
    //saida;
    int M, num = 1;;
    string word1, word2, blankspace;
    while(cin >> N){
        for(int i = 0; i<N; i++){
            cin >> word1;
            palavras.push_back(word1);

        }
        cin >> M;
        for(int j = 0; j< M; j++){
                cin >> word1 >> word2;
                adjList[word1].push_back(word2);
        }
        topologicalSort();
        //impressao
        cout << "Case #" << num << ": Dilbert should drink beverages in this order: ";
        for(int k = 0; k<ans.size(); k++){
            if(k == ans.size() -1){
                cout << ans[k];
            }
            else{
                cout << ans[k] << " ";
            }
            
        }
        cout << "." << endl;
        getline(cin,blankspace);
        cout << endl;
        //zerando
        adjList.clear();
        palavras.clear();
        grauV.clear();
        ans.clear();
        num++;
    }
    
}
