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
    string s; cin>>s;
    ll lever = 0;
    for(int i=0;i<s.length();i++){
        if(s[i] == '^'){
            lever = i;
            break;
        }
    }
    ll i = lever-1;
    ll left = 0, right = 0;
    while(i >= 0){
        if(s[i] != '='){
            left = left + (lever - i)*(s[i] - '0');
        }
            i--;
    }

    i = lever + 1;
    while(i<s.length()){
        if(s[i] != '='){
            right = right + (i - lever)*(s[i] - '0');
        }
        i++;
    }
    if(left> right){
        return "left";
    }
    else if(right>left){
        return "right";
    }
    return "balance";
}

int main()
{
    ios::sync_with_stdio(false);
    cout<<solve()<<endl;
    return 0;
}