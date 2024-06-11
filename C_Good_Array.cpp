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
    ll n; cin>>n;
    vector<ll>v(n,0);
    ll sum = 0;
    for(int i=0;i<n;i++){
        cin>>v[i];
        sum = sum + v[i];
    }
    map<ll,vector<ll>>m; //element - indices at which it is present

    for(int i=0;i<v.size();i++){
        m[v[i]].push_back(i+1);
    }

    sort(v.begin(), v.end());

    vector<ll>presum;

    presum.push_back(v[0]);

    for(int i=1;i<v.size();i++) presum.push_back(presum.back() + v[i]);

    ll diff = presum[presum.size()-2] - v.back();

    vector<ll>ans;

    if(m.find(diff) != m.end()){
        for(int i=0;i<m[diff].size();i++){
            if(diff == v.back()){
                if(m[diff].size() == 1) continue;
                else{
                    ans.push_back(m[diff][i]);
                }
            }
            else{
                ans.push_back(m[diff][i]);
            }
        }
    }

    if(n>=3 && presum[presum.size()-3] == v[v.size()-2] && presum[presum.size()-3] != diff){
        for(int i=0;i<m[v.back()].size();i++){
            ans.push_back(m[v.back()][i]);
        }
    }
    cout<<ans.size()<<endl;
    display(ans);
}

int main()
{
    ios::sync_with_stdio(false);
    ll t=1;
    while(t-->0){
        solve();
    }
    return 0;
}