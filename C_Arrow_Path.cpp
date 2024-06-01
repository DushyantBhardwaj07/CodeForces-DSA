#include<bits/stdc++.h>
using namespace std;
#define yes "YES"
#define no "NO"
#define ll long long
#define mod 1000000007
void display(vector<ll>v){ for(ll i=0;i<v.size();i++) cout<<v[i]<<' ';cout<<endl;}
void display2d(vector<vector<bool>> v){for(ll i=0;i<v.size();i++){for(ll j=0;j<v[i].size();j++){cout<<v[i][j]<<' ';}cout<<endl;}cout<<endl;}
ll add(vector<int>v){int sum = 0;for(int i=0;i<v.size();i++)sum = sum+v[i];return sum;}
bool isOdd(int n){if(n&1) return true;return false;}
bool isPrime(int n){if (n <= 1)return false;for (int i = 2; i <= n / 2; i++)if (n % i == 0)return false;return true;}
bool isVowel(char a){if(a=='a'||a=='e'||a == 'i'||a=='o'||a=='u'||a=='y'){return true;}return false;}


string solve(){
    ll n; cin>>n;
    vector<vector<char>>v(2, vector<char>(n, '.'));
    for(int i=0;i<n;i++) cin>>v[0][i];
    for(int i=0;i<n;i++) cin>>v[1][i];

    list<pair<ll,ll>>ls;
    ls.push_back({0,0});
    vector<vector<bool>>vis(2, vector<bool>(n,false));
    vis[0][0] = true;
    bool flag = true;

    while(!ls.empty()){
        ll c = ls.size();
        while(c > 0){
            ll a = ls.front().first;
            ll b = ls.front().second;
            if(flag){
                if((b+1)<n && !vis[a][b+1]){
                    ls.push_back({a, b+1});
                    vis[a][b+1] = true;
                }

                if((a+1)<=1 && !vis[a+1][b]){
                    ls.push_back({a+1, b});
                    vis[a+1][b] = true;
                }

                if((b-1)>=0 && !vis[a][b-1]){
                    ls.push_back({a, b-1});
                    vis[a][b-1] = true;
                }

                if((a-1)>=0 && !vis[a-1][b]){
                    ls.push_back({a-1, b});
                    vis[a-1][b] = true;
                }
            }

            else if(!flag){
                if(((b+1)<n) &&  v[a][b] == '>' && !vis[a][b+1]){
                    vis[a][b+1] = true;
                    ls.push_back({a, b+1});
                }
                if(((b-1)>=0) && v[a][b] == '<' && !vis[a][b-1]){
                    vis[a][b-1] = true;
                    ls.push_back({a, b-1});
                }
            }

            ls.pop_front();
            c--;
            if(vis[1][n-1]) return yes;
        }
        flag = !flag;
    }

    if(vis[1][n-1]) return yes;

    return no;
}

int main()
{
    ios::sync_with_stdio(false);
    ll t;cin>>t;
    while(t-->0){
        cout<<solve()<<"\n";
    }
    return 0;
}