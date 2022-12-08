#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int ans=0;
    int pwf=5;
    while(n/pwf>0){
        ans+=(n/pwf);
        pwf*=5;
    }
    cout<<ans<<"\n";
}