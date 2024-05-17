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

void solve(){
    ll n, k, x; cin>>n>>k>>x;
    vector<ll>v(n,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(), v.end());

    vector<ll>pre;
    pre.push_back(v[0]);

    for(int i=1;i<n;i++){
        pre.push_back(pre.back() + v[i]);
    }
    ll maxi = INT_MIN;
    for(int i = n-1; (i>=(n-1)-k) && (i >= 0); i--){
        ll g =0;
        if(x > i){
            g = 0;
        }
        else{
            g = pre[i-x];
        }
        ll temp = pre[i] - g;
        maxi = max(maxi, g - temp);
    }
    if(n == k) maxi = max(maxi,(ll) 0);
    cout<<maxi<<endl;

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