#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int n=s.length();
    int ans=1;
    int temp=1;
    for(int i=1; i<n; i++)
    {
        if(s[i]==s[i-1])
        {
            temp++;
            if(temp>ans)
            {
                ans=temp;
            }
        }
        else
        {
            temp=1;
        }
    }
    cout<<ans;
    return 0;
}