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

ll combination(ll n, ll r){
    double sum = 1;
    for(int i = 1; i <= r; i++){
        sum = sum * (n - r + i) / i;
    }
    return sum;
}
ll solve(){
    ll n,d; cin>>n>>d;
    vector<ll>v(n,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    ll ans = 0;
    for(ll i=0;i<v.size();i++){
        ll ind = lower_bound(v.begin(), v.end(), v[i] + d) - v.begin();
        if(v[ind]!=v[i]+d){
            ind--;
        }
        // cout<<i<<" "<<ind<<endl;
        if(ind>=v.size()){
            ind = v.size()-1;
        }

        ans = ans+combination(ind - i,2);
        // cout<<"ans = "<<ans<<endl;
    }
    return ans;

}

int main()
{
    ios::sync_with_stdio(false);
    cout<<solve()<<endl;
    return 0;
}