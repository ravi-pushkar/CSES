#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ma INT_MAX

int  main(){
    int n,x;
    cin>>n>>x;
    vector<int>coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    vector<int>v(x+1,0);
    v[0]=1;
    for(int i=1;i<=x;i++){
        for(int c=0;c<n;c++){
            if(coins[c]<=i){
                int cn = v[i-coins[c]];
                if(cn != 0) v[i] = (v[i] + cn) % mod;
            }
        }
    }
    cout<<v[x]<<"\n";
}