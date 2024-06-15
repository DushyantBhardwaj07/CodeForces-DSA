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
    string s,t; cin>>s>>t;
    ll br = -1;
    stringstream ss;
    stringstream tt;
    for(int i=0;i<s.length();i++){
        ss<<s[i];
        tt<<t[i];
        if(s[i] != t[i]){
            br = i;
            break;
        }
    }

    if(br == -1){
        cout<<s<<endl;
        cout<<t<<endl;
        return;
    }

    for(int i=br+1;i<s.length();i++){
        if(s[br] > t[br]){
            tt<<max(s[i], t[i]);
            ss<<min(s[i], t[i]);
        }
        else{
            tt<<min(s[i], t[i]);
            ss<<max(s[i], t[i]);
        }
    }

    string ans1 = "";
    string ans2 = "";
    ss >> ans1;
    tt >> ans2;

    cout<<ans1<<endl;
    cout<<ans2<<endl;
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