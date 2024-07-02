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

ll solve(){
    ll n, m; cin>>n>>m;
    vector<ll>ve(n, 0);
    vector<ll>adj[n+1];
    priority_queue<pair<int, int>>pq;
    for(int i=0; i<n ;i++){
        cin>>ve[i];
        pq.push({ve[i], i+1});
    }

    ll u = 0, v = 0;

    for(int i=0;i<m;i++){
        cin>>u>>v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    vector<bool>vis(n + 1, false);
    ll ans = 0;
    
    while(!pq.empty()){
        ll cost = pq.top().first;
        ll node = pq.top().second;
        for(auto it : adj[node]){
            if(!vis[it]){
                vis[node] = true;
                ans = ans + min(cost, ve[it-1]);
            }
        }
        pq.pop();               
    }

    return ans;
    
}

int main()
{
    ios::sync_with_stdio(false);
    cout<<solve()<<endl;
    return 0;
}