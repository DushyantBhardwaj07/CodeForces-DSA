#include<bits/stdc++.h>
using namespace std;
#define yes "YES"
#define no "NO"
#define ll long long
#define mod 1000000007
void display(vector<ll>v){ for(ll i=0;i<v.size();i++) cout<<v[i]<<' ';cout<<endl;}
void display2d(vector<vector<ll>> v){for(ll i=0;i<v.size();i++){for(ll j=0;j<v[i].size();j++){cout<<v[i][j]<<' ';}cout<<endl;}}
ll add(vector<int>v){int sum = 0;for(int i=0;i<v.size();i++)sum = sum+v[i];return sum;}
bool isOdd(int n){if(n&1) return true;return false;}
bool isPrime(int n){if (n <= 1)return false;for (int i = 2; i <= n / 2; i++)if (n % i == 0)return false;return true;}
bool isVowel(char a){if(a=='a'||a=='e'||a == 'i'||a=='o'||a=='u'||a=='y'){return true;}return false;}

vector<ll> x = {0,0,-1,1};
vector<ll> y = {1,-1,0,0};

ll check(int i, int j, vector<vector<ll>> &grid){
    ll maxi = INT_MIN;
    for(int k=0;k<4;k++){
        int xx = x[k]+i;
        int yy = y[k]+j;
        if(xx>=0 && xx< grid.size() && yy>=0 && yy<grid[0].size()){
            maxi = max(maxi, grid[xx][yy]);            
        }
    }
    return maxi;
}

void solve(){
    ll n,m; cin>>n>>m;
    vector<vector<ll>>v(n, vector<ll>(m, 0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }    
    
    for(int i=0;i<n;i++){            
        for(int j=0;j<m;j++){
            ll c = check(i,j,v);
            if(c > v[i][j]){
                continue;
            }
            else{
                v[i][j] = c;
            }
        }
    }


    display2d(v);
}

int main()
{
    ios::sync_with_stdio(false);
    ll t;cin>>t;
    while(t-->0){
        solve();
    }
    return 0;
}