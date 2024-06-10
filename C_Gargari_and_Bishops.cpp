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



ll n, rDiag[10005], lDiag[10005], coin[3005][3005], f=0;
ll odd_max= -1, even_max= -1, o1, o2, e1, e2;


void solve(){
    cin>>n;

    for(int i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            cin>> coin[i][j];

            rDiag[n+i-j]+= coin[i][j];
            lDiag[i+j]+= coin[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            ll poll= rDiag[n+i-j]+ lDiag[i+j]- coin[i][j];

            if((i+j)&1){
                if(poll>odd_max){
                   odd_max= poll;
                   o1= i;
                   o2= j;
                }
            }
            else{
                if(poll>even_max){
                   even_max= poll;
                   e1= i;
                   e2= j;
                }
            }

        }
    }

    cout<<(even_max+odd_max)<<endl;
    cout<<o1+1<<" "<<o2+1<<" "<<e1+1<<" "<<e2+1<<" "<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    solve();
    return 0;
}