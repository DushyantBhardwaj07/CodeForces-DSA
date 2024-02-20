#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll solve(){
    ll s; cin>>s;
    map<ll,ll>m;
    m[1] = 1;
    m[2] = 2;
    m[3] = 3;
    ll a,b;
    for(int i=0;i<3;i++){
        cin>>a>>b;
        swap(m[a], m[b]);
    }
    return m[s];
}

int main()
{
    ios::sync_with_stdio(false);
    cout<<solve()<<endl;
    return 0;
}