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

bool BS(int ind, ll target, vector<bool> &vis, vector<ll> &ans, int n, vector<pair<ll,ll>> &temp){
    int low = 0, high = n-1;
    while(low<=high){
        ll mid = low + (high-low)/2;
        if((temp[mid].first < target) || vis[mid]){
            low = mid + 1;
        }
        else{
            if(!vis[mid] && temp[mid].first >= target){
                ans[ind] = temp[mid].second+1;
                return true;
            }
            else{
                high = mid-1;
            }
        }
    }
    return false;
}


void solve(){
    ll n;
    cin >> n;
    vector<ll> s(n), p(n);
    for (ll i = 0; i < n; ++i) cin >> s[i];
    ll l = 0, r = 0;
    bool ans = true;
    for (ll i = 0; i < n; ++i) p[i] = i + 1;
    
    while (r < n){
        while (r < n - 1 and s[r] == s[r + 1]) r++;
        if (l == r) ans = false;
        else rotate(p.begin() + l, p.begin() + r, p.begin() + r + 1);
        l = r + 1;
        r++;
    }
    
    if (ans){
        display(p);
        return;
    }
    cout<<-1<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    ll t;cin>>t;
    while(t-->0){
        solve();
    }
    return 0;
}