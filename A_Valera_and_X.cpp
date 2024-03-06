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
    ll n; cin>>n;
    vector<vector<char>>v(n, vector<char> (n, '0'));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>v[i][j];
        }
    }

    map<char, ll>diag;
    ll j = 0;
    for(int i=0;i<n;i++){
        diag[v[i][j]]++;
        if(diag.size() == 2) return no;
        j++;
    }

    j = n-1;

    for(int i=0;i<n;i++){
        diag[v[i][j]];
        if(diag.size() == 2) return no;
        j--;
    }

    map<char,ll>others;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(diag.find(v[i][j]) == diag.end()){
                others[v[i][j]]++;
                if(others.size() == 2) return no;
            }
        }
    }

    ll sum = 0;

    for(auto it : others){
        sum = sum + it.second;
    }

    if(sum != (n*n)- (2*n-1)) return no;

    return yes;


}

int main()
{
    ios::sync_with_stdio(false);
    cout<<solve()<<endl;
    return 0;
}