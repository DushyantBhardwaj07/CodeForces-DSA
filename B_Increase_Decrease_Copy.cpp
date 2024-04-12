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
    vector<ll>a(n,0);
    vector<ll>b(n+1,0);

    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n+1;i++) cin>>b[i];

    ll last = b.back();
    ll ans = 0;
    ll close = 0;
    ll mini = INT_MAX;

    for(int i=0;i<a.size();i++){
        mini = min(mini,abs(a[i] - last));
    }

    bool flag = 1;
    for(int i=0;i<a.size();i++){
        ll maxi = max(a[i], b[i]);
        ll mini = min(a[i], b[i]);

        if((mini <= last) && (maxi >= last) && flag){
            ans++;
            flag = 0;
        }
        ans = ans + maxi-mini;
    }
\
    if(flag){
        ll minix = INT_MAX;
        for(int i=0;i<b.size()-1;i++) minix = min(minix, abs(b[i] - last));
        ll temp = min(mini, minix);        
        ans++; //copy
        ans = ans + temp;

    }

    return ans;

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