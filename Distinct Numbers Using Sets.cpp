#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    set<int> s;
    while(n--){
        int inp;
        cin>>inp;
        s.insert(inp);
    }
    cout<<s.size()<<"\n";
}