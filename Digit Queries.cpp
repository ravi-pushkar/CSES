#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(ll x){
    ll d=0,n=0,po=1,pn=0;
    if(x<=9){
        cout<<x<<"\n";
        return;
    }
    else{
        while(x>9*n){
            d++;
            pn=n;
            n=po*d+n;
            po*=10;
        }
        x-=9*pn;
        ll no=9*pn;
        if(x%d==0){
            no+=(x/d);
            string s=to_string(no);
            cout<<s[d-1]<<"\n";
        }
        else{
            no+=(x/d)+1;
            string s=to_string(no);
            cout<<s[x%d]<<"\n";
        }
    }
}
int main(){
    int q;
    cin>>q;
    while(q--){
        ll k;
        cin>>k;
        solve(k);
    }
}