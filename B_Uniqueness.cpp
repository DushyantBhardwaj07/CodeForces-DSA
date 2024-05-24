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

bool check(map<ll,ll> &mv ){
    for(auto it: mv){
        if(it.second != 1) return false;
    }
    return true;
}
ll solve(){
    ll n; cin>>n;
    vector<ll>v(n,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    // Aage se
    map<ll,ll>prefix;
    ll left = 0, right = 0;
    ll preInd = 0;
    while(right<n){
        prefix[v[right]]++;
        if(prefix[v[right]] == 2){
            right--;
            break;
        }
        right++;
    }
    ll prefixRight = right;

    // Piche Se
    right = n-1;
    map<ll,ll>suffix;
    while(right>=prefixRight){
        suffix[v[right]]++;
        if(suffix[v[right]] == 2){
            right++;
            break;
        }
        right--;
    }
    cout<<prefixRight<<" "<<right<<endl;
    if(right == -1 || prefixRight == n || right == prefixRight) return 0;
    if(prefixRight<right) return prefixRight+(right-prefixRight);
    return abs(right-prefixRight)-1;
}

int main()
{
    ios::sync_with_stdio(false);
    cout<<solve()<<endl;
    return 0;
}