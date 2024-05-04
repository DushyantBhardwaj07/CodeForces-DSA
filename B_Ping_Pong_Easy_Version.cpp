#include<bits/stdc++.h>
using namespace std;
#define yes "YES"
#define no "NO"
#define ll long long
#define mod 1000000007
void display(vector<bool>v){ for(ll i=0;i<v.size();i++) cout<<v[i]<<' ';cout<<endl;}
void display2d(vector<vector<ll>> v){for(ll i=0;i<v.size();i++){for(ll j=0;j<v[i].size();j++){cout<<v[i][j]<<' ';}cout<<endl;}cout<<endl;}
ll add(vector<int>v){int sum = 0;for(int i=0;i<v.size();i++)sum = sum+v[i];return sum;}
bool isOdd(int n){if(n&1) return true;return false;}
bool isPrime(int n){if (n <= 1)return false;for (int i = 2; i <= n / 2; i++)if (n % i == 0)return false;return true;}
bool isVowel(char a){if(a=='a'||a=='e'||a == 'i'||a=='o'||a=='u'||a=='y'){return true;}return false;}


void dfs(ll x, ll y , set<ll> &vis, bool & ans, map<ll,vector<ll>> & m){
    if(ans) return;
    vis.insert(x);
    if(x == y){
        ans = true;
        return;
    }

    for(auto it : m[x]){
        if(vis.find(it) == vis.end()){
            dfs(it, y, vis, ans, m);
        }
    }

}
void solve(){
    ll n; cin>>n;
    vector<pair<ll,ll>>v;
    map<ll,vector<ll>>m;
    ll q, x, y;
    for(int i=0;i<n;i++){
        cin>>q>>x>>y;

        if(q == 1){
            for(int j = 0;j < v.size() ;j ++){
                if((v[j].first < x && x < v[j].second) || (v[j].first < y && y < v[j].second) ){
                    m[v.size() + 1].push_back(j +1);

                }

                if(( x< v[j].first && v[j].first < y) || (x < v[j].second && v[j].second < y)){

                    m[j+1].push_back(v.size() + 1);  

                }
                
            }
            v.push_back({x, y});
        }

        else{
            set<ll>vis;
            bool ans = false;
            dfs(x, y, vis, ans, m);            
            if(ans) cout<<yes<<"\n";
            else cout<<no<<"\n";
        }

    }
}

int main()
{
    ios::sync_with_stdio(false);
    solve();
    return 0;
}