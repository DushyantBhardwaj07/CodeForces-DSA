#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n, m; cin>>n >> m;
    ll temp = min(n,m);
    ll temp1 = max(n,m);
    cout<<temp1 - 1<<" "<<temp<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    solve();
    return 0;
}