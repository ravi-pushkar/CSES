#include<bits/stdc++.h>
using namespace std;
#define ll long long
string path;
bool visited[7][7];
ll ans=0;
bool valid(int p,int q){
    if(p>=0 && p<7 && q>=0 && q<7 && !visited[p][q]) return true;
    return false;
}
void dfs(int i,int j,int a){
    if(i==6 && j==0){
        if(a==48) ans++;
    return;
    }
    visited[i][j]=true;
    if(path[a]=='U'|| path[a]=='?'){
        if (i > 0 && valid(i - 1, j)) {
            if (!(!valid(i - 2, j) && valid(i - 1, j - 1) && valid(i - 1, j + 1)) || (i - 1 == 6 && j == 0)) {
                dfs(i - 1, j, a + 1);
            }
        }
    }

    if (path[a] == 'D' || path[a] == '?') {
        if (i < 6 && valid(i + 1, j)) {
            if (!(!valid(i + 2, j) && valid(i + 1, j - 1) && valid(i + 1, j + 1))) {
                dfs(i + 1, j, a + 1);
            }
        }
    }

    if (path[a] == 'L' || path[a] == '?') {
        if (j > 0 && valid(i, j - 1)) {
            if (!(!valid(i, j - 2) && valid(i - 1, j - 1) && valid(i + 1, j - 1))) {
                dfs(i, j - 1, a + 1);
            }
        }
    }

    if (path[a] == 'R' || path[a] == '?') {
        if (j < 6 && valid(i, j + 1)) {
            if (!(!valid(i, j + 2)  && valid(i - 1, j + 1) && valid(i + 1, j + 1))) {
                dfs(i, j + 1, a + 1);
            }
        }
    }
    visited[i][j]=false;
    return;
}

int main(){
    cin>>path;
    dfs(0,0,0);
    cout<<ans<<"\n";
    return 0;
}