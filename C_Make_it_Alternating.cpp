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
    string s; cin>>s;
    ll cnt =1;
    ll cand = 1;
    ll del = 0;
    for(int i=0;i<s.length()-1;i++){
        if(s[i+1] == s[i]){
            cnt++;
        }
        else{
            cand = ((cand)%998244353 * (cnt%998244353))%998244353;
            del = del + cnt-1;
            cnt = 1;
        }
    }
    if(cnt != 1){
        cand = (cand%998244353 * cnt%998244353)%998244353;
        del = del + cnt-1;
    }
    cout<<del<<" ";
    ll fac = 1;
    for(int i=0;i<del;i++){
        fac = ((fac%998244353) * (del-i)%998244353)%998244353;
    }
    ll comb = (fac * (cand))%998244353;
    cout<<comb<<endl;


}

int main()
{
    ios::sync_with_stdio(false);
    ll t;cin>>t;
    while(t-->0){
        solve();
    }
    return 0;
}