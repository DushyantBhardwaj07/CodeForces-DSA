#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n,m; cin>>n>>m;
    vector<vector<ll>>v(m,vector<ll>(3,0));
    vector<vector<ll>>ans(m,vector<ll>(3,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<3;j++){
            cin>>v[i][j];
        }
    }

    map<ll,ll>mp;

    for(int i=0;i<m;i++){
        int temp = 1;
        bool flag = 0;
        set<ll>s;
        for(int j=0;j<3;j++){
            if(mp.find(v[i][j]) != mp.end()) {
                s.insert(mp[v[i][j]]);
            }
        }

        for(int j=0;j<3;j++){
            if(mp.find(v[i][j]) == mp.end()){
                if(s.find(1) == s.end()){
                    mp[v[i][j]] = 1;
                    s.insert(1);
                }
                else if(s.find(2) == s.end()){
                    mp[v[i][j]] = 2;
                    s.insert(2);
                }
                else if(s.find(3) == s.end()){
                    mp[v[i][j]] = 3;
                    s.insert(3);
                }
            }

        }
    }
    
    for(auto it: mp){
        cout<<it.second<<" ";
    }

}

int main()
{
    ios::sync_with_stdio(false);
    solve();
    return 0;
}