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

class Compare{
    public:
    bool operator()(pair<ll,ll> p1, pair<ll,ll> p2){
        if(p2.first > p1.first){
            return true;
        }
        if(p2.first == p1.first){
            if(p2.second < p1.second){
                return true;
            }
            else{
                return false;
            }
        }
        return false;
    }
};

void solve(){
    ll n,k; cin>>n>>k;
    vector<ll>v(n,0);
    vector<ll>mul(n, 0);
    for(int i=0;i<n;i++){
        cin>>v[i];
        mul[i] = ceil((double)v[i]/(double)k);
    }
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, Compare>pq;
    for(int i=0;i<v.size();i++){
        if(mul[i] != 1){
            pq.push({v[i] - ((mul[i]-1) * k), i});
        }
        else{
            pq.push({v[i] , i});
        }
    }

    vector<ll>ans;
    while(!pq.empty()){
        ll ind = pq.top().second;
        ans.push_back(ind+1);
        pq.pop();
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