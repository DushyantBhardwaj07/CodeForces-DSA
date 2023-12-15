#include<bits/stdc++.h>
using namespace std;
#define yes "YES"
#define no "NO"
#define ll long long
#define mod 1000000007
void display(vector<string>v){ for(ll i=0;i<v.size();i++) cout<<v[i]<<' ';cout<<endl;}
void display2d(vector<vector<ll>> v){for(ll i=0;i<v.size();i++){for(ll j=0;j<v[i].size();j++){cout<<v[i][j]<<' ';}cout<<endl;}cout<<endl;}
ll add(vector<int>v){int sum = 0;for(int i=0;i<v.size();i++)sum = sum+v[i];return sum;}
bool isOdd(int n){if(n&1) return true;return false;}
bool isPrime(int n){if (n <= 1)return false;for (int i = 2; i <= n / 2; i++)if (n % i == 0)return false;return true;}
bool isVowel(char a){if(a=='a'||a=='e'||a == 'i'||a=='o'||a=='u'||a=='y'){return true;}return false;}


string solve(){
    ll n,k; cin>>n>>k;
    vector<string>v;
    vector<ll>dig;
    string s;
    bool flag = false;
    ll limit = pow(2, k)-1;
    map<ll,ll>m;
    for(int i=0;i<n;i++){
        cin>>s;
        v.push_back(s);
    }
    // display(v);
    for(int i=0;i<n;i++){
        ll pos = -1;
        map<ll,ll>mpp;
        for(int bit = 0; bit < k; bit++){
            if(v[i][bit] == '1'){
                pos = bit;
                mpp[pos] = bit;
            }
        }

        if(mpp.size() == 1){
            if(m.find(pos) == m.end()) m[pos]++;
        }
    }

    string res = "";
    if(m.size() == k){
        res = yes;
    }
    else{
        res = no;
    }

    for(int i=0;i<dig.size();i++){
        for(int j = i+1;j<dig.size();j++){
            ll result = (dig[i] | dig[j]) - 1;
        }
    }
    return res;    
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
