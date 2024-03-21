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
    if(s.length() <= 2) return yes;
    map<char,ll>m;
    map<char,ll>m1;
    set<char> temp;
    for(int i=0;i<s.length();i++){
        m[s[i]] = 0;
        m1[s[i]]++;
        temp.insert(s[i]);
  
    }
    if(temp.size() == s.length()) return yes;
    
    for(int i=0;i<=s.length()-1;i++){
            for(auto it : temp){
                if(abs(m1[s[i]] - m1[it])>=2){
                    return no;
                }
            }
        }


    for(int i=1;i<s.length();i++){
        if(s[i] == s[i-1] && temp.size() >=2) return no;
    }

    set<char>tempr;
    ll j=0;
    for(int i=0;i<s.length();i++){
        if(tempr.find(s[i]) == tempr.end()){
            tempr.insert(s[i]);
        }
        else{
            j = i;
            break;
        }
    }
    for(int i = j;i<s.length();i++){
        if(s[i] != s[i-j]){
            return no;
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