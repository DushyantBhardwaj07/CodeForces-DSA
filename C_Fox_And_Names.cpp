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

void checkCycle(ll node, vector<int>adj[27], vector<bool> & vis,vector<bool> &path ,bool &ans){
    vis[node] = true;
    path[node] = true;
    for(auto it : adj[node]){
        if(!vis[it]){
            checkCycle(it, adj, vis, path, ans);
        }
        else if(path[it]){
            ans = true;
        }
    }
    path[node] = false;
}

void dfs(ll node, vector<int>adj[27], vector<bool> & vis, vector<ll> &topo){
    vis[node] = true;
    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(it, adj, vis, topo);            
        }
    }
    topo.push_back(node);
}

string solve(){
    ll n; cin>>n;
    vector<string>v;
    string s; 
    for(int i=0;i<n;i++){
        cin>>s;
        v.push_back(s);
    }
    vector<int>adj[27];
    ll i = 0;
    bool flag = false;
    while(i < n-1){
        ll j = 0;
        while(j < min(v[i].length(), v[i+1].length())){
            if(v[i][j] != v[i+1][j]){
                adj[v[i][j] - 'a'].push_back(v[i+1][j] - 'a');
                flag = true;
                break;
            }
            j++;
        }
        i++;
    }
    if(!flag){
        for(int i = 1;i<v.size();i++){
            if(v[i-1].size() > v[i].size()) return "Impossible";
        }
    }
    // if(!flag) return "Impossible";
    // for(int i=0;i<27;i++){
    //     cout<<i<<" - ";
    //     for(auto it: adj[i]){
    //         cout<<it<<" ";
    //     }
    //     cout<<endl;
    // }

    for(int i = 0;i < 27; i++){
        vector<bool>vis(27, false);
        vector<bool>path(27, false);
        bool ans = false;
        checkCycle(i, adj, vis, path, ans);
        if(ans) return "Impossible";
    }

    vector<ll>topo;
    vector<bool>vis1(27, false);
    for(int i = 0;i<26; i++){
        if(!vis1[i]){
            dfs(i, adj, vis1, topo);
        }
    }
    reverse(topo.begin(), topo.end());
    string ans = "";

    for(int i =0;i<topo.size();i++){
        ans = ans + (char)(topo[i] + 'a');
    }
    return  ans;


}

int main()
{
    ios::sync_with_stdio(false);
    cout<<solve()<<"\n";
    return 0;
}