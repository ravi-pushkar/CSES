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
        i -= (i & -i);
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
        
        lli a,b;
        cin>>a>>b;
        a--; b--;
        
        lli bs = getsum(b, n);
        if(a == 0) cout<<bs<<"\n";
        else{
            lli ans = bs - getsum(a-1, n);
            cout<<ans<<"\n";
        }
    }
    return 0;
}