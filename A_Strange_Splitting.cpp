#include<bits/stdc++.h>
using namespace std;
#define yes "YES"
#define no "NO"
#define ll long long
#define mod 1000000007
#define endl "\n"
void display(vector<ll>v){ for(ll i=0;i<v.size();i++) cout<<v[i]<<' ';cout<<endl;}
void display2d(vector<vector<ll>> v){for(ll i=0;i<v.size();i++){for(ll j=0;j<v[i].size();j++){cout<<v[i][j]<<' ';}cout<<endl;}cout<<endl;}
ll add(vector<int>v){int sum = 0;for(int i=0;i<v.size();i++)sum = sum+v[i];return sum;}
bool isOdd(int n){if(n&1) return true;return false;}
bool isPrime(int n){if (n <= 1)return false;for (int i = 2; i <= n / 2; i++)if (n % i == 0)return false;return true;}
bool isVowel(char a){if(a=='a'||a=='e'||a == 'i'||a=='o'||a=='u'||a=='y'){return true;}return false;}

void solve(){
    ll n; cin>>n;
    vector<ll>v(n,0);
    for(int i=0;i<n;i++) cin>>v[i];
    bool flag =1;
    for(int i=1;i<n;i++){
        if(v[i] != v[i-1]){
            flag = 0;
        }
    }
    if(flag){
        cout<<no<<endl;
        return;
    }

    for(int i=0;i<n;i++){
        ll mini = INT_MAX;
        ll maxi = INT_MIN;
        for(int j=0;j<n;j++){
            if(i !=j){
                mini = min(mini, v[j]);
                maxi = max(maxi, v[j]);
            }
        }
        if((maxi - mini) != 0){
            cout<<yes<<endl;
            for(int j=0;j<n;j++){
                if(i == j){
                    cout<<"R";
                }
                else{
                    cout<<"B";
                }
            }
            cout<<endl;
            return;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    ll t;cin>>t;
    while(t-->0){
        solve();
    }
    return 0;
}