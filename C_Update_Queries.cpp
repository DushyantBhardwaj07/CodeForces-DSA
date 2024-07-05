#include<bits/stdc++.h>
using namespace std;
#define ll long long

string solve(){
    ll n,m; cin>>n>>m;
    string s; cin>>s;
    vector<ll>q(m,0);
    for(int i=0;i<m;i++) cin>>q[i];
    string c; cin>>c;

    map<int,int>mp;
    sort(c.begin(), c.end());
    cout<<c<<endl;
    // for(){

    // }
    return "";
}

int main()
{
    ios::sync_with_stdio(false);
    ll t;cin>>t;
    while(t-->0){
        cout<<solve()<<"\n";
    }
    return 0;
}