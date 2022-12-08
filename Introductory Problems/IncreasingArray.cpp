#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,y;
    cin>>n;
    int x;
    cin>>x;
    long long int ans=0;
    int cnt=1;
    while(cnt<n)
    {
        int y;
        cin>>y;
        if(y<x)
        {
            ans+=(x-y);
        }
        else
        {
            x=y;
        }
        cnt++;
    }
    cout<<ans<<"\n";
    return 0;
}