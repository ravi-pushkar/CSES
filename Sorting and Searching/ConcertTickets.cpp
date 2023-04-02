#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int>price(n);
    map<int,int> mp;
    for(int i = 0; i < n; i++){
        cin>>price[i];
        mp[-price[i]]++;
    }
    for(int i = 0; i < m; i++) {
        int x;
        cin>>x;
        auto it = mp.lower_bound(-x);
        // cout<<(*it).first<<" "<<(*it).second<<"\n";
        if(it != mp.end()){
            int y = (*it).first;
            cout<<-y<<"\n";
            mp[y]--;
            if(mp[y] == 0) mp.erase(mp.find(y));
            // for(auto itr : mp)
            //     cout<<itr.first<<" "<<itr.second<<"\n";
        }
        else{
            cout<<-1<<"\n";
        }
    }
    return 0;
}