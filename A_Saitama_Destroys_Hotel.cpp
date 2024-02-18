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
    ll n,k; cin>>n>>k;
    vector<pair<ll,ll>>v;
    ll f, t;
    for(int i=0;i<n;i++){
        cin>>f>>t;
        v.push_back({f,t});
    }
    sort(v.begin() , v.end(), greater<pair<ll,ll>>());
    ll ans = 0;
    for(int i=0;i<v.size();i++){
        ans = ans + k - v[i].first;
        if(ans < v[i].second){
            ans = ans + (v[i].second - ans);
        }
        k = v[i].first;
    }
    ans = ans + k;
    return ans;
}

int main(){
    cout<<solve()<<endl;
    return 0;
}