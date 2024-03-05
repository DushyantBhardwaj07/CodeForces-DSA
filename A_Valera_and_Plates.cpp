#include<bits/stdc++.h>
using namespace std;
#define no "NO"
#define yes "YES"
#define ll long long
#define mod 1000000007
void display(vector<ll>v){ for(ll i=0;i<v.size();i++) cout<<v[i]<<' ';cout<<endl;}
void display2d(vector<vector<ll>> v){for(ll i=0;i<v.size();i++){for(ll j=0;j<v[i].size();j++){cout<<v[i][j]<<' ';}cout<<endl;}cout<<endl;}
int add(vector<int>v){int sum = 0;for(int i=0;i<v.size();i++)sum = sum+v[i];return sum;}
bool isOdd(int n){if(n&1) return true;return false;}
bool isPrime(int n){if (n <= 1)return false;for (int i = 2; i <= n / 2; i++)if (n % i == 0)return false;return true;}
bool isVowel(char a){if(a=='a'||a=='e'||a == 'i'||a=='o'||a=='u'||a=='y'){return true;}return false;}

ll solve(){
    ll n,m,k; cin>>n>>m>>k;
    vector<ll>v(n,0);
    ll noOfones = 0;
    ll noOftwos = 0;

    for(int i=0;i<n;i++){
        cin>>v[i];
        if(v[i] == 1) noOfones++;
        if(v[i] == 2) noOftwos++;
    }
    ll ans = 0;
    for(int i = 0;i<n;i++){

        if(v[i] == 1){
            if(m>0){
                m--;
            }
            else{
                ans++;
            }
            noOfones--;
        }

        else{
            if(m == 0 && k == 0){
                ans++;
            }
            else if(k > 0){
                k--;
            }
            else if(k == 0 && m>0){
                m--;
            }
            else{
                if(noOfones > noOftwos){
                    k--;
                }
                else if(noOfones < noOftwos){
                    m--;
                }
                else{
                    ans++;
                }
            }
            noOftwos--;
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