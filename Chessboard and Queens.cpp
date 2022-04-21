#include<bits/stdc++.h>
using namespace std;

bool col[8],diag1[15],diag2[15],reserved[8][8];
long long ans=0;
void search(int r){
    if(r==8){
        ans++;
        return;
    }
    for(int i=0;i<8;i++){
        if(col[i]||diag1[r+i]||diag2[r-i+7]||reserved[r][i])continue;
        col[i]=diag1[r+i]=diag2[r-i+7]=true;
        search(r+1);
        col[i]=diag1[r+i]=diag2[r-i+7]=false;
    }
}
int main(){
    memset(col,false,sizeof(col));
    memset(diag1,false,sizeof(diag1));
    memset(diag2,false,sizeof(diag2));
    for(int i=0;i<8;i++){
        string s;
        cin>>s;
        for(int j=0;j<8;j++){
            reserved[i][j]=s[j]=='*';
        }
    }
    search(0);
    cout<<ans<<"\n";
}