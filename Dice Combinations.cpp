#include <bits/stdc++.h>
using namespace std;
#define md 1000000007

int main(){
    int n;
    cin>>n;
    vector<int>v(n+1,0);
    int p = min(n,6);
    for(int i=1;i<=p;i++){
        v[i] += 1;
        for(int j=1;j<i;j++){
            v[i] = (v[i] + v[j]) % md;
        }
    }
    for(int k=7;k<=n;k++){
        for(int l=1;l<=6;l++){
            v[k] = (v[k] + v[k-l]) % md; 
        }
    }
    cout<<v[n]<<"\n";
}
