#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
 
int main(){
    lli n, m, q;
    cin>>n>>m>>q;
 
    vector<vector<lli>>dp(n+1, vector<lli>(n+1, LONG_MAX));
    vector<vector<lli>> edges(n+1, vector<lli>(n+1, LONG_MAX));
 
    for(lli i = 0; i < m; i++){
        lli x, y, z;
        cin>>x>>y>>z;
        edges[x][y] = min(edges[x][y],z);
        edges[y][x] = edges[x][y];
        dp[x][y] = edges[x][y];
        dp[y][x] = edges[x][y];
    }
 
    for(lli k = 1; k <= n; k++){
        for(lli i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(i == j) dp[i][j] = 0;
                if(dp[i][k] != LONG_MAX && dp[k][j] != LONG_MAX){
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }
    }
 
    for(lli i = 0; i < q; i++){
        lli a,b;
        cin>>a>>b;
        if(dp[a][b] != LONG_MAX) cout<<dp[a][b]<<"\n";
        else cout<<"-1\n";
    }
}