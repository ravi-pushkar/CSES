#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
 
vector<vector<lli>> dp(5005, vector<lli>(5005, LONG_MIN));
vector<int>v(5005);
 
lli solve(lli i, lli j){
    if(i > j) return 0;
    if(dp[i][j] != LONG_MIN) return dp[i][j];
 
    lli x = v[i] + min(solve(i+2, j), solve(i+1, j-1));
    lli y = v[j] + min(solve(i+1, j-1), solve(i, j-2));
 
    return dp[i][j] = max(x, y);
}
int main(){
    int n;
    cin>>n;
    
    for(int i = 0; i < n; i++){
        cin>>v[i];
    }
 
    cout<<solve(0, n-1)<<"\n";
    return 0;
}