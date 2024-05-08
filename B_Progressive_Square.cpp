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

string solve(){
    ll n,c,d; cin>>n>>c>>d;
    map<ll,ll>m;
    ll l = n * n;
    vector<ll>v(l,0);
    vector<ll>v1(l, 0);
    vector<ll>eq(n,0);
    for(int i=0;i<l;i++){
        cin>>v[i];
        m[v[i]]++;
    }
    sort(v.begin(), v.end());
     for(int i=0; i<n; i++){
        eq[i] = v[0] + i*d;
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
                v1[i*n+(j)]= eq[i]+(c*j);
        }
    }
    // display(v1);
    sort(v1.begin(), v1.end());
    for(int i=0;i<l;i++){
        if(v1[i] != v[i]){
            return no;
        }
    }
    // cout<<m.size()<<endl;
    return yes;
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
