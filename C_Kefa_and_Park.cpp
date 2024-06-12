#include<bits/stdc++.h>
using namespace std;
#define yes "YES"
#define no "NO"
#define ll long long
#define mod 1000000007
void display(vector<bool>v){ for(ll i=0;i<v.size();i++) cout<<v[i]<<' ';cout<<endl;}
void display(vector<ll>v){ for(ll i=0;i<v.size();i++) cout<<v[i]<<' ';cout<<endl;}
void display2d(vector<vector<ll>> v){for(ll i=0;i<v.size();i++){for(ll j=0;j<v[i].size();j++){cout<<v[i][j]<<' ';}cout<<endl;}cout<<endl;}
ll add(vector<int>v){int sum = 0;for(int i=0;i<v.size();i++)sum = sum+v[i];return sum;}
bool isOdd(int n){if(n&1) return true;return false;}
bool isPrime(int n){if (n <= 1)return false;for (int i = 2; i <= n / 2; i++)if (n % i == 0)return false;return true;}
bool isVowel(char a){if(a=='a'||a=='e'||a == 'i'||a=='o'||a=='u'||a=='y'){return true;}return false;}

void dfs(int node, vector<bool> &vis, vector<ll> adj[], ll m, ll c, vector<ll> &cat){
    if(cat[node] == 1) c++;
    else c = 0;
    if(c > m) return;
    vis[node] = true;
    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(it, vis, adj, m, c, cat);
        }
    }
}

void leaves(int node,vector<ll> &leafs, vector<bool> &viss, vector<ll>adj[]){
    viss[node] = true;
    bool flag = true;
    for(auto it : adj[node]){
        if(!viss[it]){
            flag = false;
            leaves(it, leafs, viss,adj);
        }
    }
    if(flag){
        leafs.push_back(node);
    }
}

ll solve(){
    ll n, m; cin>>n>>m;
    vector<ll>cat(n+1,0);
    for(int i=1;i<=n;i++) cin>>cat[i];
    vector<ll>adj[n+1];
    ll u, v;
    map<ll,ll>mp;
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<ll>leafs;
    vector<bool>viss(n+1, false);
    leaves(1, leafs, viss, adj);
    // display(leafs);
    vector<bool>vis(n+1, false);
    ll c = 0;
    dfs(1, vis, adj, m, c, cat);  
    // display(vis);
    ll ans = 0;
    for(int i=0;i<leafs.size();i++){
        if(vis[leafs[i]]) ans++;
    }
    return ans;

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t =1;
    while(t-->0){
        cout<<solve()<<"\n";
    }
    return 0;
}