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
    string s; cin >> s;
    vector<ll>front(s.length(), 0);
    vector<ll>back(s.length(), 0);

    for(int i=1;i<s.length();i++){
        if(s[i] == 'o' || s[i-1] != 'v'){
            front[i] = front[i-1];
        }
        else if(s[i-1] == 'v'){
            front[i] = front[i-1]+1;
        }
    }

    for(int i=s.length()-2;i>=0;i--){
        if(s[i] == 'o' || s[i+1] != 'v'){
            back[i] = back[i+1];
        }
        else if(s[i+1] == 'v'){
            back[i] = back[i+1]+1;
        }
    }

    // display(front);
    // display(back);
    ll ans = 0;
    for(int i=0;i<s.length();i++){
        if(s[i] == 'o'){
            ans = ans + front[i] * back[i];
        }
    }

    return ans;
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