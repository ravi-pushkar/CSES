#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
const ll mod = 1e9 + 7;
const ll sz = 1e6;
 
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    vector<ll>join(sz,0);
    vector<ll>sep(sz,0);
    join[0]=1;
    sep[0]=1;
    for(int i=1;i<sz;i++){
        sep[i]=(4*sep[i-1]+join[i-1])%mod;\
        join[i]=(2*join[i-1]+sep[i-1])%mod;
    }
    ll t;
    cin>>t;
    while (t--)
    {
        /* code */
        ll n;
        cin>>n;
        ll ans=(sep[n-1]+join[n-1])%mod;
        cout<<ans<<"\n";
    }
}