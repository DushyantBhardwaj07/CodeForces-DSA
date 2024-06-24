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
    ll n,p; cin>>n>>p;
    string s; cin>>s;
    p--;
    if(p >= n/2){
        reverse(s.begin(), s.end());
        p = n - 1 - p;
    }
    ll ans = 0;
    for(int i=0;i<n/2;i++){
        if(s[i] != s[n-i-1]){
            ans = ans + min( abs(s[i] -s[n-i-1] ), 26 - abs(s[i] - s[n-i-1]));
        }
    }

    if(ans == 0) return 0;

    ll left = 0, right = 0;

    for(int i=p;i<n/2;i++){
        if(s[i] != s[n-i-1]){
            right = i;
        }
    }
    for(int i=p;i>=0;i--){
        if(s[i] != s[n-i-1]){
            left = i;
        }       
    }
    ans = ans + min(abs(p - left) + (right - left), abs(right - p) + (right-left));

    return ans;
}

int main()
{
    ios::sync_with_stdio(   false);
    cout<<solve()<<endl;
    return 0;
}