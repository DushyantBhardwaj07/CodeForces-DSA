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
    ll n,m; cin>>n>>m;
    vector<vector<ll>>v(n,vector<ll>(m,0));
    vector<ll>row;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
            if(i > 0){
                row.push_back(v[i][j]);
            }
        }        
    }
    ll ans = 0;
    ll start = 0;
    ll i =0;
    for(int j=0;j<m;j++){
        vector<ll>temp;
        ll sum = 0;
        for(int i=0;i<n;i++){
            temp.push_back(v[i][j]);
            sum = sum + v[i][j];
        }
        sort(temp.begin(), temp.end());
        for(int k=0;k<n;k++){
            ans = ans + sum-((n-k)*temp[k]);
            sum = sum - temp[k];
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;cin>>t;
    while(t-->0){
        cout<<solve()<<"\n";
    }
    return 0;
}