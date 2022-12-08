#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
 
int main(){
    int n,x;
    cin>>n>>x;
    vector<int>coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    vector<int>v(x+1);
    v[0]=1;
    for(int i=0;i<n;i++){
        for(int j=coins[i];j<=x;j++){
            v[j]=(v[j]+v[j-coins[i]])%mod;
        }
    }
    cout<<v[x]<<"\n";
}