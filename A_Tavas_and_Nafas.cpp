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
    map<ll, string>m;
    m[0] = "zero";
    m[1] = "one"; m[11] = "eleven";
    m[2] = "two"; m[12] = "twelve";
    m[3] = "three"; m[13] = "thirteen";
    m[4] = "four"; m[14] = "fourteen";
    m[5] = "five"; m[15] = "fifteen";
    m[6] = "six"; m[16] = "sixteen";
    m[7] = "seven"; m[17] = "seventeen";
    m[8] = "eight"; m[18] = "eighteen";
    m[9] = "nine"; m[19] = "nineteen";
    m[10] = "ten"; m[20] = "twenty";
    m[30] = "thirty"; m[40] = "forty";
    m[50] = "fifty"; m[60] = "sixty";
    m[70] = "seventy";
    m[80] = "eighty"; m[90] = "ninety";
    ll n; cin>>n;
    if(n<=20){
        return m[n];
    }
    else{
        ll temp = (n / 10)*10;
        if(n%10 != 0)return m[temp]+"-"+m[n%10];
        return m[temp];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cout<<solve()<<endl;
    return 0;
}