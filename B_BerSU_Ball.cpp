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
    ll n,mm; cin>>n;
    vector<ll>v1(n,0);
    for(int i=0;i<n;i++) cin>>v1[i];
    cin>>mm;
    map<ll,ll>m;
    vector<ll>v2(mm,0);
    ll a;
    for(int i=0;i<mm;i++){
        cin>>a;
        m[a]++;
        v2[i] = a;
    }
    vector<ll>v;
    ll ans = 0;
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    for(int i=0;i<n;i++){
        if(m.find(v1[i]) != m.end()){
            m[v1[i]]--;
            ans++;
            if(m[v1[i]] == 0){
                m.erase(v1[i]);
            }
        }
        else{
            v.push_back(v1[i]);
        }
    }
    sort(v.begin(), v.end());
    for(int i=0;i<v.size();i++){

        if(m.find(v[i]+1) != m.end()){
            m[v[i]+1]--;
            ans++;
            if(m[v[i]+1] == 0){
                m.erase(v[i]+1);
            }
        }
        else if(m.find(v[i]-1) != m.end()){
            m[v[i]-1]--;
            ans++;
            if(m[v[i]-1] == 0){
                m.erase(v[i]-1);
            }
        }

    }
    
    ans = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<mm;j++){
            if(abs(v1[i] - v2[j]) <= 1){
                v2[j] = 10000;
                ans++;
                break;
            }
        }
    }
    return ans;

}

int main()
{
    ios::sync_with_stdio(false);
    ll t = 1;
    while(t-->0){
        cout<<solve()<<"\n";
    }
    return 0;
}