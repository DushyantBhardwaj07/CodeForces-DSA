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


bool comp(pair<ll,ll>a, pair<ll,ll>b){
    if(a.second < b.second) return  true;
    if(a.second == b.second){
        if(a.first<b.first) return true;
    }
    return false;
}
ll solve(){
    double n, r, avg; cin>>n>>r>>avg;
    vector<pair<ll,ll>>v;
    ll a, b;
    ll sum = 0;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        v.push_back({a,b});
        sum = sum+a;
    }    

    double average = sum/n;

    if(average >= avg) return 0;
    sort(v.begin(), v.end(), comp);

    ll diff = (n*avg) - sum;
    ll ans = 0;
    for(int i=0; i<v.size() ;i++){
        ll temp = r - v[i].first;
        if(temp > 0){
            if(temp >= diff){
                ans = ans + diff * v[i].second;
                return ans;
            }
            else{
                ans = ans + temp * v[i].second;
                diff = diff - temp;
                if(diff<=0) return ans;
            }
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cout<<solve()<<endl;
    return 0;
}
