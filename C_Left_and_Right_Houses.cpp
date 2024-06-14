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
    double n; cin>>n;
    string s; cin>>s;
    ll leftZeros = 0;
    ll zeros = 0;
    ll ones = 0;
    for(auto it : s){
        if(it == '1'){
            ones++;
        }
        else{
            zeros++;
        }
    }

    ll mini = INT_MAX;
    if(ones >= ceil(n/2)){
        mini = abs(n/2); 
    }
    ll ans = 0;

    for(int i=0;i<s.length();i++){
        if(s[i] == '1'){
            ones--;
        }
        else{
            leftZeros++;
            zeros--;
        }
        double x = i+1;
        double xn = n-x;
        if((ceil(x/2) <= leftZeros) && (ceil(xn/2) <= ones)){
            if(abs((n/2) - x) < mini){
                mini = abs((n/2) - x);
                ans = x;
            }
        }
    }
    return ans;

}

int main()
{
    ios::sync_with_stdio(false);
    ll t;cin>>t;
    while(t-->0){
        cout<<solve()<<"\n";
    }
    return 0;
}