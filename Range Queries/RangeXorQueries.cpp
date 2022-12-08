#include<bits/stdc++.h>
using namespace std;
 
using lli = long long int;
const lli maxn = 5 * 1e5 + 5;
lli tre[maxn];
 
void update(lli i, lli val, lli n){
 
    i += n;
    tre[i] = val;
 
    while(i >= 1){
        i /= 2;
        tre[i] = tre[2*i] ^ tre[2*i+1];
    }
}
 
lli getxor(lli a, lli b, lli n){
 
    a += n; b += n;
    lli ans = 0;
 
    while(a <= b){
        if(a % 2 == 1){
            ans ^= tre[a];
            a++;
        }
        if(b % 2 == 0){
            ans ^= tre[b];
            b--;
        }
        b /= 2;
        a /= 2;
    }
    return ans;
}
 
int main(){
 
    memset(tre, 0, sizeof(tre));
    lli n, q;
    cin>>n>>q;
 
    for(int i = 0; i < n; i++){
        lli x;
        cin>>x;
        update(i, x, n);
    }
 
    for(int i = 0; i < q; i++){
        lli a, b;
        cin>>a>>b;
        cout<<getxor(a-1, b-1, n)<<"\n";
    }
    return 0;
}