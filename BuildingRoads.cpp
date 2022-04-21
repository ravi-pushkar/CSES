#include<bits/stdc++.h>
using namespace std;

int lastcity = 1;
vector<vector<int>>adj(100001);
vector<bool>isvisited(100001,false);

void dfs(int pt){
    isvisited[pt]=true;
    for(auto ele : adj[pt]){
        if(!isvisited[ele]){
            lastcity=ele;
            dfs(ele);
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int>v;
    for(int i=1;i<=n;i++){
        if(!isvisited[i]){
            v.push_back(i);
            // v.push_back(make_pair(lastcity,i));
            dfs(i);
        }
    }
    cout<<v.size() - 1<<"\n";
    for(int i=1;i<v.size();i++){
        cout<<v[0]<<" "<<v[i]<<endl;
    }
    return 0;
}