#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        long long tt=i*i;
        long long ans=tt*(tt-1)/2;
        if(i>2) ans-=4*(i-1)*(i-2);
        cout<<ans<<"\n";
    }
}
