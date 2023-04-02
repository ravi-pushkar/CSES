#include <bits/stdc++.h>
using namespace std;    
    
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define umii unordered_map<int, int>
#define umsi unordered_map<string, int>
#define si set<int>
#define ss set<string>

#define f(i,s,e) for(long long int i=s;i<e;i++)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define pb push_back
#define eb emplace_back

#define MOD 1000000007
#define PI 3.1415926535897932384626433832795

ll min(ll a,int b) { if (a<b) return a; return b; }
ll min(int a,ll b) { if (a<b) return a; return b; }
ll max(ll a,int b) { if (a>b) return a; return b; }
ll max(int a,ll b) { if (a>b) return a; return b; }
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }

bool comp(pll a, pll b){
    if(a.second == b.second) return a.first > b.first;
    return a.second < b.second;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    
    ll n;
    cin>>n;
    vector<pll> time(n);
    f(i, 0, n) cin>>time[i].first>>time[i].second;
    sort(time.begin(), time.end(), comp);
    int ans = 1, ld = 0;
    f(i, 1, n){
        if(time[i].first >= time[ld].second){
            ans++;
            ld = i;
        }
    }
    cout<<ans<<"\n";
    return 0;
}