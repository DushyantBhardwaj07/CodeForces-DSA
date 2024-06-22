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
    vector<ll>v(n,0);
    ll s = 0;
    for(int i=0;i<n;i++) cin>>v[i];
    for(int i=0;i<n;i++) s = s + v[i];

    if(s%3 != 0) return 0;
    s = s/3;
    vector<ll>temp(n,0);
    ll sum = 0;
    for(int i=n-1;i>=0;i--){
        sum = sum + v[i];
        if(sum == s){
            temp[i] = 1;
        }
    }


    for(int i = n-2;i>=0;i--){
        temp[i] = temp[i] + temp[i+1];
    }


    ll ans = 0;
    ll summ = 0;
    for(int i =0;i<n-2;i++){
        summ = summ + v[i];
        if(summ == s){
            ans = ans + temp[i+2];
        }
    }

    return ans;

}

int main()
{
    ios::sync_with_stdio(false);
    cout<<solve()<<"\n";
    return 0;
}