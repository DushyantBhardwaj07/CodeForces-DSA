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
    ll maxi = INT_MIN;
    ll n; cin>>n;
    vector<ll>v1(n,0);
    vector<ll>v2(n,0);
    for(int i=0;i<n;i++) cin>>v1[i];
    for(int i=0;i<n;i++) cin>>v2[i];

    for(int i=0;i<n;i++){
        ll sum1 = 0, sum2 = 0;
        for(int j = i;j<n;j++){
            sum1 = sum1 | v1[j];
            sum2 = sum2 | v2[j];
        }
        maxi = max(maxi, sum1+sum2);
    }
    return maxi;
}

int main()
{
    ios::sync_with_stdio(false);
    cout<<solve()<<endl;
    return 0;
}