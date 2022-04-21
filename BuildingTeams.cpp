#include <bits/stdc++.h>
using namespace std;

int adj[100001][100001] = {0};
int ans[100001];
for(int i=0;i<100001;i++) ans[i]=0;

bool bip(int n,int v[][], int src ,int ans){
    ans[src] = 1;
    queue<int>q;
    q.push(src);
    while(!q.empty()){
        int p = q.front();
        q.pop();
        if(v[p][p] == 1) return false;
        for(int nb = 1;nb <= n;nb++){
            if(v[p][nb] && ans[nb] == 0){
                ans[nb] = 3 - ans[p];
                q.push(nb);
            }
            else if(v[p][nb] && ans[nb] == ans[p]) return false;
        }
    }
    return true;
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 0;i < m;i++){
        int a,b;
        cin>>a>>b;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }
    for(int i = 1;i < n; i++){
        if(ans[i] == 0){
            if(!bip(adj, i, ans, n)){
                cout<<"IMPOSSIBLE\n";
                return 0;
            }
        }
    }
    for(int i = 1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    //cout<<"SOMECHANGes\n";
}