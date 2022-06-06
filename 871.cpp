#include <bits/stdc++.h>
#define pii pair<pair<int,int>,int>
#define ff first.first
#define fs first.second
#define saida freopen("saida.txt", "w",stdout)
#define maxint 1000000
using namespace std;

char matrix[26][26];
bool vis[26][26];
vector<int> ans;
int contador = 0;
int vx[] = {1,-1,0,0,-1,-1,1,1}, vy[] = {0,0,1,-1,1,-1,1,-1};

int count1 = 0, b;

bool isValid(int i, int j){
    if(i<0 or i>=count1 or j<0 or j>= b or vis[i][j] == true or matrix[i][j] == '0'){
        return false;
    }
    return true;
}
void dfs(int i, int j){
    vis[i][j] = true;
    contador++;
    for(int k = 0; k<8; k++){
        int ax = i+vx[k];
        int ay = j+vy[k];
        if(isValid(ax,ay)){
            dfs(ax,ay);
        }
    }

}

int main(){
   int N; cin >> N;
   string a, str;
   for(int i = 0; i<N; i++){
       memset(vis,false,sizeof(vis));
       if(i == 0){
            cin.ignore();
            getline(cin, a);
       }
       getline(cin, str);
       while(str !=""){
           for(int j = 0;j<str.size(); j++){
               matrix[count1][j] = str[j];
           }
            count1++;
            b = str.size();
            getline(cin,str);
       }

       for(int j = 0; j<count1; j++){
           for(int k = 0; k<b; k++){
               if(matrix[j][k] == '1'){
                   dfs(j,k);
                    ans.push_back(contador);
                    contador = 0;
               }
           }
       }
       if(ans.size() == 0){
           if(i == N -1){
                cout << 0 << endl;
           }
           else{
                cout << 0 << endl;
                cout << endl;
           }  
       }
       else{
            sort(ans.rbegin(),ans.rend());
            if(i == N-1){
                cout << ans[0] << endl;
            }
            else{
                cout << ans[0] << endl;
                cout << endl;
            }
            ans.clear();
            count1 = 0;
       }
   }
}
