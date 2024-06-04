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
    vector<pair<ll,ll>>v;
    ll c, p;
    for(int i=0;i<n;i++){
        cin>>c>>p;
        v.push_back({c,p});
    }
    ll k; cin>>k;
    vector<pair<ll,ll>>tables;
    for(int i=0;i<k;i++){
        cin>>c;
        tables.push_back({c, i});
    }
    sort(tables.begin(), tables.end());
    vector<bool>vis(n+1, false);
    ll ans = 0;
    vector<pair<ll,ll>>ansvec;
    for(int i=0;i<tables.size();i++){
        ll maxi = 0;
        ll ind = n;
        bool flag = false;
        for(int j = 0;j<v.size();j++){
            if((v[j].first<=tables[i].first) && !vis[j]){
                if(v[j].second > maxi){
                    maxi = v[j].second;
                    ind = j;
                    flag = true;
                }
            }
        }
        vis[ind] = true;    
        if(flag) ansvec.push_back({ind+1, tables[i].second+1});
        ans = ans + maxi;
    }

    cout<<ansvec.size()<<" "<<ans<<endl;
    for(auto it : ansvec){
        cout<<it.first<<" "<<it.second<<endl;
    }

}

int main()
{
    ios::sync_with_stdio(false);
    solve();
    return 0;
}