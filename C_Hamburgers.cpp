#include<bits/stdc++.h> 
using namespace std;
#define yes "YES"
#define no "NO"
#define ll long long
#define mod 1000000007

bool check(ll mid, map<char, ll> &m, ll nb, ll ns, ll nc, ll pb, ll ps, ll pc, ll r){

    ll B = mid * m['B'], S = mid * m['S'], C = mid * m['C'];
    ll diffb = B-nb, diffs = S-ns, diffc = C-nc;
    ll cost = 0;
    if(diffb > 0){
        cost = cost+diffb*pb;
    }
    if(diffs > 0){
        cost = cost+diffs*ps;
    }
    if(diffc>0){
        cost = cost+diffc*pc;
    }
    if(cost>r){
        return false;
    }
    return true;
}

ll solve(){
    string s; cin>>s;
    map<char, ll>m;
    for(int i=0;i<s.length(); i++){
        m[s[i]]++;
    }
    ll nb, ns, nc; cin>>nb>>ns>>nc;
    ll pb, ps, pc; cin>>pb>>ps>>pc;
    ll r; cin>>r;
    ll low = 0, high = 2e12;
    while(low<=high){
        ll mid = low+(high-low)/2;
        if(check(mid, m, nb, ns, nc, pb, ps, pc, r)){
            low = mid+1;
        }
        else{
            high  = mid-1;
        }
    }
    return high;
}

int main()
{
    ios::sync_with_stdio(false);
    cout<<solve()<<endl;
    return 0;
}