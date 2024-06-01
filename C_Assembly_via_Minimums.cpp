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
    vector<ll>a(n, 0);
    ll size = (n * (n-1))/2;
    vector<ll>b(size, 0);
    map<ll,ll>m;
    for(int i=0;i<size;i++){
        cin>>b[i];
        m[b[i]]++;
    }
    sort(b.begin(), b.end());
    ll j = 0;
    for(int i=0;i<b.size();i++){
        if((m[b[i]]) > 0){
            a[j] = b[i];
            m[b[i]] = m[b[i]] - (n-j-1);
            j++;
        }
    }
    a[a.size()-1] = a[a.size()-2];

    display(a);

}

int main(){

    ios::sync_with_stdio(false);
    ll t;cin>>t;
    while(t-->0){
        solve();
    }
    return 0;
}