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
    string s;
    for(int i=0;i<8;i++){
        ll noOfW = 0, noOfB = 0;
        cin>>s;
        for(int i=0;i<s.length();i++){
            if(i>0){
                if((s[i] == 'W' && s[i-1] == 'W') || (s[i] == 'B' && s[i-1] == 'B')) return no;
            }
            if(s[i] == 'W') noOfW++;
            if(s[i] == 'B') noOfB++;
        }
        if(noOfW !=4 || noOfB != 4) return no;
    }
    return yes;
}

int main()
{
    ios::sync_with_stdio(false);
    cout<<solve()<<endl;
    return 0;
}