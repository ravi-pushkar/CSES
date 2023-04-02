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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    
    ll n; cin>>n;
    vll vec(n);
    f(i, 0, n) cin>>vec[i];
    sort(vec.begin(), vec.end());
    int median = 0, medianpo = 0;
    if(n%2 == 1) median = vec[n/2];
    else{
        ll x = (vec[(n+1)/2] + vec[n/2]);
        if(x % 2 == 0) median = medianpo = x/2;
        else{
            median = x/2;
            medianpo = median+1;
        }
    }
    ll ans = 0, ansd = 0;
    f(i, 0, n){
        ans += abs(median-vec[i]);
        ansd += abs(medianpo - vec[i]);
    }
    cout<<min(ans, ansd)<<"\n";
    return 0;
}