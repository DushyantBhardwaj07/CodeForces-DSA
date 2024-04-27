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
    ll n; cin>>n;
    vector<ll>v(n,0);
    for(int i=0;i<n;i++) cin>>v[i];
    if(n == 2){
        cout<<2<<endl;
        display(v);
        return;
    }

    vector<ll>ans;
    vector<bool>vis(n+1, false);
    ans.push_back(v[0]);
    ans.push_back(v[1]);
    for(int i=2;i<n;i++){
        if((ans[ans.size()-2] < ans.back()) && (ans.back() < v[i])){
            ans.pop_back();
            ans.push_back(v[i]);
        }
        else if((ans[ans.size()-2] > ans.back()) && (ans.back() > v[i])){
            ans.pop_back();
            ans.push_back(v[i]);
        }
        else{
            ans.push_back(v[i]);
        }
    }

    cout<<ans.size()<<endl;
    display(ans);
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