#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>v(n+1,INT_MAX);
    v[0]=0;
    for(int i=1;i<=n;i++){
        for(char c : to_string(i)){
            v[i]=min(v[i],v[i-(c-'0')]+1);
        }
    }
    cout<<v[n]<<"\n";
}