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
 
vi adj[200005];
vector<bool> bol(200005, false);
int ans = 0;
 
void dfs(int a, int b){
    
    for(auto i : adj[a]){
        if(i != b){
            dfs(i, a);
            if(!bol[a] && !bol[i]){
                ans++;
                bol[a] = bol[i] = true;  
            } 
        }
    }
}
 
void solve(){
    
    int n;
    cin>>n;
    for(int i = 1; i < n; i++){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(1, 0);
    cout<<ans<<"\n";
}
 
int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
// 	int t;
// 	cin>>t;
// 	while(t--){
	    
// 	}
    solve();
	return 0;
}