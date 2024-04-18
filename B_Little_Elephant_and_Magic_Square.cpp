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
    vector<vector<ll>>v(3, vector<ll>(3,0));
    for(int i=0;i < 3; i++){
        for(int j=0;j<3;j++){
            cin>>v[i][j];
        }
    }
    ll x = 0,y = 0,z = 0;
    x = (v[0][2] + v[1][2] + v[0][1] + v[2][1] - v[1][0] - v[2][0])/2;
    y = v[0][2] + v[1][2] - x;
    z = v[0][1] + v[2][1] - x;
    v[0][0] = x;
    v[1][1] = y;
    v[2][2] = z;
    display2d(v);
}

int main()
{
    ios::sync_with_stdio(false);
    solve();
    return 0;
}