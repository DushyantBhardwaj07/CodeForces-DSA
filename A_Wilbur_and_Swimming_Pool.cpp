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
    ll n; cin>>n;
    vector<pair<int,int>>v;
    ll x, y;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        v.push_back({x, y});
    }

    if(n == 1) return -1;
    if(n == 2){
        if(v[0].first == v[1].first || v[0].second == v[1].second){
            return -1;
        }
    }

    for(int i=0;i<v.size();i++){
        for(int j= i+1;j<v.size();j++){
            if(v[i].first != v[j].first && v[i].second != v[j].second){
                
                ll s1 = abs((v[i].first) - (v[j].first));
                ll s2 = abs((v[i].second) - (v[j].second));
                return s1*s2;
            } 
        }
    }
    return -1;

}

int main()
{
    ios::sync_with_stdio(false);
    cout<<solve()<<endl;
    return 0;
}