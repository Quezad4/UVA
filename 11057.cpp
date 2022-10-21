#include <bits/stdc++.h>
using namespace std;

vector<int> v;
vector<int>::iterator a;
vector<pair<int,int> > ans;
map<int,int> mymap;

int main(){
   // freopen("entrada.txt","r",stdin);
    //freopen("saida.txt","w",stdout);
    int N, target, valor;
    string blankspace;    
    while(cin >> N){
        for(int i = 0; i<N; i++){
            cin >> valor;
            v.push_back(valor);
            if(mymap.find(valor) == mymap.end()) mymap[valor] = 1;
            else mymap[valor]++;
        }
        cin >> target;
        cin.ignore();
        getline(cin,blankspace);
        sort(v.begin(),v.end());
        for(int i = 0; i<N; i++){ 
            a = lower_bound(v.begin(),v.end(),abs(v[i]-target));  
            if(v[i] + v[a-v.begin()] == target){
                if(v[i] == v[a-v.begin()]){
                    if(mymap[v[i]] >=2){
                        ans.push_back({v[i],v[a-v.begin()]});
                    }
                }
                else{
                    ans.push_back({v[i],v[a-v.begin()]});
                }
            }
        }
        int menor = 1000000;
        int c, d;
        for(int i = 0; i<ans.size(); i++){
            if(abs(ans[i].first - ans[i].second) < menor){
                menor = abs(ans[i].first - ans[i].second);
                c = ans[i].first;
                d = ans[i].second;
            }
        }
        cout << "Peter should buy books whose prices are " << c <<  " and " << d << "." << endl;
        cout << endl;
        ans.clear();
        v.clear();
        mymap.clear();
    }
}
