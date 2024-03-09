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

bool isDigit(char a){
    if(a >= '0' && a<= '9') return true;
    return false;
}

bool isChar(char a){
    if(a >= 'a' && a<= 'z') return true;
    return false;
}

bool isBigChar(char a){
    if(a >= 'A' && a<= 'Z') return true;
    return false;
}


// password should consist only of lowercase Latin letters and digits;
// there should be no digit that comes after a letter (so, after each letter, there is either another letter or the string ends);
// all digits should be sorted in the non-decreasing order;
// all letters should be sorted in the non-decreasing order.

string solve(){
    ll n; cin>>n;
    string s; cin>>s;

    if(isBigChar(s[0])) return no;
    char lastDig = s[0];
    char lastChar = s[0];
    for(int i=1;i<s.length();i++){
        if(isBigChar(s[i])) return no;
        
        if(isDigit(s[i]) && isChar(s[i-1])) return no;

        if(isDigit(s[i])){
            if(s[i]<lastDig){
                return no;
            }
            lastDig = s[i];
        }

        if(isChar(s[i])){
            if(s[i] < lastChar){
                return no;
            }
            lastChar = s[i];
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
