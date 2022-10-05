#include <bits/stdc++.h>
using namespace std;

char matrix[35][35][35];
bool vis[35][35][35];


int movz[] = {1,-1};
int movx[] = {0,0,1,-1};
int movy[] = {-1,1,0,0};

int L,R,C,dz,dx,dy;

bool isValid(int z,int x, int y){
   if(z<0 or z>=L or x<0 or x>=R or y<0 or y>=C or vis[z][x][y] == true or matrix[z][x][y] == '#'){
      return false;
   }
   return true;
}


int bfs(int z, int x, int y){
   queue<pair<pair<pair<int,int>, int>, int > > f;
   f.push({{{z,x},y},0});
   vis[z][x][y] = true;
   while(!f.empty()){
      int zu = f.front().first.first.first;
      int xu = f.front().first.first.second;
      int yu = f.front().first.second;
      int cont = f.front().second;
      f.pop();
      if(dz == zu and dx == xu and dy == yu ) return cont;
      for(int i = 0; i<4; i++){
         int az = zu;
         int ax = xu+movx[i];
         int ay = yu+movy[i];
         if(isValid(az,ax,ay)){
            f.push({{{az,ax},ay},cont+1});
            vis[az][ax][ay] = true;
            matrix[az][ax][ay] = '0';

         }
         for(int j = 0; j<2; j++){
            int az = zu+movz[j];
            int ax = xu;
            int ay = yu;
            if(isValid(az,ax,ay)){
               f.push({{{az,ax},ay},cont+1});
               vis[az][ax][ay] = true;
               matrix[az][ax][ay] = '0';
            }
         }
      }
   }
   return -1;
}







int main(){
   //freopen("saida.txt", "w",stdout);
   //freopen("entrada.txt", "r", stdin);
   char valor;
   int sz,sx,sy;
   string blankline;
   cin >> L >> R >> C;
   while(L != 0 or R != 0 or C != 0){
      for(int k = 0; k<L; k++){
         for(int i = 0; i<R; i++){
            for(int j = 0; j<C; j++){
               cin >> valor;
               matrix[k][i][j] = valor;
               if(valor == 'S'){
                  sz = k;
                  sx = i;
                  sy = j;
               }
               if(valor == 'E'){
                  dz = k;
                  dx = i;
                  dy = j;
               }
            }
         }
         if(k < L -1){
            cin.ignore();
            getline(cin, blankline);
         }
      }
      memset(vis,false,sizeof(vis));
      int  ans = bfs(sz,sx,sy);
      if(ans == -1) cout << "Trapped!" << endl;
      else{
         cout << "Escaped in " << ans << " minute(s)." << endl;
      }
      /*
      cout << "-----------------------------------" << endl;
      for(int k = 0; k<L; k++){
         for(int i = 0; i<R; i++){
            for(int j = 0; j<C; j++){
               cout << matrix[k][i][j] << " ";
            }
            cout << endl;
         }
         cout << endl;
      }
      */
     cin >> L >> R >> C;
   }
}
