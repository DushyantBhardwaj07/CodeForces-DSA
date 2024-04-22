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

void dfs(ll node, vector<ll> adj[], vector<bool> &vis, ll &red, ll &blue, char c){
    vis[node] = true;
    for(auto it : adj[node]){
        if(!vis[it]){
            if(c == 'r'){
                blue++;
                dfs(it, adj, vis, red, blue,'b');
            }
            else{
                red++;
                dfs(it, adj, vis, red, blue,'r');
            }
        }
    }
}

ll solve(){
    ll n; cin>>n;
    vector<ll>adj[n+1];
    ll u,v;
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll red = 0;
    ll blue = 0;
    vector<bool>vis(n+1, false);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            red++;
            char c = 'r';
            dfs(i, adj, vis, red, blue,c);
        }
    }
    ll totposedges = red*blue;
    ll ans = totposedges - (n-1);
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    ll t = 1;
    while(t-->0){
        cout<<solve()<<"\n";
    }
    return 0;
}