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
bool isPrime(ll &n){if (n <= 1)return false;for (int i = 2; i <= n / 2; i++)if (n % i == 0)return false;return true;}
bool isVowel(char a){if(a=='a'||a=='e'||a == 'i'||a=='o'||a=='u'||a=='y'){return true;}return false;}

bool prime[100005];
void SieveOfEratosthenes(int n)
{
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
}


ll nextPrime(ll &n){
    for(int i = n ; i<= 100003; i++){
        if(prime[i]) return i;
    }

}

ll solve(){
    ll n, m; cin>>n>>m;
    vector<vector<ll>>v(n,vector<ll>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }

    ll mini = INT_MAX;

    for(int i=0;i<n;i++){
        ll ans = 0;
        for(int j=0;j<m;j++){
            ll temp = nextPrime(v[i][j]);
            ans = ans+(temp - v[i][j]);
        }
        mini = min(ans, mini);
    }


    for(int j=0;j<m;j++){
        ll ans = 0;
        for(int i=0;i<n;i++){
            ll temp = nextPrime(v[i][j]);
            ans = ans+(temp - v[i][j]);
            
        }
        mini = min(ans, mini);
    }

    return mini;
}

int main(){
    SieveOfEratosthenes(100003);
    prime[0] = 0;
    prime[1] = 0;
    cout<<solve()<<endl;
    return 0;
}