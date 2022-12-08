#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    cin>>n;
    vector<int>coins(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>coins[i];
    }
    vector<int>dp(100001,0);
    dp[0]=1;
    for(int i=1;i<=n;i++){
        int val = coins[i];
        int sum = 100001-val;
        for(;sum>=0;sum--){
            if(dp[sum]){
                dp[sum+val]=1;
            }
        }
    }
    int ans=0;
    vector<int>vans;
    for(int i=1;i<100001;i++){
        if(dp[i]){
            ans++;
            vans.push_back(i);
        }
    }
    cout<<ans<<"\n";
    for(int i=0;i<vans.size();i++){
        cout<<vans[i]<<" ";
    }
    return 0;
}