#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
const lli maxn = 5* (1e5) + 5;
lli tre[maxn];
 
void update(lli i, lli val, lli n){
 
    i += n;
    tre[i] = val;
 
    while(i >= 1){
        i /= 2;
        tre[i] = min(tre[2*i], tre[2*i+1]);
    }
}
 
lli getmin(lli a, lli b, lli n){
 
    a += n; b += n;
    lli ans = INT_MAX;
 
    while(a <= b){
 
        if(a % 2 == 1){
            ans = min(ans, tre[a]);
            a++;
        }
        if(b % 2 == 0){
            ans = min(ans, tre[b]);
            b--;
        }
        a /= 2;
        b /= 2;
    }
    return ans;
}
 
int main(){
 
    fill(tre, tre+maxn, INT_MAX);
    lli n, q;
    cin>>n>>q;
 
    for(int i = 0; i < n; i++){
        lli x;
        cin>>x;
        update(i, x, n);
    }
 
    for(int i = 0; i < q; i++){
        lli tq, a, b;
        cin>>tq>>a>>b;
 
        if(tq == 1){
            update(a-1, b, n);
        }
        else{
            cout<<getmin(a-1, b-1, n)<<"\n";
        }
    }
    return 0;
}