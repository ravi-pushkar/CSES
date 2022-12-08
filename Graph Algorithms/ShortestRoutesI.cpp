#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
 
int main(){
    lli n, m;
    cin>>n>>m;
    vector<pair<lli, lli>> edges[n+1];
    vector<lli>dp(n+1, LONG_MAX), bol(n+1, 0);
    priority_queue<pair<lli, lli>>q;
    dp[1] = 0;
    q.push({0, 1});
 
    for(lli i = 0; i < m; i++){
        lli x, y, w;
        cin>>x>>y>>w;
        edges[x].push_back({y, w});
    }
 
    while(!q.empty()){
        pair<lli, lli> p = q.top();
        lli y = p.second, w = -p.first;
        q.pop();
        if(bol[y] == 1) continue;
        bol[y] = 1;
        for(auto e : edges[y]){
            lli yy = e.first, ww = e.second;
            if(dp[y] != LONG_MAX && dp[yy] > dp[y] + ww){
                dp[yy] = dp[y] + ww;
                q.push({-dp[yy], yy});
            }
        }
    }
 
    for(lli i = 1; i <= n; i++){
        cout<<dp[i]<<" ";
    }
    return 0;
}