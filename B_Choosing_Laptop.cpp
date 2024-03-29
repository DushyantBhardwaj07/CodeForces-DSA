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
    vector<vector<ll>>v;
    ll a;
    for(int i=0;i<n;i++){
        vector<ll>temp;
        for(int j=0;j<4;j++){
            cin>>a;
            temp.push_back(a);
        }
        v.push_back(temp);
    }

    vector<ll>uptodate(n,1);
    for(int i = 0;i<v.size();i++){
        for(int j=0;j<v.size();j++){
            if(v[i][0] > v[j][0] && v[i][1] > v[j][1] && v[i][2] > v[j][2] && v[i][3] > v[j][3]){
                uptodate[j] = 0;
            }
        }
    }

    ll mini  = INT_MAX;
    ll ans = 0;
    for(int i=0;i<v.size();i++){
        if(uptodate[i]){
            if(v[i][3] < mini){
                mini = v[i][3];
                ans = i;
            }
        }
    }

    return ans+1;
}

int main()
{
    ios::sync_with_stdio(false);
    cout<<solve()<<endl;
    return 0;
}