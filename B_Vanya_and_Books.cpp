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

ll solve(){
    ll n; cin>>n;
    if(n<10) return n;

    if(n<100){
        n = n-9;
        return 2*n + 9;
    }

    ll ans = 189; // 1 - 99

    vector<ll>v = {100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000};
    vector<string>vs = {"100", "1000", "10000", "100000", "1000000", "10000000", "100000000", "1000000000", "10000000000"};

    for(int i=0;i<v.size();i++){
        if(n >= v[i] && n <=v[i+1]){
            ans = ans + (n - v[i] + 1)*(vs[i].length());
            // cout<<(n - v[i] + 1) << " " <<(vs[i].length())<<endl;

            break;
        }
        else if(n > v[i] && n > v[i+1]){
            ans = ans + (v[i+1] -v[i]) * (vs[i].size());
        }
        else{
            break;
        }
    }

    if(n!=100 && binary_search(v.begin(), v.end(), n)) ans++;
    // if(n != 100 &&)
    return ans;
}


int main()
{
    ios::sync_with_stdio(false);
    cout<<solve()<<endl;
    return 0;
}