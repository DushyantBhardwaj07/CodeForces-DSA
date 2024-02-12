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
    ll x, y; cin>>x>>y;
    ll four  = ceil(y/2.0);
    ll empty = 0;
    if((y%2) == 1){
        for(int i=0;i<four-1;i++){
            empty = empty + 7;
        }
        empty = empty + 11;
    }
    else if((y%2) == 0){
        for(int i=0;i<four;i++){
            empty = empty + 7;
        }
    }
    if(empty < x){
        ll t = ceil((x-empty)/15.0);
        return four+t;
    }
    return four;
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