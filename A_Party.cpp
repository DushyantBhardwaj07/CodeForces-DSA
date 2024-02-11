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


void dfs(int node,vector<ll>adj[], vector<bool> &vis, vector<ll> & temp){
    vis[node] = true;
    for(auto it : adj[node]){
        if(it!=-1 && !vis[it]){
            temp.push_back(it);
            dfs(it,adj, vis, temp);
        }
    }
}

ll solve(){
    ll n; cin>>n;
    vector<ll>adj[n+1];
    ll a;
    for(int i=1;i<=n;i++){
        cin>>a;
        adj[i].push_back(a);
    }
    map<ll, vector<ll>>m;
    for(int i=1;i<=n;i++){
        vector<bool>vis(n+1, false);
        vector<ll>temp;
        dfs(i, adj, vis, temp);
        m[i] = temp;
    }
    ll mini = INT_MIN;
    for(auto it : m){
        mini = max(mini,(ll) it.second.size());
    }
    return mini+1;
}

int main()
{
    ios::sync_with_stdio(false);
    cout<<solve()<<"\n";
    return 0;
}