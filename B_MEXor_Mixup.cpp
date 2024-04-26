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

vector<ll>xori(300001, 0);

ll solve(){
    ll a, b; cin>>a>>b;
    ll x = xori[a-1];
    
    if(x == b){
        return a;
    }

    if((x^b) == a) return a+2;
    return a+1;

}

int main()
{
    ios::sync_with_stdio(false);
    ll t;cin>>t;
    for(int i=1;i<=300001;i++){
        xori[i] = xori[i-1] ^ i;
    }
    while(t-->0){
        cout<<solve()<<"\n";
    }
    return 0;
}