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


void dfs(ll node, vector<bool> &vis, vector<ll> adj[] ){
    vis[node] = true;
    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(it, vis, adj);
        }
    }
}

ll solve(){
    ll n; cin>>n;
    ll x,y;
    vector<pair<ll,ll>>v;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        v.push_back({x, y});
    }

    vector<ll> adj[1001];
    vector<bool>vis(1001, false);

    for(int i=0;i<v.size();i++){
        for(int j=0;j<v.size();j++){
            if((i!=j) && (v[i].first == v[j].first || v[i].second == v[j].second)){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    ll ans = 0;

    for(int i=0;i<n;i++){
        if(!vis[i]){
            ans++;
            dfs(i, vis, adj);
        }
    }

    return ans-1;

}

int main()
{
    ios::sync_with_stdio(false);
    cout<<solve()<<"\n";
    return 0;
}