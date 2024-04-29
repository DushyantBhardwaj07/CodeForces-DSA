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
    ll n, m; cin>>n>>m;
    vector<ll>v(n*m, 0);
    ll flag = false;
    ll l = n*m;
    ll neg = 0;
    ll s = 0;
    ll summ = 0;
    vector<ll>v1(n*m, 0);
    for(int i=0;i<l;i++){
        cin>>v[i];
        if(v[i] == 0) flag = true;
        if(v[i] < 0){
            neg++;
        }
        summ = summ + abs(v[i]);
        v1[i] = abs(v[i]);
        // s = s + abs(v[i]);
    }

    sort(v1.begin(), v1.end());

    if(flag){
        ll sum = 0;
        for(int i=0;i<l;i++){
            sum = sum + abs(v[i]);
        }
        return sum;
    }

    if(neg %2 == 1){
        // cout<<v[0]<<endl;
        return summ - 2 * v1[0];
    }
    return summ;
}

int main()
{
    ios::sync_with_stdio(false);
    ll t;cin>>t;
    while(t-->0){
        cout<<solve()<<"\n";
    }
    return 0;
}