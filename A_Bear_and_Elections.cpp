#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool check(ll mid, vector<ll>v){
    v[0] = v[0]+mid;
    ll sum = 0;
    for(int i=1;i<v.size();i++){
        if(v[i]>=v[0]){
            sum = sum + v[i] - v[0]+1;
            if(sum > mid) return false;
        }

    }
    if(sum>mid) return false;
    return true;
}

ll solve(){
    ll n; cin>>n;
    vector<ll>v(n,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    ll low = 0, high = 10000;
    while(low<=high){
        ll mid = low + (high-low)/2;
        if(check(mid, v)){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return low;
}

int main()
{
    ios::sync_with_stdio(false);
    cout<<solve()<<endl;
    return 0;
}