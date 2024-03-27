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
    ll n,k,b,s; cin>>n>>k>>b>>s;
    vector<ll>v(n, 0);
    ll temp = ((b+1) * (k)) - 1;  
    if(temp > s){
        temp = s;
    }  
    v[0] = temp;
    ll rem = s - temp;
    for(int i=1;i<n;i++){
        if(rem<k){
            v[i] = rem;
            break;
        }   
        v[i] = k-1;
        rem = rem - (k-1);
    }
    ll sum = 0;
    ll beauty= 0;
    for(int i=0;i<v.size();i++){
        sum = sum + v[i];
        beauty = beauty + v[i]/k;
    }
    // cout<<beauty<<endl;
    if(sum != s || beauty != b){
        cout<<-1<<endl;
        return;
    }

    display(v);
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