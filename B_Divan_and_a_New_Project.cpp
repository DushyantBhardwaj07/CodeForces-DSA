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

void solve(){
    ll n; cin>>n;
    vector<ll>v(n,0);
    for(int i=0;i<n;i++) cin>>v[i];
    int x = 0;
    vector<ll>temp(n,0);
    ll cnt = 1;
    for(int i=0;i<n;i=i+2){
        temp[i] = cnt;
        if(i+1<n){
            temp[i+1] = cnt;
        }
        cnt++;
    }
    priority_queue<pair<ll,ll>>pq;
    for(int i=0;i<n;i++){
        pq.push({v[i], i});
    }
    
    sort(temp.begin(), temp.end());
    vector<ll>ans(n,0);

    for(int i=0;i<n;i++){
        ans[pq.top().second] = temp[i];
        pq.pop();
    }

    ll fans = 0;
    for(int i=0;i<n;i++){
        fans = fans + 2 * (abs(ans[i])) * v[i];
    }
    cout<<fans<<endl;
    cout<<0<<" ";
    map<ll,ll>m;
    for(int i=0;i<ans.size();i++){
        if(m.find(ans[i]) != m.end()){
            ans[i] = ans[i] * -1;
        }
        m[ans[i]]++;
    }
    display(ans);
}


int main()
{
    ios::sync_with_stdio(false);
    ll t;cin>>t;
    while(t-->0){
        solve();
    }
    return 0;
}