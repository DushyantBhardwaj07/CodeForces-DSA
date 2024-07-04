#include<bits/stdc++.h>
using namespace std;
#define yes "YES"
#define no "NO"
#define ll long long
#define mod 1000000007
void display(vector<ll>v){ for(ll i=0;i<v.size();i++) cout<<v[i]<<' ';cout<<endl;}
void display2d(vector<vector<ll>> v){for(ll i=0;i<v.size();i++){for(ll j=0;j<v[i].size();j++){cout<<v[i][j]<<' ';}cout<<endl;}cout<<endl;}
ll add(vector<int>v){int sum = 0;for(int i=0;i<v.size();i++)sum = sum+v[i];return sum;}
bool isOdd(int n){if(n&1) return true;return false;}
bool isPrime(int n){if (n <= 1)return false;for (int i = 2; i <= n / 2; i++)if (n % i == 0)return false;return true;}
bool isVowel(char a){if(a=='a'||a=='e'||a == 'i'||a=='o'||a=='u'||a=='y'){return true;}return false;}

ll solve(){
    ll n; cin>>n;
    vector<pair<ll,ll>>v;
    map<ll,ll>m;

    ll a;
    for(int i=0;i<n;i++){
        cin>>a;
        m[a]++;
    }

    for(auto it : m){
        v.push_back({it.second, it.first});
    }
    sort(v.begin(), v.end());
    map<ll,ll>mp;

    for(int i=0;i<v.size()-1;i++){
        mp[v[i].second]++;
    }

    ll ans = min((ll) mp.size(), (ll) v.back().first);

    if(mp.find(v.back().second) == mp.end()){
        ans = max(ans, min ((ll) mp.size() + 1, (ll) v.back().first -1));
    }

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
