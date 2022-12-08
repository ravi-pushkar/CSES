#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n,x;
    cin>>n>>x;
    vector<int>price(n,0);
    vector<int>pages(n,0);
    for(int i=0;i<n;i++) cin>>price[i];
    for(int i=0;i<n;i++) cin>>pages[i];
    vector<int>v(x+1);
    for(int i=0;i<n;i++){
        for(int j=x;j>=price[i];j--){
                v[j]=max(v[j-price[i]]+pages[i],v[j]);
        }
    }
    cout<<v[x]<<"\n";
}