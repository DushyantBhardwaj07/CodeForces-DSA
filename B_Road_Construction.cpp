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
    ll n,m; cin>>n>>m;
    ll a;
    map<ll,ll>mp;
    for(int i=0;i<2*m;i++){
        cin>>a;
        mp[a]++;
    } 
    ll temp = 0;
    for(int i=1;i<=n;i++){
        if(mp.find(i) == mp.end()){
            temp = i;
            break;
        }
    }
    vector<pair<ll,ll>>p;
    for(int i=1;i<=n;i++){
        if(i == temp) continue; 
        p.push_back({i,temp});
    }
    cout<<p.size()<<endl;
    for(int i=0;i<p.size();i++){
        cout<<p[i].first<<" "<<p[i].second<<endl;
    }

}

int main()
{
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
