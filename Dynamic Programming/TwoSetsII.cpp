#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define INV2 500000004
#define ll long long
 
int main(){
    int n;
    cin>>n;
    int tsum = (n*(n+1))/2;
    if(n%4==1 || n%4==2){
        cout<<0<<"\n";
    }
    else{
        vector<vector<ll>>dp((tsum/2)+1,vector<ll>(n+1,0));
        for(int i=0;i<=n;i++)dp[0][i]=1;
        for(int i=0;i<=tsum/2;i++){
            for(int j=1;j<=n;j++){
                ll x = ((i>=j) && j>=1) ?dp[i-j][j-1]:0;
                ll y = ((j>=1)) ?dp[i][j-1]:0;
                dp[i][j]=(x+y)%mod;
            }
        }
        cout<<(dp[tsum/2][n] * INV2)%mod<<"\n";
    }
    return 0;
}