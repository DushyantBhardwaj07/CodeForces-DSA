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
    string s; cin>>s;
    string str = s+s;

    if(s.find("0") == -1){
        return (ll) s.length() * (ll) s.length();
    }

    if(s.find("1") == -1){
        return 0;
    }

    ll sum = 0;

    for(int i=1;i<s.length();i++){
        if(s[i] == '1' && s[i-1] == '1'){
            sum = sum + (s[i] - '0') + (s[i-1] - '0');
        }
    }

    ll maxi = 0;
    ll cnt = 0;
    if(s[0] == s.back() && s[0] == '1'){
        maxi = 2;        
    }
    for(int i=0;i<str.length();i++){
        if(str[i] == '1'){
            cnt++;
        }
        else{
            maxi = max(maxi, cnt);
            cnt=0;
        }
    }
    maxi = max(maxi, cnt);
    ll temp = ceil(maxi/2.0);
    ll ans = (maxi - temp) *temp + temp;
    return ans;
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