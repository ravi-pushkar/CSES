#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
 
int isinside(int x,int y,int n){
    if(x>=0 && x<n && y>=0 && y<n) return 1;
    return 0;
}
 
int main(){
    int n;
    cin>>n;
    vector<vector<char>>grid(n, vector<char>(n,'\0'));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    vector<vector<int>>v(n,vector<int>(n,0));
    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            if(grid[i][j]=='.'){
                if(i==n-1 && j==n-1) v[i][j]=1;
                if(isinside(i+1,j,n)) v[i][j] = (v[i][j]+v[i+1][j]) % mod;
                if(isinside(i,j+1,n)) v[i][j] = (v[i][j]+v[i][j+1]) % mod;
            }
        }
    }
    cout<<v[0][0]<<"\n";
}