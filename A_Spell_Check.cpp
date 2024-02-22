
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

bool check(string s, map<char,ll> &m){
    for(auto it : s){
        m[it]--;
    }
    for(auto it : m){
        if(it.second != 0) return false;
    }
    return true;
}

string solve(){
    ll n; cin>>n;
    string s; cin>>s;
    map<char, ll>m;
    m['T'] = 1;
    m['i'] = 1;
    m['m'] = 1;
    m['u'] = 1;
    m['r'] = 1;
    if(n > 5) return no;
    if(check(s, m)){
        return yes;
    }
    return no; 
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