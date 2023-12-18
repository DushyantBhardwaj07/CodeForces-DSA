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
    ll na, nb, k, m; cin>>na>>nb>>k>>m;
    vector<ll> a(na, 0);
    vector<ll> b(nb, 0);
    for(int i=0;i<na;i++) cin>>a[i];
    for(int i=0;i<nb;i++) cin>>b[i];
    vector<ll>ans;

    for(int i=0;i<k;i++){
        ans.push_back(a[i]);
    }
    // display(ans);
    ll temp = ans.back();
    ll cnt = 0;
    for(int i=0;i<b.size() && cnt<m;i++){
        if(b[i] > temp){
            ans.push_back(b[i]);
            cnt++;
        }
    }
    // cout<<ans.size()<<endl;
    if(ans.size() >= k+m) return yes;
    return no;
}

int main()
{
    ios::sync_with_stdio(false);
    cout<<solve()<<endl;
    return 0;
}