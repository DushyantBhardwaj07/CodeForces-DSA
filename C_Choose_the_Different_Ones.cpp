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
    ll n,m,k; cin>>n>>m>>k;
    vector<ll>v1(n,0);
    vector<ll>v2(m,0);
    for(int i=0;i<n;i++) cin>>v1[i];
    for(int i=0;i<m;i++) cin>>v2[i];
    map<ll,ll>m1;
    map<ll,ll>m2;
    for(int i=0;i<n;i++) if(v1[i] <= k) m1[v1[i]]++;
    for(int i=0;i<m;i++) if(v2[i] <= k) m2[v2[i]]++;
    set<ll>common;
    for(auto it : m1){
        if(m2.find(it.first) != m2.end()){
            common.insert(it.first);
        }
    }

    vector<ll>first;
    vector<ll>second;
    for(auto it: m1){
        if(common.find(it.first) == common.end()){
            first.push_back(it.first);
        }
    }
    for(auto it: m2){
        if(common.find(it.first) == common.end()){
            second.push_back(it.first);
        }
    }
    if(first.size() > k/2 || second.size() > k/2) return no;

    if(first.size()!=k/2 && second.size() == k/2){
        if(common.size() >= (k/2 - first.size())) return yes;
        return no;
    }

    if(first.size() ==k/2 && second.size() != k/2){
        if(common.size() >= (k/2 - second.size())) return yes;
        return no;
    }

    if(first.size() !=k/2 && second.size() != k/2){
        if(common.size() >= ((k/2 - second.size()) + (k/2 - first.size()))) return yes;
        return no;
    }

    return yes;


}

int main()
{
    ios::sync_with_stdio(false);
    ll t;cin>>t;
    while(t-->0){
        cout<<solve()<<endl;
    }
    return 0;
}