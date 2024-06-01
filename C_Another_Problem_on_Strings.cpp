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

ll solve(ll k, string s){
    int left = 0, right = 0;
    int c = 0;
    ll ans = 0;

    while(right < s.length()){

        if(s[right] == '1') c++;

        if(c <= k){
            ans = ans + right - left + 1;
            right++;
        }

        else{
            while(left < s.length() && c > k){
                if(s[left] == '1') c--;
                left++;
            }
            ans = ans + right-left+1;
            right++;
        }
    }    


    return ans;
}

int main()
{
    ll k; cin>>k;
    string s; cin>>s;

    if(k == 0){
        cout<<solve(k, s)<<"\n";
    }
    else{
        cout<<solve(k, s) - solve(k-1, s)<<"\n";
    }

    return 0;
}