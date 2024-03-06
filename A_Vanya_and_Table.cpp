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
    ll n; cin>>n;
    map<pair<ll,ll>, ll>m;
    vector<vector<ll>>v(n, vector<ll>(4,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<4;j++){
            cin>>v[i][j];
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j = v[i][0]; j<=v[i][2]; j++){
            for(int k=v[i][1];k<=v[i][3];k++){
                m[{j,k}]++;
            }            
        }
    }
    ll ans = 0;
    for(auto it :m){
        ans = ans + it.second;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cout<<solve()<<endl;
    return 0;
}