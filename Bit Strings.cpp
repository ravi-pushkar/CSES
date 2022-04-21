#include<bits/stdc++.h>
using namespace std;
#define md 1000000007
int main(){
    int n;
    cin>>n;
    long long ans=1;
    for(int i=1;i<=n;i++){
        ans=(2*ans)%md;
    }
    ans%=md;
    cout<<ans<<"\n";
}