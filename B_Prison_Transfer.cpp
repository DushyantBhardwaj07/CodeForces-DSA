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


ll nCr(ll n, ll r){
    double sum = 1;
    for(int i = 1; i <= r; i++){
        sum = sum * (n - r + i) / i;
    }
    return sum;
}
ll solve(){
    ll n, t, c; cin>>n>>t>>c;
    vector<ll>v(n,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    ll left = 0, right = 0;
    ll ans = 0;
    while(right<n){
        if(v[right] <= t) right++;
        else{
            if( (right-left) >= c){
                ans = ans + (right-left)-c+1;
            }
            left = right;
            while((left<n) && v[left] > t ){
                left++;
                right++;
            }
            right++;
        }
    }
    bool flag = 0;
    for(int i=left;i<right;i++){
        if(v[i] > t) flag = 1;
    }
    if(flag == 0){
        if( (right-left) >= c){
            ans = ans + (right-left)-c+1;
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cout<<solve()<<endl;
    return 0;
}