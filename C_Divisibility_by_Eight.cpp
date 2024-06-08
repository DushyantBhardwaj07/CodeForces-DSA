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

void solve(){
    string s; cin>>s;
    vector<string>v;
    for(int i=0;i<=999;i++){
        if(i % 8 == 0){
            v.push_back(to_string(i));
        }
    }
    if(s.back() == '0'){
        cout<<yes<<endl;
        cout<<0<<endl;
        return;
    }

    for(int i=0;i<v.size();i++){
        ll j =0;
        ll l = v[i].length();
        string temp = v[i];
        vector<bool>vis(s.length(), false);
        for(int k=0;k<s.length();k++){
            if(s[k] == temp[j] && !vis[k]){
                vis[k] = true;
                j++;
                if(j == l){
                    cout<<yes<<endl;
                    cout<<temp<<endl;
                    return;
                }
            }
        }

    }
    cout<<no<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    solve();
    return 0;
}