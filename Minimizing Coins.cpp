#include <bits/stdc++.h>
using namespace std;
#define ma INT_MAX 

int main(){
    int n,x;
    cin>>n>>x;
    vector<int>coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    vector<int>v(x+1,ma);
    v[0]=0;
    for(int i=1;i<=x;i++){
        for(int c=0;c<n;c++){
            if(coins[c]<=i){
                int cn = v[i-coins[c]];
                if(cn != ma && cn + 1 < v[i]){
                    v[i] = cn +1;
                }
            }
        }
    }
    if(v[x] == ma) cout<<-1<<"\n";
    else cout<<v[x]<<"\n";
}