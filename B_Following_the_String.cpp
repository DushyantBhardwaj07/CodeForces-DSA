#include<bits/stdc++.h>
using namespace std;
#define yes "YES"
#define no "NO"
#define ll long long
#define mod 1000000007
void display(vector<char>v){ for(ll i=0;i<v.size();i++) cout<<v[i]<<' ';cout<<endl;}
void display2d(vector<vector<ll>> v){for(ll i=0;i<v.size();i++){for(ll j=0;j<v[i].size();j++){cout<<v[i][j]<<' ';}cout<<endl;}cout<<endl;}
ll add(vector<int>v){int sum = 0;for(int i=0;i<v.size();i++)sum = sum+v[i];return sum;}
bool isOdd(int n){if(n&1) return true;return false;}
bool isPrime(int n){if (n <= 1)return false;for (int i = 2; i <= n / 2; i++)if (n % i == 0)return false;return true;}
bool isVowel(char a){if(a=='a'||a=='e'||a == 'i'||a=='o'||a=='u'||a=='y'){return true;}return false;}

string solve(){
    ll n; cin>>n;
    map<char, ll>m;
    vector<ll>v(n,0);
    vector<char>ans(n,'0');
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    char var = 'a';
    for(int i=0;i<n;i++){
        if(v[i] == 0){
            m[var] = 0;
            ans[i] = var;
            var++; 
        }
        else if(v[i]!=0){
            for(auto &it: m){
                if(it.second + 1 == v[i]){
                    it.second++;
                    ans[i] = it.first;
                    break;
                }
            }
        }
    }

    string res="";
    stringstream sso;
    for(int i=0;i<ans.size();i++){
        sso<<ans[i];
    }
    sso>>res;
    return res;

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