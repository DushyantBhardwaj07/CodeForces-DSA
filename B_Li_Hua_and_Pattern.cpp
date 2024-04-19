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

string solve(){
    ll n,k; cin>>n>>k;
    vector<vector<ll>>v(n, vector<ll>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>v[i][j];
        }
    }
    vector<vector<ll>>v1 = v;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            v1[i][j] = v[n - 1 - i][n - 1 - j];
        }
    }

    // display2d(v1);
    
    ll cnt = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(v1[i][j] != v[i][j]){
                v1[i][j] = v[i][j];
                cnt++;
            }
        }
    }
    
    cnt = cnt/2;
    if(cnt > k) return no;
    if(cnt == k) return yes;

    if(n & 1) return yes;
    k = k-cnt;
    if(k & 1) return no;
    return yes;
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