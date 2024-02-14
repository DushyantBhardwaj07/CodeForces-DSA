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
    ll n ,m; cin>>n>>m;
    vector<ll>v(n,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    stack<ll>s;
    for(int i=n-1;i>=0;i--){
        s.push(v[i]);
    }   

    ll ans = 0;
    ll rem = 0;
    while(!s.empty()){
        
        if(!s.empty()){
            if(s.top() > rem) rem = 0;
            
            if((m >= s.top()) && rem == 0){
                ans++;
                rem = m - s.top();
                s.top() = 0;
            }

            else if(rem > 0 && s.top() <= rem){
                rem = rem - s.top();
                s.top() = 0;
            }
        }

        if(s.top() == 0) s.pop();
    }

    return ans;    
}

int main()
{
    ios::sync_with_stdio(false);
    cout<<solve()<<endl;
    return 0;
}