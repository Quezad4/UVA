#include <bits/stdc++.h>
using namespace std;

class FenwickTree{
private:
	int N;
	vector<int>jt;
	int query(int id){
		int resp = 0;
		for(;id>0; id = id-(id&-id)){
			resp += jt[id];
		}
		return resp;
	}
	void update(int id, int x){
		for(; id<=N; id = id+(id&-id)){
			jt[id]+= x;
		}
	}
	
public:
	FenwickTree(){};
	FenwickTree(int N1){
		N = N1+1;
		jt.assign(N,0);
	}
	int query(int l, int r){
		return query(r)- (l ? query(l-1):0);
	}
	void up(int id, int x){
		update(id,x);
	}
};





int main(){
	int N; cin >> N;
	bool ok=false;
	int count = 0;
	while(N != 0){
		count++;
		if(ok)cout << endl;
		ok=true;
		int valor, x, y, pos, num;
		string str;
		FenwickTree obj(N);
		for(int i = 1; i<=N; i++){
			cin >> valor;
			obj.up(i,valor);
		}
		cin >> str;
		cout << "Case " << count << ":" << "\n";
		while(str != "END"){
			if(str == "M"){
				cin >> x >> y;
				cout << obj.query(x,y) << "\n";
			}
			else{
				cin >> pos >> num;
				obj.up(pos,num-obj.query(pos,pos));
			}
			cin >> str;
		}
		cin >> N;
	}
	
}
