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
    ll n, m; cin>>n>>m;
    vector<vector<ll>>dp(m, vector<ll>(n ,0));  
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>dp[i][j];
        }
    }
    // display2d(dp);
    vector<ll>temp;
    for(int j=0;j<n;j++){
        ll sum = 0;
        for(int i=0;i<m;i++){
            // cout<<dp[i][j]<<endl;
            sum = sum + dp[i][j];
        }
        temp.push_back(sum);
    }
    display(temp);
    ll ans = -1;
    int maxi = INT_MIN;
    for(int i=0;i<temp.size();i++){
        if(temp[i] > maxi){
            maxi = temp[i];
            ans = i+1;
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cout<<solve()<<endl;
    return 0;
}