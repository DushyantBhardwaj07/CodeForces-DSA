#include<bits/stdc++.h>
using namespace std;
#define yes "YES"
#define no "NO"
#define maybe "MAYBE"
#define ll long long
#define mod 1000000007
void display(vector<ll>v){ for(ll i=0;i<v.size();i++) cout<<v[i]<<' ';cout<<endl;}
void display2d(vector<vector<ll>> v){for(ll i=0;i<v.size();i++){for(ll j=0;j<v[i].size();j++){cout<<v[i][j]<<' ';}cout<<endl;}cout<<endl;}
ll add(vector<int>v){int sum = 0;for(int i=0;i<v.size();i++)sum = sum+v[i];return sum;}
bool isOdd(int n){if(n&1) return true;return false;}
bool isPrime(int n){if (n <= 1)return false;for (int i = 2; i <= n / 2; i++)if (n % i == 0)return false;return true;}
bool isVowel(char a){if(a=='a'||a=='e'||a == 'i'||a=='o'||a=='u'||a=='y'){return true;}return false;}

string solve(){
    ll n,f,k; cin>>n>>f>>k;
    vector<ll>v(n,0);
    vector<pair<ll,ll>>p;
    for(int i=0;i<n;i++){
        cin>>v[i];
        p.push_back({v[i],i});
    }
    ll element = v[f-1];
    sort(p.begin(), p.end(), greater<pair<ll,ll>>());
    // for(auto it : p){
    //     cout<<it.first<<" "<<it.second<<endl;
    // }
    bool flag = 0;
    for(int i=0;i<k;i++){
        if(p[i].first == element){
            flag =1;
        }
    }

    for(int i=k;i<n;i++){
        if(p[i].first == element){
            if(flag) return maybe;
            else return no;
        }
    }
    return yes;

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