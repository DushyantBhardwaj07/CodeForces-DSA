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


void helper(string &s, vector<ll> &v, ll &m, ll sumOdd, ll sumEven, vector<ll> & ans){

    if(v.size() == m){
        ans = v;
        return;
    }

    for(int i=0;i<s.length();i++){
        if((s[i] == '1' && v.empty())  || (s[i] == '1' && (i+1) != v.back())){
            if(v.size() & 1){
                if((sumEven + i+1 > sumOdd) && (v.size() < m)){
                    v.push_back(i+1);
                    helper(s, v, m, sumOdd, sumEven + i +1, ans);
                }
            }
            else{
                if((sumOdd + i+1 > sumEven) && (v.size() < m)){
                    v.push_back(i+1);
                    helper(s, v, m, sumOdd + i + 1, sumEven, ans);
                }                                
            }
        }        
    }

    if(v.size() < m) v.pop_back();
}

void solve(){
    string s; cin>>s;
    ll m; cin>>m;
    vector<ll>v;
    vector<ll>ans;

    helper(s, v, m,0,0,ans);
    
    if(ans.size() == m){
        cout<<yes<<endl;    
        display(ans);
    }
    else{
        cout<<no<<endl;
    }

}

int main()
{
    ios::sync_with_stdio(false);
    solve();
    return 0;
}