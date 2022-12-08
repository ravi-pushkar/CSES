#include<bits/stdc++.h>
using namespace std;
using pr = pair<int,int>;
// using mp = make_pair;
 
string s;
bool visited[1001][1001];
pr start, last;
 
int main(){
    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>s;
        for(int j=0;j < m;j++){
            if(s[j] == 'A') start = {i,j};
            if(s[j] == 'B') last = {i,j};
            if(s[j] == '#') visited[i][j] = true;
        }
    }
    queue<pr>q;
    q.push(start);
    map<pr,pr>post;
    while(!q.empty()){
        pr p = q.front();
        q.pop();
        if(visited[p.first][p.second])
            continue;
        // if ()
        visited[p.first][p.second] = true;
        if(p == last){
            // visited[last.first][last.second] = true;
            break;
        }
        if(p.first > 0 && !visited[p.first-1][p.second]){
            pr ps = {p.first-1,p.second};
            q.push(ps);
            post[ps] = p;
        }
        if(p.first < n-1 && !visited[p.first+1][p.second]){
            pr ps = {p.first+1,p.second};
            q.push(ps);
            post[ps] = p;
        }
        if(p.second > 0 && !visited[p.first][p.second-1]){
            pr ps = {p.first,p.second-1};
            q.push(ps);
            post[ps] = p;
        }
        if(p.second < m-1 && !visited[p.first][p.second+1]){
            pr ps = {p.first,p.second+1};
            q.push(ps);
            post[ps] = p;
        }
    }
    pr s = last;
    pr po = post[s];
    string ans = "";
    if(!visited[last.first][last.second]) 
    {   
        cout<<"NO\n";
        return 0;
    }
    while(s != start){
        // cout<<s.first<<" " << s.second <<endl;
        int sx = s.first, sy = s.second;
        int pox = po.first, poy = po.second;
        if(sx + 1 == pox) ans += 'U';
        if(sx - 1 == pox) ans +=  'D';
        if(sy + 1 == poy) ans += 'L';
        if(sy - 1 == poy) ans += 'R';
        s = po;
        po = post[s];
    }
    reverse(ans.begin(), ans.end());
    if(!visited[last.first][last.second]) cout<<"NO\n";
    else{
        cout<<"YES\n"<<ans.size()<<"\n"<<ans<<"\n";
    }
    return 0;
}