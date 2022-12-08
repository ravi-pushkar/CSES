#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
const lli maxn = 5 * 1e5 + 5;
lli tre[maxn];
 
void update(lli i, lli val, lli n){
 
    i += n;
    tre[i] += val;
 
    while(i >=  1){
        i /= 2;
        tre[i] += val;
    }
}
 
lli getsum(lli a, lli b, lli n){
 
    a += n; b += n;
    lli ans = 0;
 
    while(a <= b){
        if(a % 2 == 1){
            ans += tre[a];
            a++;
        }
        if(b % 2 == 0){
            ans += tre[b];
            b--;
        }
        a /= 2;
        b /= 2;
    }
    return ans;
}
 
int main(){
 
    memset(tre, 0, sizeof(tre));
    lli n,q;
    cin>>n>>q;
    vector<lli> v(n, 0);
 
    for(int i = 0; i < n; i++){
        cin>>v[i];
        lli x = (i == 0) ? v[i] : (v[i] - v[i-1]);
        update(i, x, n);
    }
 
    for(int i = 0; i < q; i++){
        lli tq;
        cin>>tq;
        if(tq == 2){
            lli k;
            cin>>k;
            cout<<getsum(0, k-1, n)<<"\n";
        }
        else{
            lli a, b, x;
            cin>>a>>b>>x;
            update(a-1, x, n);
            if(b < n) update(b, -x, n);
        }
    }
    return 0;
}