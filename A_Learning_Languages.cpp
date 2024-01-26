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


void dfs(int node, vector<bool> & vis,vector<ll>adjLis[]){
    vis[node] = true;

    for(auto it: adjLis[node]){
        if(!vis[it]){
            dfs(it, vis, adjLis);
        }
    }

}

ll solve(){
    ll n, m; cin>>n>>m;
    vector<ll>adjLisPer[n+1];
    vector<ll>adjLisLang[m+1];

    ll q,a;
    bool flag = true;
    for(int i=0;i<n;i++){
        cin>>q;
        if(q!=0) flag = false;
        for(int j=0;j<q;j++){
            cin>>a;
            adjLisPer[i].push_back(a);
            adjLisLang[a].push_back(i);
        }
    }
    // return 1;
    // vector<bool>vis(max(n,m) + 1, false);

    vector<ll>adjLis[n];

    for(int i=0;i<n;i++){
        // cout<<i << " - ";
        for(auto it : adjLisPer[i]){
            for(auto itr : adjLisLang[it]){
                adjLis[i].push_back(itr);
            }
            // cout<<it << " ";
        }
        cout<<endl;
    }

    // for(int i=0;i<n;i++){
    //     cout<<i<<" - ";
    //     for(auto it : adjLis[i]){
    //         cout<<it<<" ";
    //     }
    //     cout<<endl;
    // }
    ll ans = 0;
    vector<bool>vis(n+1, false);

    for(int i=0;i<n;i++){
        if(!vis[i]){
            ans++;
            dfs(i, vis, adjLis);                        
        }
    }
    if(flag) return ans;
    ans--;
    return ans;

}

int main()
{
    ios::sync_with_stdio(false);
    cout<<solve()<<endl;
    return 0;
}