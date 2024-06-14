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
    string s; cin>>s;
    ll firstCapital = 0;
    ll lastCapital = 0;
    bool flag = 1;
    ll tempsmall = 0;
    ll tempbig = 0;
    for(int i=0;i<s.length();i++){
        if('a'<=s[i] && 'z' >= s[i]){
            tempsmall++;
        }
        else{
            tempbig++;
        }
    }
    for(int i=0;i<s.length();i++){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            if(flag){
                firstCapital = i;
                flag = 0;
            }
        }
        else{
            lastCapital--;
            break;
        }
    }
    ll small = 0;
    ll big = 0;
    for(int i = lastCapital+1;i<s.length();i++){
        if('a'<=s[i] && 'z' >= s[i]){
            small++;
        }
        else{
            big++;
        }
    }

    return min({firstCapital + big , tempsmall, tempbig});

}

int main()
{
    ios::sync_with_stdio(false);
    cout<<solve()<<endl;
    return 0;
}