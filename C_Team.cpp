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
    ll n, m, t ,k;
    cin>>n>>m;
    vector<ll>a(3000001, 0);
    
    if (n - 1 <= m && m <= 2*(n + 1))
    {
        if (m == n - 1) {
            a[0] = -1;
            a[m + 1] = -1;
            t = n - 1;
        }
        else if (m == n)
        {
            a[m + 1] = -1;
            t = n;
        }
        else t = n + 1;
        k = m % t;
        if (k == 0 && m != t) k = n + 1;
        if (a[0] == -1) cout<<"0";
        for (int i = 1; i <= n; i++)
        {
            if (a[i] != -1){
            if (k > 0) cout<<"110";
            else cout<<"10";
            k--;
            }
        }
        if (a[m + 1] != -1) {
            if (k > 0) cout<<"11"<<endl;
            else cout<<"1"<<endl;
        }
    }
    else cout<<"-1"<<endl;
    
}

int main()
{
    ios::sync_with_stdio(false);
    solve();
    return 0;
}