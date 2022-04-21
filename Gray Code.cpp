#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=0;i<=(1<<n);i++){
        int it=i^(i>>1);
        bitset<16>x(it);
        string s=x.to_string();
        cout<<s.substr(16-n)<<"\n";
    }
}