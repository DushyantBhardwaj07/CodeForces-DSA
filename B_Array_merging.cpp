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
    ll n; cin>>n;
    map<ll,ll>ma;
    map<ll,ll>mb;
    vector<ll>a(n,0);
    vector<ll>b(n,0);

    for(int i=0;i<n;i++){
        cin>>a[i];
        ma[a[i]] = 1;
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
        mb[b[i]] = 1;
    }

    stack<ll>s;

    for(int i=0;i<n;i++){
        if(s.empty()){
            s.push(a[i]);
        }

        else{
            if(s.top() == a[i]){
                s.push(a[i]);
            }
            else{
                ma[s.top()] = max(ma[s.top()], (ll) s.size());
                s = stack<ll>();
                s.push(a[i]);
            }
        }
    }
    ma[s.top()] = max( (ll) ma[s.top()], (ll) s.size());

    stack<ll>s1;
    for(int i=0;i<n;i++){
        if(s1.empty()){
            s1.push(b[i]);
        }
        else{
            if(s1.top() == b[i]){
                s1.push(b[i]);
            }
            else{
                mb[s1.top()] = max(mb[s1.top()], (ll) s1.size());
                s1 = stack<ll>();
                s1.push(b[i]);
            }
        }
    }
    
    mb[s1.top()] = max( (ll) mb[s1.top()], (ll) s1.size());

    ll maxi = INT_MIN;

    for(auto it : ma){
        maxi = max(maxi, it.second + mb[it.first]);
    }

    for(auto it : mb){
        maxi = max(maxi, it.second + ma[it.first]);
    }

    return maxi;
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
