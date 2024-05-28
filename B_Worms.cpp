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

ll LOWER(ll l, ll h, vector<pair<ll,ll>> &ans, ll t){
    while(l<=h){
        ll m = l + (h-l)/2;
        if(ans[m].first <= t && ans[m].second >= t){
            return m+1;
        }
        else if(ans[m].first > t){
            h = m-1;
        }
        else if(ans[m].second < t){
            l = m+1;
        }
    }
    return -1;
}

void solve(){
    ll n; cin>>n;
    vector<ll>v(n,0);
    for(int i=0;i<n;i++) cin>>v[i];
    ll m; cin>>m;
    vector<ll>q(m,0);
    for(int i=0;i<m;i++) cin>>q[i];
    ll c = 1;
    vector<pair<ll,ll>>ans;
    for(int i=0;i<n;i++){
        ans.push_back({c, c + v[i]-1});
        c = c + v[i];
    }

    for(int i=0;i<m;i++){
        ll l = 0;
        ll h = ans.size()-1;
        cout<<LOWER(l,h, ans, q[i])<<endl;
    }

}

int main()
{
    ios::sync_with_stdio(false);
    ll t= 1;
    while(t-->0){
        solve();
    }
    return 0;
}