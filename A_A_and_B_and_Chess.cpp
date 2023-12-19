#include<bits/stdc++.h>
using namespace std;
#define yes "YES"
#define no "NO"
#define ll long long
#define mod 1000000007
void display(vector<ll>v){ for(ll i=0;i<v.size();i++) cout<<v[i]<<' ';cout<<endl;}
void display2d(vector<vector<char>> v){for(ll i=0;i<v.size();i++){for(ll j=0;j<v[i].size();j++){cout<<v[i][j]<<' ';}cout<<endl;}cout<<endl;}
ll add(vector<int>v){int sum = 0;for(int i=0;i<v.size();i++)sum = sum+v[i];return sum;}
bool isOdd(int n){if(n&1) return true;return false;}
bool isPrime(int n){if (n <= 1)return false;for (int i = 2; i <= n / 2; i++)if (n % i == 0)return false;return true;}
bool isVowel(char a){if(a=='a'||a=='e'||a == 'i'||a=='o'||a=='u'||a=='y'){return true;}return false;}

string solve(){
    map<char,ll>m;
    m['q'] = 9;
    m['r'] = 5;
    m['b'] = 3;
    m['n'] = 3;
    m['p'] = 1;
    m['k'] = 0;
    char temp;
    ll white = 0, black = 0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cin>>temp;
            if(temp != '.'){
                if(temp>='A' && temp<= 'Z'){
                    white = white + m[tolower(temp)];
                }
                else{
                    black = black + m[temp];
                }
            }
        }
    }

    if(white > black) return "White";
    if(black > white) return "Black";
    return "Draw";

}

int main()
{
    ios::sync_with_stdio(false);
    cout<<solve()<<endl;
    return 0;
}

