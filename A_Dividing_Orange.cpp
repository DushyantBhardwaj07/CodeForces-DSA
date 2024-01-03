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
    vector<ll>v(k,0);
    map<ll,ll>m;
    for(int i=0;i<k;i++){
        cin>>v[i];
        m[v[i]]++;
    }
    // display(v);
    ll c = 0;
    for(int i=0;i<k;i++){
        c = 0;
        cout<<v[i]<<" ";
        c++;
        for(int j=1;j<=n*k;j++){
            if(m.find(j) == m.end()){
                cout<<j<<" ";
                m[j]++;
                c++;
                if(c%n ==0){
                    cout<<endl;
                    break;
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    solve();
    return 0;
}