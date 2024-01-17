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

ll solve(){
    ll n; cin>>n;
    if(n>0) return n;
    ll flag = false;
    if(n<0){
        n=n*-1;
        flag = true;
    }
    string s = to_string(n);
    ll temp1, temp2;
    string s1 = s;
    s.erase(s.begin() + s.length()-2);
    string s2 = s;
    s1.erase(s1.begin() + s1.length()-1);
    string s3 = s1;
    temp1 = stoi(s2);
    temp2 = stoi(s3);
    return max({-1*temp1, -1*temp2, -1*n});
}

int main()
{
    ios::sync_with_stdio(false);
    cout<<solve()<<endl;
    return 0;
}