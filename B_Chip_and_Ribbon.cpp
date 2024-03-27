#include<bits/stdc++.h>
using namespace std;
#define yes "YES"
#define no "NO"
#define ll long long
#define mod 1000000007
void display(vector<ll>temp){ for(ll i=0;i<temp.size();i++) cout<<temp[i]<<' ';cout<<endl;}
void display2d(vector<vector<ll>> temp){for(ll i=0;i<temp.size();i++){for(ll j=0;j<temp[i].size();j++){cout<<temp[i][j]<<' ';}cout<<endl;}cout<<endl;}
ll add(vector<ll>v){ll sum = 0;for(ll i=0;i<v.size();i++)sum = sum+v[i];return sum;}
bool isOdd(ll n){if(n&1) return true;return false;}
bool isPrime(ll n){if (n <= 1)return false;for (ll i = 2; i <= n / 2; i++)if (n % i == 0)return false;return true;}
bool isVowel(char a){if(a=='a'||a=='e'||a == 'i'||a=='o'||a=='u'||a=='y'){return true;}return false;}

ll solve(){
    ll sum = 0;
    ll n; cin>>n;
    vector<ll>temp(n,0);
    for(ll i=0;i<n;i++){
        cin>>temp[i];
    }    
    ll diff = temp[0]-1;
    for(ll i= 1;i<temp.size();i++){
        if(temp[i]>temp[i-1]){
            sum = sum + temp[i] - temp[i-1];
        }
    }
    return sum+diff;
}

int main()
{
    ll t;cin>>t;
    while(t-->0){
        cout<<solve()<<endl;
    }
    return 0;
}