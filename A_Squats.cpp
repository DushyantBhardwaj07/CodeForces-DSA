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

void solve(){
    ll n; cin>>n;
    string s; cin>>s;
    ll stood = 0;
    for(auto it : s){
        if(it == 'X'){
            stood++;
        }
    }
    ll temp = n/2;

    if(stood >= n/2){
        ll t = stood - n / 2;
        cout<<t<<endl;
        for(int i=0;i<n && t > 0;i++){
            if(s[i] == 'X'){
                s[i] = 'x';
                t--;    
            }
        }
        cout<<s<<endl;
    }

    else{
        ll t = n/2 - stood;
        cout<<t<<endl;
        for(int i=0;i<n & t >0;i++){
            if(s[i] == 'x'){
                s[i] = 'X';
                t--;
            }
        }
        cout<<s<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    solve();
    return 0;
}