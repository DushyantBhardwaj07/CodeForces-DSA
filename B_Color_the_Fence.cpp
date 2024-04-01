#include<bits/stdc++.h>
using namespace std;
#define yes "YES"
#define no "NO"
#define ll long long
#define mod 1000000007
void display(vector<string>v){ for(ll i=0;i<v.size();i++) cout<<v[i]<<' ';cout<<endl;}
void display2d(vector<vector<string>> v){for(ll i=0;i<v.size();i++){for(ll j=0;j<v[i].size();j++){cout<<v[i][j]<<' ';}cout<<endl;}cout<<endl;}
ll add(vector<int>v){int sum = 0;for(int i=0;i<v.size();i++)sum = sum+v[i];return sum;}
bool isOdd(int n){if(n&1) return true;return false;}
bool isPrime(int n){if (n <= 1)return false;for (int i = 2; i <= n / 2; i++)if (n % i == 0)return false;return true;}
bool isVowel(char a){if(a=='a'||a=='e'||a == 'i'||a=='o'||a=='u'||a=='y'){return true;}return false;}

bool compare(pair<ll,ll>a, pair<ll,ll> b){
    if(a.first <= b.first && a.second > b.second){
        return true;
    }
    return false;
    
}

string solve(){
    ll n; cin>>n;

    vector<pair<ll,ll>>pairs;
    vector<ll>v(9,0);
    ll a; 
    for(int i=0;i<9;i++){
        cin>>a;
        pairs.push_back({a, i+1});
        v[i] = a;
    }

    sort(pairs.begin(), pairs.end(), compare);


    ll len = 0;
    ll rem = 0;
    len =  n / pairs[0].first;
    rem = n % pairs[0].first;
    ll digit = pairs[0].second;
    string ans = "";
    stringstream sso;

    for(int i=0;i<len;i++){
        sso<<digit;
    }

    sso>> ans;

    ll cost = 0;

    for(int i=0;i<ans.length();i++){
        ll ind = ans[i] - '1';
        cost = rem + v[ind];
        for(int j=8;j>=0;j--){
            if(cost >= v[j]){
                stringstream ss1;
                ss1<<j+1;
                char add;
                ss1>>add;
                ans[i] = add;
                rem = cost - v[j];
                break;
            }
        }
    }

    if(ans.length() == 0) return "-1";

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cout<<solve()<<"\n";
    return 0;
}
