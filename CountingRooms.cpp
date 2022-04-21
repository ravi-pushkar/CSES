#include<bits/stdc++.h>
using namespace std;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
char bmap[1001][1001];
int isvisited[1001][1001];

bool isvalid(int x,int y, int n, int m){
    if(x>=n || x<0 || y>=m || y<0) return false;
    return true;
}

void dfs(int x, int y, int n, int m){
    isvisited[x][y]=1;
    for(int i=0;i<4;i++){
        int xnew = x + dx[i];
        int ynew = y + dy[i];
        if(isvalid(xnew, ynew,n, m) && !isvisited[xnew][ynew]){
            isvisited[xnew][ynew]=1;
            if(bmap[xnew][ynew]=='.') dfs(xnew,ynew,n,m);
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>bmap[i][j];
            isvisited[i][j]=0;
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(bmap[i][j]=='.' && !isvisited[i][j]){
                dfs(i,j,n,m);
                ans++;
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}