#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
const lli maxn = 2*(1e5) + 5;
lli tre[maxn];
 
void update(lli i, lli val, lli n){
 
    i++;
 
    while(i <= n){
        tre[i] += val;
        i += (i & -i);
    }
}
 
lli getsum(lli i, lli n){
 
    i++;
    lli sum = 0;
    while(i >= 1){
        sum += tre[i];
        i -= (i & (-i));
    }
    return sum;
}
 
int main(){
 
    memset(tre, 0, sizeof(tre));
    lli n,q;
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
            lli dif;
            if(a == 1) dif = getsum(a-1, n);
            else dif = getsum(a-1, n) - getsum(a-2, n);
            b = b - dif;
            a--;
            update(a, b, n);
        }
        else if(tq == 2){
            a--; b--;
            if(a == 0) cout<<getsum(b, n)<<"\n";
            else cout<<getsum(b, n) - getsum(a-1, n)<<"\n";
        }
    }
    return 0;
}