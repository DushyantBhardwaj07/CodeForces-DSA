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

bool check(vector<ll> & v){
    bool flagodd = false;
    bool flageven = false;
    if((v[0] & 1)) flagodd = true;
    if(!(v[0] & 1)) flageven = true;

    for(int i=0;i<v.size();i++){
        if(flageven){
            if(v[i] & 1) return false;
        }

        else if(flagodd){
            if(!(v[i] & 1)) return false;
        }
    }

    return true;
}

string solve(){
    ll n; cin>>n;
    vector<ll>v(n,0);
    for(int i=0;i<n;i++) cin>>v[i];
    if(check(v)) return yes;
    vector<ll>v1 = v;
    vector<ll>v2 = v;
    for(int i=0;i<n;i=i+2){
        v1[i]++;
    }
    if(check(v1)) return yes;
    for(int i=1;i<n;i=i+2){
        v2[i]++;
    }
    if(check(v2)) return yes;

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