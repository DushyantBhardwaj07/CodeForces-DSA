#include<bits/stdc++.h>
using namespace std;
#define yes "YES"
#define no "NO"
#define ll long long
#define mod 1000000007
void display(vector<string>v){ for(ll i=0;i<v.size();i++) cout<<v[i]<<' ';cout<<endl;}
void display2d(vector<vector<ll>> v){for(ll i=0;i<v.size();i++){for(ll j=0;j<v[i].size();j++){cout<<v[i][j]<<' ';}cout<<endl;}cout<<endl;}
ll add(vector<int>v){int sum = 0;for(int i=0;i<v.size();i++)sum = sum+v[i];return sum;}
bool isOdd(int n){if(n&1) return true;return false;}
bool isPrime(int n){if (n <= 1)return false;for (int i = 2; i <= n / 2; i++)if (n % i == 0)return false;return true;}
bool isVowel(char a){if(a=='a'||a=='e'||a == 'i'||a=='o'||a=='u'||a=='y'){return true;}return false;}

bool compare(string a, string b){
    stringstream ss0;
    stringstream ss1;
    ll num1, num2;

    ss0<<a; ss1<<b;
    ss0>>num1; ss1>>num2;
    if(a.length() < b.length()) return true;

    else if(a.length() == b.length()){
        if(num1<num2){
            return true;
        }
        else{
            return false;
        }
    }

    return false;
}

void helper(set<string> &st, ll n, string ans, ll noOf4, ll noOf7){
    if(n<0) return;
    if(n == 0){
        if(noOf4 == noOf7) st.insert(ans);
        return;
    }
    ans = ans+'4';
    helper(st, n-1, ans, noOf4+1, noOf7);
    ans.back() = '7';
    helper(st, n-1, ans, noOf4, noOf7+1);

}
string solve(){
    string s; cin>>s;
    stringstream sso; sso<<s;
    ll num;
    sso>>num;
    set<string>st;
    string ans = "";
    if(s.length() & 1){
        helper(st, s.length() + 1, ans, 0, 0);
    }
    else{
        helper(st, s.length(), ans, 0, 0);
        helper(st, s.length() + 2, ans, 0, 0);
    }
    vector<string>temp;
    for(auto it : st){
        temp.push_back(it);
    }
    sort(temp.begin(), temp.end(), compare);
    for(int i=0;i<temp.size();i++){
        stringstream sso;
        sso<<temp[i];
        ll var; sso>>var;
        if(var>=num) return temp[i];
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cout<<solve()<<endl;
    return 0;
}