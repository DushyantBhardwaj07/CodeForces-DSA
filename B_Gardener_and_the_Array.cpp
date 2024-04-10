#include<bits/stdc++.h>
using namespace std;
#define yes "Yes"
#define no "No"
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
    vector<vector<ll>>v;
    for(int i=0;i<n;i++){
        ll k; cin>>k;
        vector<ll>temp(k,0);
        for(int j=0;j<k;j++){
            cin>>temp[j];
        }
        v.push_back(temp);
    }

    for(auto it : v){
        for(int i=0;i<it.size();i++){
            m[it[i]]++;
        }
    }

    for(int i=0;i<v.size();i++){
        bool flag = 1;
        for(int j=0;j<v[i].size();j++){
            if(m[v[i][j]] == 1){
                flag = 0;
                break;
            }
        }
        if(flag){
            return yes;
        }
    }
    return no;
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