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
    ll j = 0, f = n;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    ll last = -1;
    bool flag = true;
    for(int i=0;i<v.size();i++){
        if(i>0){
            last = v[i-1];
            if(last != v[i]){
                flag = false;
            }
        }
    }
    
    // cout<<flag<<endl;
    if(flag) return -1;
    // display(v);
    for(int i=0;i<v.size();i++){
        if(v[0] != v[i]){
            // cout<<f<<endl;
            f = min(f, j);
            j = 0;
        }
        else{
            j++;
            // cout<<j<<endl;
        }
    }

    f = min(f, j);

    return f;
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
