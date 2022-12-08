#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n,x;
    cin>>n>>x;
    vector<int>v(n,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int p=0,q=n-1,ans=0;
    while(p<=q){
        if(p==q && v[p]<=x) {
            p++;
            q--;
            ans++;
        }    
        else if(v[p]+v[q]<=x){
            p++;
            q--;
            ans++;
        }
        else{
            q--;
            ans++;
        }
    }
    cout<<ans<<"\n";
    return 0;
}