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

bool check(string &s){
    vector<string>alcohol = {"ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE", "TEQUILA", "VODKA", "WHISKEY", "WINE"};
    for(int i=0;i<alcohol.size();i++){
        if(alcohol[i] == s) return true;
    }
    return false;
}

ll solve(){
    ll n; cin>>n;
    string s;
    ll ans = 0;
    ll num = 0;
    for(int i=0;i<n;i++){
        stringstream sso;
        cin>>s;
        sso<<s;
        sso>>num;

        if(check(s)){
            ans++;
        }
        else if((s[0]>='0' && s[0]<='9') && num<18){
            ans++;
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