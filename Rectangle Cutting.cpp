#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>v(501,vector<int>(505,-1));

int precal(int m, int n){
    if(v[m][n]!=-1) return v[m][n];
    if(m==n) return v[m][n]=0;
    int ans=INT_MAX;
    for(int i=1;i<=(m/2);i++){
        ans=min(ans,1+precal(m-i,n)+precal(i,n));
    }
    for(int j=1;j<=(n/2);j++){
        ans=min(ans,1+precal(m,n-j)+precal(m,j));
    }
    return v[m][n]=ans;
}

int main(){
    int a,b;
    cin>>a>>b;
    int sol=precal(a,b);
    cout<<sol<<"\n";
}