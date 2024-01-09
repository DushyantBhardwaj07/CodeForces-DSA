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
    ll n, m; cin>>n>>m;
    vector<ll>v(n,0);
    for(int i=0;i<n;i++) cin>>v[i];
    vector<ll>preSum;
    preSum.push_back(v[0]);
    for(int i=1;i<v.size();i++){
        preSum.push_back(preSum.back() + v[i]);
    }

    ll l, r;
    for(int i=0;i<m;i++){
        cin>>l>>r;
        l--;
        r--;
        ll temp = 0;
        if(l == 0){
            temp = preSum[r];
        }

        else{
            temp = preSum[r] - preSum[l];
        }

        if(temp == 0) cout<<1<<endl;
        else{
            cout<<0<<endl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    solve();
    return 0;
}