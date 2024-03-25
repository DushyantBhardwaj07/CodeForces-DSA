#include<bits/stdc++.h>
using namespace std;
#define yes "YES"
#define no "NO"
#define ll long long
#define mod 1000000007
void display(vector<ll>v){ for(ll i=0;i<v.size();i++) cout<<v[i]<<' ';cout<<endl;}
void display2d(vector<vector<ll>> v){for(ll i=0;i<v.size();i++){for(ll j=0;j<v[i].size();j++){cout<<v[i][j]<<' ';}cout<<endl;}cout<<endl;}
bool isOdd(int n){if(n&1) return true;return false;}
bool isPrime(int n){if (n <= 1)return false;for (int i = 2; i <= n / 2; i++)if (n % i == 0)return false;return true;}
bool isVowel(char a){if(a=='a'||a=='e'||a == 'i'||a=='o'||a=='u'||a=='y'){return true;}return false;}

ll solve(){
    ll n,W; cin>>n>>W;    
    vector<ll>w(n,0);
    map<ll,ll>m;
    for(int i=0;i<n;i++){
        cin>>w[i];
        m[w[i]]++;
    }
    ll h = 1;
    ll rem = W;
    while(!m.empty()){
        auto itr = m.begin();
        
        if(itr->first > rem){
            h++;
            rem = W;
        }

        auto it = m.lower_bound(rem);
        if(it->first > rem){
            it--;
        }
        ll div = rem/it->first;
        if(div >= it->second){
            m.erase(it);
            rem = (rem - it->second*it->first);
        }
        else{
            it->second = it->second-div;
            rem = rem - (div * it->first);
        }
    }
    return h;

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