#include<bits/stdc++.h>
using namespace std;
#define ll long long

set<ll>lucky;

void helper(ll n){

    if(n>10000000000){
        return;
    }
    if(n > 0) lucky.insert(n);
    helper(n*10+4);
    helper(n*10+7);
}

ll solve(){

    ll l,r; cin>>l>>r;

    ll ans = 0, prev = l;
    while (l <= r)
    {
        auto it = lower_bound(lucky.begin(), lucky.end(), l);
        ll n = *it;
        ll next = min(n, r);
        ans = ans + n * (next - l + 1);
        l = next + 1;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    helper(0);
    cout<<solve()<<endl;
    return 0;
}