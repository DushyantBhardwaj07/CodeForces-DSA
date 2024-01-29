    #include<bits/stdc++.h>
    using namespace std;
    #define yes "YES"
    #define no "NO"
    #define ll long long
    #define mod 1000000007
    void display(vector<ll>v){ for(ll i=0;i<v.size();i++) cout<<v[i]<<' ';cout<<endl;}
    void display2d(vector<vector<ll>> v){for(ll i=0;i<v.size();i++){for(ll j=0;j<v[i].size();j++){cout<<v[i][j]<<' ';}cout<<endl;}cout<<endl;}
    ll add(vector<ll>v){ll sum = 0;for(ll i=0;i<v.size();i++)sum = sum+v[i];return sum;}
    bool isOdd(ll n){if(n&1) return true;return false;}
    bool isPrime(ll n){if (n <= 1)return false;for (ll i = 2; i <= n / 2; i++)if (n % i == 0)return false;return true;}
    bool isVowel(char a){if(a=='a'||a=='e'||a == 'i'||a=='o'||a=='u'||a=='y'){return true;}return false;}

    ll luckiness(ll n){
        ll maxi = INT_MIN;
        ll mini = INT_MAX;
        string str = to_string(n);
        while(n>0){
            ll rem = n%10;
            maxi = max(maxi, rem);
            mini = min(mini,rem);
            n=n/10;
        }
        return maxi-mini;
    }

    ll solve(ll l, ll r) {
        ll luck = 0;
        ll ans = l;
        for(ll i=l;i<=min(r,l+100);i++){
            ll curr_luck=0,x=i;
            ll mini=INT_MAX;
            ll maxi=INT_MIN;
            while(x!=0){
                mini=min(mini,x%10);
                maxi=max(maxi,x%10);
                x/=10;
            }
            curr_luck = maxi-mini;
            if(curr_luck>luck){
                luck=curr_luck;
                ans=i;
            }
        }
        return ans;

    }

    int main()
    {
        ios::sync_with_stdio(false);
        ll t;cin>>t;
        while(t-->0){
            ll l,r; cin>>l>>r;
            cout<<solve(l,r)<<"\n";
        }
        return 0;
    }