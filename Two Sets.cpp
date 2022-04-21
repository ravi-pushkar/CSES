#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n%4 !=0 && (n+1)%4 !=0){
        cout<<"NO"<<"\n";
        return 0;
    }
    else{
        cout<<"YES"<<"\n";
        vector<int>v1,v2;
        int p;
        if(n%4){
            p=3;
            v1.push_back(1);
            v1.push_back(2);
            v2.push_back(3);
        } 
        else{
            p=4;
            v1.push_back(1);
            v1.push_back(4);
            v2.push_back(2);
            v2.push_back(3);
        }
        for(int i=0;i<(n-1)/4;i++){
            v1.push_back(4*i+1+p);
            v1.push_back(4*i+4+p);
            v2.push_back(4*i+2+p);
            v2.push_back(4*i+3+p);
        }
        cout<<v1.size()<<"\n";
        for(int i:v1) cout<<i<<" ";
        cout<<"\n";
        cout<<v2.size()<<"\n";
        for(int i:v2) cout<<i<<" ";
        cout<<"\n";
    }
    return 0;
}
