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

    priority_queue<pair<ll,ll>>maxh;
    priority_queue <pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>>minh;
    for(int i=0;i<v.size();i++){
        maxh.push({v[i], i});
        minh.push({v[i], i});
    }

    ll low =0, high = n-1;

    while(low<=high && !minh.empty() && !maxh.empty()){
        ll minelement = minh.top().first;
        ll minindex = minh.top().second;
        ll maxelement = maxh.top().first;
        ll maxindex = maxh.top().second;

        if(v[low] != minelement && v[low] != maxelement && v[high] != minelement && v[high] != maxelement){
            cout<<low+1<<" "<<high+1<<endl;
            return;
        }
        
        if(v[low] == minelement){
            minh.pop();
            low++;
        }
        else if(v[low] == maxelement){
            maxh.pop();
            low++;
        }
        
        if(v[high] == minelement){
            minh.pop();
            high--;
        }
        else if(v[high] == maxelement){
            maxh.pop();
            high--;
        }

    }
    cout<<"-1"<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    ll t;cin>>t;
    while(t-->0){
        solve();
    }
    return 0;
}