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

vector<vector<ll>>dp(2002, vector<ll>(2002,-1));

ll helper(int i, vector<ll> &v, int k, int n){
    if(k == 0) return 1;

    if(dp[i][k] != -1){
        return dp[i][k];
    }

    ll ans = 0;
    for(int j = i;j<n;j = j + v[i]){
        if(v[j]%v[i] == 0){
            ans = (ans + helper(j, v, k-1, n))%mod;
        }
    }
    return dp[i][k] = ans % mod;

}

ll solve(){
    ll n, k;
    cin>>n>>k;
    ll ans = 0;
    vector<ll>v;
    for(int i=0;i<n;i++){
        v.push_back(i+1);
    }
    return helper(0, v, k, n);
}

int main()
{
    cout<<solve()<<endl;
    return 0;
}
