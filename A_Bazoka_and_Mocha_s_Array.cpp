#include<bits/stdc++.h>
using namespace std;
#define yes "Yes"
#define no "No"
#define ll long long
#define mod 1000000007
void display(vector<ll>v){ for(ll i=0;i<v.size();i++) cout<<v[i]<<' ';cout<<endl;}
void display2d(vector<vector<ll>> v){for(ll i=0;i<v.size();i++){for(ll j=0;j<v[i].size();j++){cout<<v[i][j]<<' ';}cout<<endl;}cout<<endl;}
ll add(vector<ll>v){ll sum = 0;for(ll i=0;i<v.size();i++)sum = sum+v[i];return sum;}
bool isOdd(ll n){if(n&1) return true;return false;}
bool isPrime(ll n){if (n <= 1)return false;for (ll i = 2; i <= n / 2; i++)if (n % i == 0)return false;return true;}


bool check(vector<ll> &arr, ll n){
    for(ll i=0; i<n; i++){
        vector<ll> rotate(arr.begin()+i, arr.end());
        rotate.insert(rotate.end(), arr.begin(), arr.begin()+i);
        if(is_sorted(rotate.begin(),rotate.end())){
            return true;
        }

    }
    return false;    
}

string solve(){
    ll n;
    cin>>n;
    vector< ll> v(n);
    for(ll i=0; i<n; i++) cin>>v[i];
    if(check(v,n)) return yes;
    return no;        
}
int main(){
    ios::sync_with_stdio(false);
    ll t;
    cin>>t;
    while(t--){
        cout<<solve()<<"\n";
    }

    return 0;
}
