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

bool compare(int i, int j, int k, int l){
    vector<ll>ans = {i,j,k,l};
    sort(ans.begin(), ans.end());
    for(int i=1;i<4;i++){
        if(ans[i] == ans[i-1]) return false;
    }
    return true;
}

void solve(){
    ll r1, r2, c1, c2, d1, d2;
    cin>>r1 >> r2;
    cin>>c1 >> c2;
    cin>>d1 >> d2;
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            for(int k=1;k<=9;k++){
                for(int l=1;l<=9;l++){
                    if(compare(i,j,k,l)){
                        if(i+j == r1 && k+l == r2 && i+k == c1 && j+l == c2 && j+k ==d2 && i+l == d1){
                        cout<<i<<" "<<j<<endl;
                        cout<<k<<" "<<l<<endl;
                        return;
                        }
                    }
                }
            }
        }
    }
    cout<<-1<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    solve();
    return 0;
}