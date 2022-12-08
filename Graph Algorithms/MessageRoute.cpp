#include <bits/stdc++.h>
using namespace std;
 
bool visited[100001];
vector<vector<int>>adj(100001);
 
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    queue<int>q;
    q.push(1);
    map<int,int>prev;
    vector<int>dis(n + 1, INT_MAX);
    dis[1] = 0;
    while(!q.empty()){
        // queue<int>q1;
        int p = q.front();
        q.pop();
        if(visited[p]){
            continue;
        }
        visited[p] = true;
        if(p == n){
            break;
        }
        for(auto ele : adj[p])
        {
            if(!visited[ele])
            {
                q.push(ele);
                if(dis[ele] > dis[p] + 1)
                {
                    prev[ele] = p;
                    dis[ele] = dis[p] + 1;
                }
            }
        }
    }
    if(!visited[n]){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    else{
        // cout<<"Printing\n";
        int cur = n;
        int pre = prev[cur];
        vector<int>v;
        v.push_back(n);
        string strp = to_string(1);
        while(cur != 1){
            v.push_back(pre);
            cur = pre;
            pre = prev[cur];
        }
        reverse(v.begin(),v.end());
        for(int i = 1;i<v.size();i++){
            strp += " "+ to_string(v[i]);
        }
        cout<<v.size()<<"\n"<<strp<<"\n";
    }
    return 0;
}