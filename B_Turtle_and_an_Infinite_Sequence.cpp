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

ll solve(){
    ll n, m; 
    cin >> n >> m;
    ll i = 1;
    ll temp = 0;
    ll ret = 0;
    for (; n > 0; n /= 2, i *= 2) {
        if (n % 2 == 1) {
            ret += i;
            temp += i;
        } else {
            ll x = min(i - temp, temp + 1);
            if (x <= m) {
                ret += i;
            }
        }
    }

    for (; i - temp <= m; i *= 2) {
        ret += i;
    }

    return ret;
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