#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
 
lli modp(lli x, lli p){
    lli ans = 1;
    while(p > 0){
        if(p & 1) ans *= x;
        p=p>>1;
        x *= x;
    }
    return ans;
}
 
int main(){
 
    lli q;
    cin>>q;
    while(q--){
 
        lli n; cin>>n;
        lli c = 1;
        for(lli i = 9;; n-=i, c++, i = 9*modp(10,c-1)*c){
            if(n-i <= 0) break;
        }
        n--;
        lli x = n/c, y = n%c;
        lli ans = modp(10, c-1) + x;
        string s = to_string(ans);
        cout<<s[y]<<"\n";
    }
    return 0;
}