#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll solve(){
    ll n; cin>>n;
    ll temp =1;
    ll ans = 0;
    while( temp <=n){
        ans++;
        temp = temp*2;
    }
    ans--;
    ll shift = (1 << ans);
    return shift;
}

int main()
{
    ios::sync_with_stdio(false);
    ll t;cin>>t;
    while(t-->0){
        cout<<solve()<<endl;
    }
    return 0;
}