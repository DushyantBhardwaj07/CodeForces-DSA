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
    ll root = sqrt(n);
    vector<ll>v;
    for(ll i=2;i<=root;i++){
        if((n%i) == 0){    
            if(v.empty()){
                v.push_back(i);
            }        
            else if((v.size() == 1) && (n % (v[0] * i)) == 0){
                v.push_back(i);
                break;
            }
        }
    } 
    ll mul = 1;
    if(v.size() == 2) mul = v[0] * v[1];

    if((v.size() <= 1) || (v[0] ==n/mul || v[1] == n/mul )){
        cout<<no<<endl;
        return;
    }
    if((v[0] * v[1] * (n/mul)) != n){
        cout<<no<<endl;
        return;
    }

    cout<<yes<<endl;
    cout<<v[0]<<" "<<v[1]<<" "<<n/mul<<endl;
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
