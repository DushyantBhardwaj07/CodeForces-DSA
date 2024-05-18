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

string tor(ll &a){
    string a1 = "";
    while(a > 0){
        stringstream sso;
        ll rem = a%3;
        sso<<rem;
        char temp;
        sso>>temp;
        a1 = a1+temp;
        a = a/3;
    }
    reverse(a1.begin(), a1.end());
    return a1;
}

ll solve(){
    ll a,c; cin>>a>>c;
    string a1 = tor(a);
    string c1 = tor(c);
    string b1 = "";
    if(a1.length() < c1.length()){
        while(a1.length() < c1.length()){
            a1 = '0'+a1;
        }
    }
    else if(c1.length() < a1.length()){
        while(c1.length() < a1.length()){
            c1 = '0'+c1;
        }
    }
    for(int i = 0;i<a1.length();i++){
        int j = 0;
        while(j<=9){
            if(((a1[i] - '0') + j)%3 == (c1[i]-'0')){
                stringstream sso;
                sso<<j;
                char temp;
                sso>>temp;
                b1 = b1 + temp;
                break;
            }
            j++;
        }
    }

    ll ans = 0;
    ll power = 0;
    for(int i=b1.length()-1;i>=0;i--){
        ans = ans+(b1[i]-'0')*pow(3, power);
        power++;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cout<<solve()<<endl;
    return 0;
}