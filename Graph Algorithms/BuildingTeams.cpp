#include <bits/stdc++.h>
using namespace std;
 
typedef long long int lli;
typedef pair<int,int> pii;
typedef map<int,int> mii;
typedef unordered_map<int, int> omii;
typedef vector<int> vi;
typedef vector<int, int> vii;
typedef stack<int> si;
typedef queue<int> qi;
 
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define f first
#define s second
#define mod 1000000007
 
const int INF = 1e9;
const lli MOD = 1e9 + 7;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dx8[8] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy8[8] = {0, 1, 0, -1, 1, -1, 1, -1};
 
 
vi adj[100005];
vector<bool> bol(100005, false);
vi ans(100005, 0);
bool bo;
 
void bfs(int s, bool &b){
    int c = 1;
    qi q;
    q.push(s);
    
    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            int x = q.front();
            q.pop();
            bol[x] = true;
            ans[x] = c;
            for(int p : adj[x]){
                if(ans[p] == c){
                    b = false;
                    return;
                }
                if(!bol[p]){
                    q.push(p);
                }
            }
        }
        if(c == 1) c = 2;
        else c = 1;
    }
}
 
int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
	int n,m;
    cin>>n>>m;
    bo = true;
    
    for(int i = 0; i < m; i++){
        int a, b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for(int i = 1; i <= n; i++){
        if(!bol[i]) bfs(i, bo);
        if(!bo){
            cout<<"IMPOSSIBLE\n";
            return 0;
        } 
    }
 
	for(int i = 1; i <= n; i++) cout<<ans[i]<<" ";
	return 0;
}