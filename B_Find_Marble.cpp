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
    ll n,s,t; cin>>n>>s>>t;
    vector<ll>v(n,0);
    map<ll,pair<bool, ll>>m;
    for(int i=0;i<n;i++){
        cin>>v[i];
        m[i+1] = {false, v[i]};
    }
    auto &it = m[s];
    if(s == t) return 0;
    if( s!=t && it.second == t) return 1;
    ll ans = 0;
    while(it.second!= t && it.first == false){
        if(it.first == false){
            it.first = true;
            ans++;
        }
        auto &itr = m[it.second];
        // cout<<itr.second<<endl;
        if(itr.first == true) return -1;
        if(itr.second == t) ans++;
        it = itr;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cout<<solve()<<endl;
    return 0;
}