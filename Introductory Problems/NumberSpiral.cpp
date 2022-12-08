#include <bits/stdc++.h>
using namespace std;
 int main()
 {
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
    long long int x,y;
    cin>>x>>y;
    long long int ans;
    if(y>x)
    {
        if(y%2==1)
        {
            ans=y*y-x+1;
        }
        else
        {
            ans=(y-1)*(y-1)+x;
        }
    }
    else
    {
        if(x%2==0)
        {
            ans=x*x-y+1;
        }
        else
        {
            ans=(x-1)*(x-1)+y;
        }
    }
    cout<<ans<<"\n";
 
    }
    return 0;
 }