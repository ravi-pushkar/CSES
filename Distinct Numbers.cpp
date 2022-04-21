#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n,ans=0;
    cin>>n;
    vector<int>v(n,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    if(n==1){
        cout<<1<<"\n";
        return 0;
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n-1;i++){
        if(v[i]!=v[i+1]) ans++;
    }
    if(v[n-1]!=v[n-2] || ans==0) ans++;
    cout<<ans<<"\n";
    return 0;
}