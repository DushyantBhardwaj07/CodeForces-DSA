#include<bits/stdc++.h>
using namespace std;
#define yes "YES"
#define no "NO"
#define ll double
#define mod 1000000007
void display(vector<ll>v){ for(ll i=0;i<v.size();i++) cout<<v[i]<<' ';cout<<endl;}
void display2d(vector<vector<ll>> v){for(ll i=0;i<v.size();i++){for(ll j=0;j<v[i].size();j++){cout<<v[i][j]<<' ';}cout<<endl;}cout<<endl;}
ll add(vector<int>v){int sum = 0;for(int i=0;i<v.size();i++)sum = sum+v[i];return sum;}
bool isOdd(int n){if(n&1) return true;return false;}
bool isPrime(int n){if (n <= 1)return false;for (int i = 2; i <= n / 2; i++)if (n % i == 0)return false;return true;}
bool isVowel(char a){if(a=='a'||a=='e'||a == 'i'||a=='o'||a=='u'||a=='y'){return true;}return false;}

string solve(){
    ll n; cin>>n;
    ll temp = sqrt(n);
    for(ll i = 1;i< temp;i++){
        ll k1 = i;
        ll x = 2 * n - i - i*i;
        if(x > 0){
            ll D = 1 + 4 * x;
            ll k2 = (-1 + sqrt(D)) / 2;

            if(k2 > 0 && ceil(k2) == floor(k2)){
                ll a = (k1 * (k1 + 1))  / 2 + (k2 * (k2 + 1))/ 2;
                if(a == n) return yes;
            }
        }
    }

    return no;
    
}

int main()
{
    ios::sync_with_stdio(false);
    cout<<solve()<<endl;
    return 0;
}