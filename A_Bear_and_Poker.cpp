    #include<bits/stdc++.h>
    using namespace std;
    #define yes "Yes"
    #define no "No"
    #define ll long long
    #define mod 1000000007

    ll lcm(ll a, ll b){
        return (a / __gcd(a,b)) * b;
    }

    string solve(){
        ll n; cin>>n;
        vector<ll>v(n,0);
        for(int i=0;i<n;i++) cin>>v[i];
        ll ans = v[0];
        for(int i=1;i<n;i++){
            ans = lcm(ans, v[i]);
        }
        for(int i=0;i<n;i++){
            if(ans % v[i] != 0 ) return  no;
            ll temp = ans/v[i];
            while(temp > 1 && temp%2 == 0){
                temp = temp/2;
            }
            while(temp > 1 && temp%3 == 0){
                temp = temp/3;
            }
            if(temp!=1) return no;
        }
        return yes;
    }

    int main()
    {
        ios::sync_with_stdio(false);
        cout<<solve()<<endl;
        return 0;
    }