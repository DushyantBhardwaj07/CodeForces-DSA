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
    vector<double>values = {500, 1000, 1500, 2000, 2500};
    double  m1, m2, m3, m4, m5,w1, w2, w3, w4, w5, hs, hu;
    cin>>m1>>m2>>m3>>m4>>m5;
    vector<double>m = {m1,m2,m3,m4,m5};
    cin>>w1>>w2>>w3>>w4>>w5;
    vector<double>wrong = {w1,w2,w3,w4,w5};
    cin>>hs>>hu;
    double total = 0;
    for(int i=0;i<5;i++){
        double a = (0.3)*values[i];
        double b = ((1-(m[i]/250.0))*values[i]) - (50.0*wrong[i]);
        total = total + max(a, b);
    }

    total = total +(hs*100.0)- (hu*50.0);
    return total;   
}

int main()
{
    ios::sync_with_stdio(false);
    cout<<solve()<<endl;
    return 0;
}