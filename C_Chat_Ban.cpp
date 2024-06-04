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
long long get(int k) {return k * 1ll * (k + 1) / 2;}
bool isPrime(int n){if (n <= 1)return false;for (int i = 2; i <= n / 2; i++)if (n % i == 0)return false;return true;}
bool isVowel(char a){if(a=='a'||a=='e'||a == 'i'||a=='o'||a=='u'||a=='y'){return true;}return false;}

ll solve(){
    int a;
    ll b;
    cin >> a >> b;
    ll c = 1, d = 2 * a - 1;
    ll e = 2 * a - 1;
    bool f = false;
    while (c <= d) {
        int g = (c + d) >> 1;
        if (g >= a) {
            f = (get(a) + get(a - 1) - get(2 * a - 1 - g) >= b);
        } else {
            f = (get(g) >= b);
        }
        if (f) {
            e = g;
            d = g - 1;
        } else {
            c = g + 1;
        }
    }
    return e;
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