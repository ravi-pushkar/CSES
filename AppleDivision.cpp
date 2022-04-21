#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll solve(ll vec[],ll i,ll tot,ll temps){
    if(i==0) return abs(tot-2*temps);
    return(min(solve(vec,i-1,tot,temps+vec[i]),solve(vec,i-1,tot,temps)));
}
int main(){
    ll n;
    cin>>n;
    ll v[n],tts=0;
    for(int i=0;i<n;i++){
        cin>>v[i];
        tts+=v[i];
    }
    ll x=solve(v,n,tts,0);
    cout<<x<<"\n";
}