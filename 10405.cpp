#include <bits/stdc++.h>
using namespace std;


int dp[1010][1010];


int lcs(string str1, string str2, int tam1, int tam2){
    if(tam1 == 0 or tam2 == 0) return dp[tam1][tam2] = 0;
    if(str1[tam1-1] == str2[tam2-1]) return dp[tam1][tam2] = 1+lcs(str1,str2,tam1-1,tam2-1);
    if(dp[tam1][tam2] != -1) return dp[tam1][tam2];
    return dp[tam1][tam2] = max(lcs(str1,str2,tam1-1,tam2), lcs(str1,str2,tam1,tam2-1));
}



int main(){
    string str1,str2;
    while(getline(cin,str1)){
        getline(cin,str2);
        memset(dp,-1,sizeof(dp));
        cout << lcs(str1,str2,str1.size(),str2.size()) << endl;
    }
}
