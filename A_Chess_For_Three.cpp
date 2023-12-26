#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll solve(){
    vector<ll>v(3,0);
    for(int i=0;i<3;i++){
        cin>>v[i];
    }

    // sort(v.begin(), v.end());

    ll a = v[0];
    ll b = v[1];
    ll c = v[2];
    ll s = a + b + c;
    
    if((s % 2) != 0) return -1;
    return min(s/2, a + b);




    // if((a == b) && (b == c) && (a!=0)) return -1;
    
    ll ans = 0;

    while(c > 0){
        if(b > 0){
            c--;
            b--;
            ans++;
        }        

        if(c == 0) break;

        if(a > 0){
            c--;
            a--;
            ans++;
        }
        if((b == 0) && (a ==0)) break;
    }

    ans = ans + min(a,b);
    return ans;
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