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
    ll n, k; cin>>n >> k;
    vector<ll>v(n, 0);
    map<ll,vector<ll>>m;
    for(int i=0;i<n;i++){
        cin>>v[i];
        m[v[i]].push_back(i+1);
    }
    sort(v.begin(), v.end());
    vector<ll>ans;
    for(int i=0; i<v.size() && k > 0;i++){
        if(v[i] > k) break;
        k = k - v[i];
        ans.push_back(m[v[i]].back());
        m[v[i]].pop_back();
    }

    cout<<ans.size()<<endl;
    sort(ans.begin(), ans.end());
    display(ans);
}

int main()
{
    ios::sync_with_stdio(false);
    solve();
    return 0;
}