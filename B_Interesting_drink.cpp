#include<bits/stdc++.h>
using namespace std;
#define no "NO"
#define yes "YES"
#define ll long long
#define mod 1000000007
void display(vector<ll>v){ for(ll i=0;i<v.size();i++) cout<<v[i]<<' ';cout<<endl;}
void display2d(vector<vector<ll>> v){for(ll i=0;i<v.size();i++){for(ll j=0;j<v[i].size();j++){cout<<v[i][j]<<' ';}cout<<endl;}cout<<endl;}
int add(vector<int>v){int sum = 0;for(int i=0;i<v.size();i++)sum = sum+v[i];return sum;}
bool isOdd(int n){if(n&1) return true;return false;}
bool isPrime(int n){if (n <= 1)return false;for (int i = 2; i <= n / 2; i++)if (n % i == 0)return false;return true;}
bool isVowel(char a){if(a=='a'||a=='e'||a == 'i'||a=='o'||a=='u'||a=='y'){return true;}return false;}

void solve(){
    ll n; cin>>n;
    vector<ll>v(n,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    ll q; cin>>q;
    vector<ll>coins(q,0);
    for(int i=0;i<q;i++){
        cin>>coins[i];
    }

    for(int i=0;i<coins.size();i++){
        ll ind = upper_bound(v.begin(), v.end(), coins[i]) - v.begin();
        if(ind == 0){
            if(v[0] == coins[i]){
                cout<<1<<endl;
            }
            else{
                cout<<0<<endl;
            }
        }
        else{
            cout<<ind<<endl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    solve();
    return 0;
}