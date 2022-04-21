#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main(){
    ll n,m,k;
    int p=0,q=0,ans=0;
    cin>>n>>m>>k;
    vector<ll>u(n,0);
    vector<ll>v(m,0);
    for(int i=0;i<n;i++) cin>>u[i];
    for(int j=0;j<m;j++) cin>>v[j];
    sort(u.begin(),u.end());
    sort(v.begin(),v.end());
    while(p<n && q<m){
        if(v[q]<=u[p]+k && v[q]>=u[p]-k){
            p++;
            q++;
            ans++;
        }
        else if(v[q]<u[p]-k){
            q++;
        }
        else if(u[p]+k<v[q]){
            p++;
        }
    }
    cout<<ans<<"\n";
    return 0;
}