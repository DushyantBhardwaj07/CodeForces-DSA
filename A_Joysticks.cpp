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

vector<vector<ll>>dp(1000, vector<ll>(1000, -1));
ll helper(int a, int b){

    if(a == 0 || b == 0) return 1;

    if(dp[a][b] != -1){
        return dp[a][b];
    }
    
    ll left= 0, right = 0;

    if(b > 1) left = helper(a+1, b-2);
    if(a > 1) right = helper(a-2, b+1);

    return dp[a][b] = 1 + max(left, right);
}

ll solve(){
    ll a, b; cin>>a >> b;
    ll ans = helper(a,b);

    return ans-1;
}

int main()
{
    ios::sync_with_stdio(false);
    cout<<solve()<<endl;
    return 0;
}