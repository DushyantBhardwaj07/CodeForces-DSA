#include<bits/stdc++.h>
using namespace std;
#define yes "YES"
#define no "NO"
#define ll long long
#define mod 1000000007
void display(vector<string>v){ for(ll i=0;i<v.size();i++) cout<<v[i]<<' ';cout<<endl;}
void display2d(vector<vector<ll>> v){for(ll i=0;i<v.size();i++){for(ll j=0;j<v[i].size();j++){cout<<v[i][j]<<' ';}cout<<endl;}cout<<endl;}
ll add(vector<int>v){int sum = 0;for(int i=0;i<v.size();i++)sum = sum+v[i];return sum;}
bool isOdd(int n){if(n&1) return true;return false;}
bool isPrime(int n){if (n <= 1)return false;for (int i = 2; i <= n / 2; i++)if (n % i == 0)return false;return true;}
bool isVowel(char a){if(a=='a'||a=='e'||a == 'i'||a=='o'||a=='u'||a=='y'){return true;}return false;}

ll solve(){
    ll n,k; cin>>n>>k;
    vector<string>v;
    string s;
    ll ans = 0;
    for(int i=0;i<n;i++){
        cin>>s;
        v.push_back(s);
    }
    for(int i=0;i<n;i++){
        bool flag = 1;
        ll num = 0;
        vector<bool>visited(v[i].length()+1, false);
        for(int j=0;j<v[i].size();j++){
            visited[v[i][j] - '0'] = true;
        }

        for(int i=0;i<=k;i++){
            if(visited[i] == false) flag = 0;
        }
        if(flag) ans++;
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cout<<solve()<<endl;
    return 0;
}