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


void dfs(ll i, ll j, ll n, ll m, vector<pair<ll,ll>> &v, vector<vector<bool>> &vis){
    vis[i][j] = true;
    v.push_back({i, j});

    if(j < m && !vis[i][j+1]) dfs(i, j+1, n, m, v, vis);
    else if(j == m && i<n && !vis[i+1][j] && vis[i][j-1]) dfs(i+1, j, n, m, v, vis);

    if(j > 0 && !vis[i][j-1])  dfs(i, j-1, n, m, v, vis);
    else if(j == 0 && i<n && !vis[i+1][j] && vis[i][j+1]) dfs(i+1, j, n, m, v, vis);
}

void solve(){
    ll n, m, k; cin>>n>>m>>k;
    vector<pair<ll,ll>> v;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    dfs(0,0,n-1,m-1,v, vis);

    for(int i=0;i<v.size();i++){
        v[i].first++;
        v[i].second++;
    }

    vector<vector<ll>>ans;

    ll j = 0;

    for(int i = 0; i<k-1 ;i++){
        ans.push_back({v[j].first, v[j].second});
        j++;
        ans.back().push_back(v[j].first);
        ans.back().push_back(v[j].second);
        j++;
    }


    vector<ll>temp;
    for(;j<v.size();j++){
        temp.push_back(v[j].first);
        temp.push_back(v[j].second);
    }

    ans.push_back(temp);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i].size() / 2<<" ";
        for(int j = 0; j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }


}

int main()
{
    ios::sync_with_stdio(false);
    solve();
    return 0;
}