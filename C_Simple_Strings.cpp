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
    string str; cin>>str;
    stack<char>s;
    for(int i=0;i<str.length()-1;i++){
        if(s.empty()){
            s.push(str[i]);
        }
        else if(s.top() == str[i] && i<str.length()-1){
            for(char j='a';j<='z';j++){
                if(s.top() != j && j != str[i+1]){
                    str[i] = j;
                    s.push(j);
                    break;
                }
            }
        }
        else{
            s.push(str[i]);
        }
    }
    if(!s.empty() && s.top() == str.back()){
        for(char j='a';j<='z';j++){
                if(j != s.top()){
                    str.back() = j;
                    break;
            }
        }
    }
    return str;

}

int main()
{
    ios::sync_with_stdio(false);
    ll t=1;
    while(t-->0){
        cout<<solve()<<"\n";
    }
    return 0;
}