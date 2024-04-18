#include<bits/stdc++.h>
using namespace std;
#define yes "YES"
#define no "NO"
#define ll long long
#define mod 1000000007
void display(vector<ll>v){ for(ll i=0;i<v.size();i++) cout<<v[i]<<' ';cout<<endl;}
void display2d(vector<vector<ll>> v){for(ll i=0;i<v.size();i++){for(ll j=0;j<v[i].size();j++){cout<<v[i][j]<<' ';}cout<<endl;}cout<<endl;}
int add(vector<int>v){int sum = 0;for(int i=0;i<v.size();i++)sum = sum+v[i];return sum;}
bool isOdd(int n){if(n&1) return true;return false;}
bool isPrime(int n){if (n <= 1)return false;for (int i = 2; i <= n / 2; i++)if (n % i == 0)return false;return true;}
bool isVowel(char a){if(a=='a'||a=='e'||a == 'i'||a=='o'||a=='u'||a=='y'){return true;}return false;}

ll sumOfDigits(ll n){
    ll sum = 0;
    while(n > 0){
        sum = sum+n%10;
        n = n/10;
    }
    return sum;
}
ll calculate(ll i, ll a){
    ll ans = i;
    while((a-1)>0){
        ans = ans*i;
        a--;
    }
    return ans;
}
void solve(){
    vector<ll>ans;
    ll a,b,c; cin>>a>>b>>c;
    for(ll i=1;i<=81;i++){
        ll temp = (b*calculate(i,a)) + c;
        if(i == sumOfDigits(temp) && temp<1e9 && temp>=0) ans.push_back(temp);
    }
    cout<<ans.size()<<endl;
    display(ans);
}

int main()
{
    ios::sync_with_stdio(false);
    solve();
    return 0;
}