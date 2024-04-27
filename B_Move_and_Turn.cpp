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


ll helper(ll i, ll j, set<pair<ll,ll>> &vis, ll n, ll n1, char dir, map<tuple<ll, ll, char,ll>, ll> &dp) {
    if (n == n1) {
        if (vis.find({i, j}) == vis.end()) {
            vis.insert({i, j});
            return 1;
        }
        return 0;
    }
    if (dp.find(make_tuple(i, j, dir,n)) != dp.end()) {
        // cout<<"debug"<<endl;
        return dp[make_tuple(i, j, dir,n)];
    }
    ll sum = 0;
    if (n == 0) {
        sum += helper(i - 1, j, vis, n+1, n1, 'l', dp);
        sum += helper(i, j - 1, vis, n+1, n1, 'd', dp);
        sum += helper(i + 1, j, vis, n+1, n1, 'r', dp);
        sum += helper(i, j + 1, vis, n+1, n1, 'u', dp);
    } else {
        if (dir == 'l') {
            sum += helper(i, j - 1, vis, n+1, n1, 'd', dp);
            sum += helper(i, j + 1, vis, n+1, n1, 'u', dp);
        } else if (dir == 'd') {
            sum += helper(i + 1, j, vis, n+1, n1, 'l', dp);
            sum += helper(i - 1, j, vis, n+1, n1, 'r', dp);
        } else if (dir == 'r') {
            sum += helper(i, j + 1, vis, n+1, n1, 'u', dp);
            sum += helper(i, j - 1, vis, n+1, n1, 'd', dp);
        } else {
            sum += helper(i - 1, j, vis, n+1, n1, 'l', dp);
            sum += helper(i + 1, j, vis, n+1, n1, 'r', dp);
        }
    }
    return dp[make_tuple(i, j, dir,n)] = sum;
}

ll solve() {
    ll n; cin >> n;
    if(n & 1){
        return 2 * (n/2 + 1) * (n/2 + 2);
    }
    return (n/2+1)*(n/2+1);
}

int main() {
    ios::sync_with_stdio(false);
    ll t = 1;
    while (t-- > 0) {
        cout << solve() << "\n";
    }
    return 0;
}
