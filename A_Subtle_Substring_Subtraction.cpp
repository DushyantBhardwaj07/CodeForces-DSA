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
    string s; cin>>s;
    int n = s.length();
    if(s.length() == 1){
        cout<<"Bob "<<s[0]-'a' + 1<<endl;
        return;
    }
    ll first = 0;
    ll last = 0;
    for(int i=0;i<s.length()-1;i++){
        first = first + s[i] - 'a'+1;
    }

    for(int i=n-1;i>0;i--){
        last = last + s[i] - 'a'+1;
    }

    if(n & 1){
        if(first >= last){
            cout<<"Alice "<<first - (s.back() - 'a' + 1)<<endl;
        }
        else{
            cout<<"Alice "<<last - (s[0] - 'a' + 1)<<endl;
        }
    }
    else{
        ll summ = 0;
        for(int i=0;i<s.length();i++){
            summ = summ + s[i]-'a'+1;
        }
        cout<<"Alice "<<summ<<endl;
    }
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