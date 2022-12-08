#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<int>dp;
    int ans = 1;
    for(int i=0;i<n;i++){
        int sz = dp.size();
        if(sz == 0 || v[i] > dp[sz-1]){
            dp.push_back(v[i]);
        }
        else{
            auto it = lower_bound(dp.begin(), dp.end(), v[i]);
            *it = v[i];
        }
    }
    cout<<dp.size()<<"\n";
    return 0;
}