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

string solve(){
    ll n; cin>>n;
    map<ll,ll>m;
    ll a;
    for(int i=0;i<n;i++){
        cin>>a;
        m[a]++;
    }    
    map<ll,ll>m1;
    for(int i=0;i<n-1;i++){
        cin>>a;
        m1[a]++;
    }

    ll ans1 =0;
    for(auto it :m){
        if(m1.find(it.first)  == m1.end()){
            ans1 = it.first;
            break;
        }
        else{
            if(it.second != m1[it.first]){
                ans1 = it.first;
                break;
            }
        }
    }
    map<ll,ll>m2;

    for(int i=0;i<n-2;i++){
        cin>>a;
        m2[a]++;
    }

    ll ans2= 0;
    for(auto it :m1){
        if(m2.find(it.first)  == m2.end()){
            ans2 = it.first;
            break;
        }
        else{
            if(it.second != m2[it.first]){
                ans2 = it.first;
                break;
            }
        }
    }

    cout<<ans1<<endl;
    cout<<ans2<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    solve();
    return 0;
}