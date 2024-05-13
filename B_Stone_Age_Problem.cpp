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

void solve(){
    ll n,k; cin>>n>>k;
    vector<ll>v(n,0);
    ll sum = 0;
    map<ll,ll>m;

    for(int i=0;i<n;i++){
        cin>>v[i];
        sum = sum + v[i];
        m[i+1] = v[i];
    }
    
    ll t,a,b;
    ll all = 0;
    for(int i=0;i<k;i++){
        cin>>t;
        if(t == 1){
            cin>>a>>b;
            if(m.find(a) != m.end()){
                sum = sum - m[a];
                m[a] = b;
                sum = sum + b;
            }
            else{
                sum = sum + b - all;
                m[a] = b;
            }
            cout<<sum<<endl;

        }
        else{
            cin>>a;
            all = a;
            m.clear();
            sum = a * n;
            cout<<sum<<endl;
        }

    }
}

int main()
{
    ios::sync_with_stdio(false);
    ll t =1;
    while(t-->0){
        solve();
    }
    return 0;
}