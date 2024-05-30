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
    ll sum = 0;
    for(int i=0;i<n;i++){
        cin>>v[i];
        sum = sum + v[i];
    }
    if(sum % 3 == 0) return 0;
    ll sumOfdigit = 0;
    ll sum1 = sum;
    while(sum1 > 0){
        sumOfdigit += sum1%10;
        sum1 = sum1/10;
    }
    if(sumOfdigit % 3 == 2){
        return 1;
    }
    if(sumOfdigit % 3 == 1){
        for(int i=0;i<n;i++){
            ll s = 0;
            while(v[i] > 0){
                s += v[i]%10;
                v[i] = v[i]/10;
            }
            if(s % 3 == 1){
                return 1;
            }
        }
    }
    return 2;


}

int main()
{
    ios::sync_with_stdio(false);
    ll t;cin>>t;
    while(t-->0){
        cout<<solve()<<endl;
    }
    return 0;
}