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
    int n; cin>>n;
    int maxi=-1;
    vector<ll>a(100005,0);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a[x]++;
        maxi=max(maxi,x);
    }
    vector<ll>b(100005,0);
    b[0]=0;
    b[1]=a[1];
    for(ll i=2;i<=100000;i++){
        b[i]=max(b[i-1],b[i-2]+(a[i]*i));
    }
    cout<<b[maxi];    
}

int main()
{
    ios::sync_with_stdio(false);
    solve();
    return 0;
}