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

vector<ll>dp1(1001, -1);
vector<ll>dp2(1001, -1);
 
ll helper1(ll n, ll k){
    if(n<0){
        return 0;
    }
    else if(n == 0){
        return 1;
    }

    if(dp1[n] != -1) return dp1[n];

    ll ans = 0;
    for(int i= 1;i<=k;i++){
        if(n>=i){
            ans = ((ans%mod) + (helper1(n-i, k)%mod))%mod;
        }
    }

    return dp1[n] = ans%mod;
}

ll helper2(ll n, ll k, ll d){
    if(n<0){
        return 0;
    }
    else if(n == 0){
        return 1;
    }

    if(dp2[n] != -1) return dp2[n];

    ll ans = 0; 
    for(int i= 1;i<=k;i++){
        if((n>=i) && (i<d)){
            ans = ((ans%mod) + (helper2(n-i, k, d)%mod))%mod;
        }
    }

    return dp2[n] = ans%mod;
}

ll solve(){
    ll n,k,d; cin>>n>>k>>d;
    ll temp = helper1(n, k) - helper2(n, k, d);
    if(temp<0){
        return mod+temp;
    }
    return temp;
   
}

int main()
{
    ios::sync_with_stdio(false);
    cout<<solve()<<endl;
    return 0;
}