#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int

int main(){
    int n,m;
    cin>>n>>m;
    vector<ll>x(n,0);
    for(int i=0;i<n;i++)cin>>x[i];

    vector<vector<ll>>v(n,vector<ll>(m+2,0));
    if(x[0]==0){
        for(int j=1;j<=m;j++)v[0][j]+=1;
    }
    else{
        v[0][x[0]]+=1;
    }
    for(ll i=1;i<n;i++){
        if(x[i]==0){
            for(ll j=1;j<=m;j++){
                v[i][j] = (v[i][j]+v[i-1][j-1]+v[i-1][j]+v[i-1][j+1])%mod;
            }
        }
        else{
           ll j = x[i];
           v[i][j] = (v[i][j]+v[i-1][j-1]+v[i-1][j]+v[i-1][j+1])%mod;
        }
    }
    int ans=0;
    for(int i=1;i<=m;i++){
        ans=(ans+v[n-1][i])%mod;
    }
    cout<<ans<<"\n";
}