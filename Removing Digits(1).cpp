#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>v(n+1,INT_MAX);
    v[0]=0;
    for(int i=1;i<=n;i++){
        int x=0;
        for(char c : to_string(i)){
            x=max(x,c-'0');
        }
        v[i]=v[i-x]+1;
    }
    cout<<v[n]<<"\n";
}