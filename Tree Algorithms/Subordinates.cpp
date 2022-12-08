#include<bits/stdc++.h>
using namespace std;
 
vector<vector<int>>adj(200001);
vector<int> ans(200001);
#define pb push_back;
 
int solve(int x){
    if(adj[x].size() == 0){
        return 1;
    }
    for(int i = 0; i < adj[x].size(); i++){
        ans[x] += solve(adj[x][i]);
    } 
    return ans[x] + 1;
}
int main(){
    
    int t;
    cin>>t;
    for(int i = 2; i <= t; i++){
        int parent;
        cin>>parent;
        adj[parent].push_back(i);
    }
    solve(1);
    for(int i = 1; i <= t; i++){
        cout<<ans[i]<<" "; 
    }
    return 0;
}