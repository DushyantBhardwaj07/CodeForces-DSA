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


ll DP(ll n, vector<ll> &coins){

    vector<vector<ll>> dp(coins.size(), vector<ll>(n+1, 0));

    for(int j=0;j<n+1;j++){
        dp[0][j] = INT_MAX;
    }
    for(int i=1;i<coins.size();i++){
        for(int j=1;j<n+1;j++){
            if(coins[i-1]<=j){
                dp[i][j] = min(1+dp[i][j - coins[i-1]], dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[coins.size()-1][n];

}
ll solve(){

    ll n; cin>>n;
    vector<ll>coins = {1,3,6,10,15};

    if(n<15){
        return DP(n, coins);       
    }
    ll temp = (n/15);
    n = n-(temp*15);
    if(n == 0) return temp;


    ll with = temp + DP(n,coins);

    ll without = (temp-1) + DP(n+15, coins);


    return min(with, without);
}

int main()
{
    ios::sync_with_stdio(false);
    ll t;cin>>t;
    while(t-->0){
        cout<<solve()<<endl;
    }
    return 0;
}