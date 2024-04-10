#include<bits/stdc++.h>
using namespace std;
#define yes "Yes"
#define no "No"
#define ll long long
#define mod 1000000007
void display(vector<ll>v){ for(ll i=0;i<v.size();i++) cout<<v[i]<<' ';cout<<endl;}
void display2d(vector<vector<char>> v){for(ll i=0;i<v.size();i++){for(ll j=0;j<v[i].size();j++){cout<<v[i][j]<<' ';}cout<<endl;}cout<<endl;}
ll add(vector<int>v){int sum = 0;for(int i=0;i<v.size();i++)sum = sum+v[i];return sum;}
bool isOdd(int n){if(n&1) return true;return false;}
bool isPrime(int n){if (n <= 1)return false;for (int i = 2; i <= n / 2; i++)if (n % i == 0)return false;return true;}
bool isVowel(char a){if(a=='a'||a=='e'||a == 'i'||a=='o'||a=='u'||a=='y'){return true;}return false;}

vector<ll> diri = {0 ,0, 1, -1};
vector<ll> dirj = {1 ,-1, 0, 0};
bool dfs(int i, int j, int pari, int parj, vector<vector<bool>> & vis, vector<vector<char>> &v, bool & ans, char &c){
    vis[i][j] = true;

    for(int k=0;k<4;k++){
        ll tempi = i + diri[k];
        ll tempj = j + dirj[k];

        if(tempi >=0 && tempj >=0 && tempi < v.size() && tempj < v[0].size() && !vis[tempi][tempj] && v[tempi][tempj] == c){
           if(dfs(tempi, tempj, i, j, vis, v, ans, c)) return true;
        }

        else if(tempi >=0 && tempj >=0 && tempi < v.size() && tempj < v[0].size() && vis[tempi][tempj] && v[tempi][tempj] == c){
            if(tempi != pari && tempj != parj){
                return true;
            }
        }
    }
    return false;
}

string solve(){
    ll n, m; cin>>n>>m;
    vector<vector<char>>v(n, vector<char>(m,'0'));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            vector<vector<bool>>vis(n, vector<bool>(m, false));
            bool ans = false;
            if(dfs(i, j, -1, -1, vis, v, ans, v[i][j])) return yes;
        }
    }
    return no;


}

int main()
{
    ios::sync_with_stdio(false);
    cout<<solve()<<"\n";
    return 0;
}