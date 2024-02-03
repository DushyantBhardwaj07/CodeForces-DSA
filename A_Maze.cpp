#include<bits/stdc++.h>
using namespace std;
#define yes "YES"
#define no "NO"
#define ll long long
#define mod 1000000007
void display(vector<ll>v){ for(ll i=0;i<v.size();i++) cout<<v[i]<<' ';cout<<endl;}
void display2d(vector<vector<char>> v){for(ll i=0;i<v.size();i++){for(ll j=0;j<v[i].size();j++){cout<<v[i][j];}cout<<endl;}cout<<endl;}
ll add(vector<int>v){int sum = 0;for(int i=0;i<v.size();i++)sum = sum+v[i];return sum;}
bool isOdd(int n){if(n&1) return true;return false;}
bool isPrime(int n){if (n <= 1)return false;for (int i = 2; i <= n / 2; i++)if (n % i == 0)return false;return true;}
bool isVowel(char a){if(a=='a'||a=='e'||a == 'i'||a=='o'||a=='u'||a=='y'){return true;}return false;}


void dfs(int i , int j, vector<vector<char>> &v, vector<vector<bool>> &vis, ll &k, int n , int m){
    if(k == 0) return;
    vis[i][j]= true;


    if(j<m-1 && !vis[i][j+1] && v[i][j+1] == '.') dfs(i, j+1, v, vis, k, n , m);
    if(i < n-1 && !vis[i+1][j] && v[i+1][j] == '.') dfs(i+1, j, v, vis, k, n ,m);
    if(j > 0 && !vis[i][j-1] && v[i][j-1] == '.') dfs(i, j-1, v, vis, k, n, m);
    if(i > 0 && !vis[i-1][j] && v[i-1][j] == '.') dfs(i-1, j, v, vis, k, n , m);

    if(k>0){
        k--;    
        v[i][j] = 'X';
    }

}


void solve(){
    ll n, m, k; cin>>n>>m>>k;
    vector<vector<char>>v(n, vector<char>(m, '0'));

    vector<vector<bool>>vis(n, vector<bool>(m, false));

    bool flag = true;
    ll sti =0, stj = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
            if(flag && v[i][j] == '.'){
                sti = i; stj = j;
                flag = false;
            }
        }
    }

    dfs(sti, stj, v, vis, k, n, m); 
    display2d(v);

}

int main()
{
    ios::sync_with_stdio(false);
    solve();
    return 0;
}