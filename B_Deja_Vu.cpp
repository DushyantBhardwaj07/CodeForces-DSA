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

ll power(ll n, ll k){
    ll ans = 1;
    for(int i=0;i<k;i++){
        ans = ans * n;
    }
    return ans;
}

void solve(){
    ll n,k; cin>>n>>k;
    vector<ll>v(n,0);
    vector<ll>q(k,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    for(int i=0;i<k;i++){
        cin>>q[i];
    }

    map<ll,ll>m;

    vector<ll>temp;

    for(int i=0;i<k;i++){
        if(m.find(q[i]) == m.end()){
            temp.push_back(q[i]);
        }
        m[q[i]]++;
    }
    // display(temp);

    for(int i=0;i<temp.size();i++){
        ll t = power(2,temp[i]);
        ll t1 = power(2,temp[i]-1);
        for(int j=0;j<v.size();j++){
            if(v[j]%t == 0){
                v[j] = v[j] + t1;
            }
        }
    }

    display(v);

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