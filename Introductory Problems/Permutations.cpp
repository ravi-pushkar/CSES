#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n;
    cin>>n;
    if(n==1)
    {
        cout<<n;
    }
    else if(n<4)
    {
        cout<<"NO SOLUTION";
    }
    else if(n==4)
    {
        string s="2 4 1 3";
        cout<<s<<"\n";
    }
    else
    {
        for(int i=1;i<=n;i+=2)
        {
            cout<<i<<" ";
        }
        for(int i=2;i<=n;i+=2)
        {
            cout<<i<<" ";
        }
    }
    return 0;
}