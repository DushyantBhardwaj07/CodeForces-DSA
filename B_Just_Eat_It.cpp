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

string solve(){
    ll n; cin>>n;
    vector<ll>v(n,0);
    bool flag = 0;
    ll sum = 0;
    for(int i=0;i<n;i++){
        cin>>v[i];
        sum = sum + v[i];
    }

    ll maxi = INT_MIN;
    ll summ = 0;
    for(int i=0;i<n;i++){
        summ = summ + v[i];
        maxi = max(maxi, summ);
        if(summ < 0){
            summ = 0;
        }
    }
    // cout<<maxi<<" "<<sum<<endl;
    if(maxi > sum) return no;
    map<ll,ll>m;
    vector<ll>presum;
    presum.push_back(0);
    presum.push_back(v[0]);
    m[0] = 0;
    for(int i=1;i<v.size();i++) presum.push_back(presum.back() +v[i]);
    for(int i=1;i<=presum.size()-1;i++){
        if(m.find(presum[i] - sum) != m.end()){
            if((i == presum.size()-1) && (m[presum[i] - sum] == 0)){
                return yes;
            }
            else{
                return no;
            }
        }
        m[presum[i]] = i;
    }
    return yes;

    
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