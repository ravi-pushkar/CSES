#include <bits/stdc++.h>
using namespace std;
 
int main(){
    string s;
    cin>>s;
    unordered_map<char,int>hmap;
    int oddcnt=0;
    char oddch;
    for(int i=0;i<s.size();i++) hmap[s[i]]++;
    for(auto x:hmap){
        if(x.second %2!=0){
            oddcnt++;
            oddch=x.first;
        }
    }
    if(oddcnt>1 || (s.size()%2==0 && oddcnt==1)){
        cout<<"NO SOLUTION\n";
    }
    else{
        string x="",y="";
        for(auto p:hmap){
            string st(p.second/2,p.first);
            x=x+st;
            y=st+y;
        }
        if(oddcnt==1) cout<<x+oddch+y<<"\n";
        else cout<<x+y<<"\n";
    }

 }