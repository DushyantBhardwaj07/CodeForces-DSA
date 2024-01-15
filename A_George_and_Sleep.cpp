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
    string s,t; cin>>s>>t;
    string hs = s.substr(0, 2);
    string ms = s.substr(3, 2);

    string ht = t.substr(0, 2);
    string mt = t.substr(3, 2);


    ll hours = stoi(hs)-stoi(ht);
    ll mins = stoi(ms)-stoi(mt);
    if(hours<0){
        hours = hours+24;
    }

    if(mins<0){
        mins = mins + 60;
        hours--;
    }
     
    if(hours<0){
        hours = hours+24;
    }

    string sh = to_string(hours);
    if(sh.length() == 1) sh = '0'+sh;
    string sm = to_string(mins);
    if(sm.length() == 1) sm = '0'+sm;
    
    string ans = sh+':'+sm;
    return ans;

}

int main()
{
    ios::sync_with_stdio(false);
    cout<<solve()<<endl;
    return 0;
}