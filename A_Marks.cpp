#include<bits/stdc++.h>
using namespace std;
#define yes "YES"
#define no "NO"
#define ll long long
#define mod 1000000007
void display(vector<char>v){ for(ll i=0;i<v.size();i++) cout<<v[i]<<' ';cout<<endl;}
void display2d(vector<vector<ll>> v){for(ll i=0;i<v.size();i++){for(ll j=0;j<v[i].size();j++){cout<<v[i][j]<<' ';}cout<<endl;}cout<<endl;}
ll add(vector<int>v){int sum = 0;for(int i=0;i<v.size();i++)sum = sum+v[i];return sum;}
bool isOdd(int n){if(n&1) return true;return false;}
bool isPrime(int n){if (n <= 1)return false;for (int i = 2; i <= n / 2; i++)if (n % i == 0)return false;return true;}
bool isVowel(char a){if(a=='a'||a=='e'||a == 'i'||a=='o'||a=='u'||a=='y'){return true;}return false;}

ll solve(){
    ll n, m; cin>>n>>m;
    string num;
    vector<string>matrix;
    for(int i=0;i<n;i++){
        vector<ll>v;
        cin>>num;
        matrix.push_back(num);
    }
    vector<char>highest;
    for(int i=0;i<m;i++){
        char maxi = '0';
        for(int j=0;j<n;j++){
            maxi = max(maxi, matrix[j][i]);
        }
        highest.push_back(maxi);
    }
    ll ans = 0;
    for(int i=0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(matrix[i][j] == highest[j]){
                ans++;
                break;
            }
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cout<<solve()<<endl;
    return 0;
}