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

bool check(int mid, vector<ll> &v){
    map<ll,ll>m;
    for(int i=mid;i<v.size();i=i+mid+1){
        m[v[i]]++;
    }
    if(m.size() >=3){
        return false;
    }
    if(m.size() == 1){
        return true;
    }
    bool flag = false;
    for(auto it : m){
        if(it.second == 1){
            flag = true;
        }
    }
    if(flag) return true;
    return false;
}

bool check2(int mid, vector<ll> &v){
    map<ll,ll>n;

    for(int i=0;i<v.size();i=i+mid+1){
        n[v[i]]++;
    }
    if(n.size() >=3){
        return false;
    }
    if(n.size() == 1){
        return true;
    }
    bool flag1 = false;
    for(auto it : n){
        if(it.second == 1){
            flag1 = true;
        }
    }
    if(flag1) return true;
    return false;
}

ll solve(){
    ll n,k; cin>>n>>k;
    vector<ll>v(n,0);
    for(int i=0;i<n;i++) cin>>v[i];
    map<ll,vector<ll>>m;
    for(int i=0;i<k;i++){
        m[i+1].push_back(-1);
    }
    for(int i=0;i<n;i++){
        m[v[i]].push_back(i);
    }
    for(int i=0;i<k;i++){
        m[i+1].push_back(n);
    }
    ll ans = INT_MAX;

    for(auto it : m){
        ll temp = INT_MIN;
        for(int i=1;i<it.second.size();i++){
            temp = max(temp, abs(it.second[i] - it.second[i-1])-1);
        }
        ll c = 0;
        for(int i=1;i<it.second.size();i++){
            if(abs(it.second[i] - it.second[i-1])-1 == temp){
                c++;
            }
        }
        if(c>1){
            ans = min(ans, temp);
        }
        if(c == 1){
            ll tempans = INT_MIN;
            for(int i=1;i<it.second.size();i++){
                if(abs(it.second[i] - it.second[i-1])-1 == temp){
                    continue;
                }
                else{
                    tempans = max(tempans, abs(it.second[i] - it.second[i-1])-1);
                }
            }
            tempans = max(tempans, temp/2);
            ans = min(ans, tempans);
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

