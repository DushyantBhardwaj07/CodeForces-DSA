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
    ll a = n,b = 1,c = 1;
    if(n == 2 || n ==1 ) return n;

    return max({(n*(n-1)*(n-2)) / __gcd(n,(n-1)*(n-2)), (n-1)*(n-2)*(n-3) / __gcd(n-1,(n-2)*(n-3)) , (n)*(n-1)*(n-3) / __gcd(n,(n-1)*(n-3))});
}

int main()
{
    ios::sync_with_stdio(false);
    cout<<solve()<<endl;
    // cout << 924 * 924 * 918<<endl;
    return 0;
}