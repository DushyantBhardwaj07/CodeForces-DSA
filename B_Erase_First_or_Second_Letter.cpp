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

set<string>ans;

void helper(ll n, string s){
    stack<string>st;
    ans.insert(s);
    st.push(s);
    while(!st.empty()){
        string op1 = st.top().substr(1, st.top().size());
        string op2 = st.top().substr(0,1);
        if(st.top().size() >= 2) op2 = op2 + st.top().substr(2, st.top().size()-1);
        st.pop();
        if((op1.length() > 0) && ans.find(op1) == ans.end()){
            st.push(op1);
            ans.insert(op1);
        }
        if( (op2.length() > 0) && ans.find(op2) == ans.end()){
            st.push(op2);
            ans.insert(op2);
        }
    }
}

ll solve(){
    ans.clear();
    ll n; cin>>n;
    string s; cin>>s;
    helper(n, s);
    return ans.size();
}

int main()
{
    ios::sync_with_stdio(false);
    ll t;cin>>t;
    while(t-->0){
        cout<<solve()<<endl;
    }
    return 0;
}