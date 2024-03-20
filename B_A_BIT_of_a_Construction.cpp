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
    ll n, k; cin>>n>>k;
    vector<ll>ans(n,0);


    if(n == 1){
        ans[0] = k;
        display(ans);
        return;
    }

    if(!((k+1) & k)){
        ans[0] = k;
        display(ans);
        return;
    }  

    for(int i=30;i>0;i--){
        ll temp = 1<<i;

        if(temp <= k){
            ans[0] = temp-1;
            ans[1] = k - (temp-1);
            break;
        }
    }

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