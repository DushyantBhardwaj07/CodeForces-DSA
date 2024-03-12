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
    vector<ll>v(n,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(v[k] == v[j]+v[i] || v[i] == v[j] + v[k] || v[j] == v[i] + v[k]){
                    if(v[k] == v[j]+v[i]) cout<<k+1<<" "<<j+1<<" "<<i+1<<endl;
                    if(v[i] == v[j] + v[k]) cout<<i+1<<" "<<j+1<<" "<<k+1<<endl;
                    if(v[j] == v[i] + v[k]) cout<<j+1<<" "<<i+1<<" "<<k+1<<endl;
                    return;                    
                }
            }
        }
    }
    cout<<-1<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    solve();
    return 0;
}