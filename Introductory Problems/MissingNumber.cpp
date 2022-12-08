#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int n;
    cin>>n;
    long long int sum=n*(n+1);
    sum=sum/2;
    long long int ts=0;
    long long int x;
    int cnt=0;
    while(cnt<n-1)
    {
        cin>>x;
        ts=ts+x;
        cnt++;
    }
    long long int ans=sum-ts;
    cout<<ans;
    return 0;
}