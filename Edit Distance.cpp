#include<bits/stdc++.h>
using namespace std;

int main(){
    string n,m;
    cin>>n>>m;
    int a=n.size(),b=m.size();
    vector<vector<int>>v(a+1,vector<int>(b+1,0));
    for(int i=0;i<=a;i++){
        for(int j=0;j<=b;j++){
            if(i==0)v[i][j]=j;
            else if(j==0)v[i][j]=i;
            else if(n[i-1]==m[j-1]){
                v[i][j]=v[i-1][j-1];
            }
            else{
                v[i][j]=1+min(v[i][j-1],min(v[i-1][j],v[i-1][j-1]));
            }
        }
    }
    cout<<v[a][b]<<"\n";
}