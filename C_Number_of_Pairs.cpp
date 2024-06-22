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
    ll n,l,r; cin>>n>>l>>r;
    vector<ll>v(n,0);
    for(int i=0;i<n;i++) cin>>v[i];
    ll ans = 0;
    sort(v.begin(), v.end());
    // display(v);
    for(int i=0;i<n-1;i++){
        ll lo = i;
        // cout<<i<<' '<<lo<<endl;
        ll hi = 0;
        if(v[i] < l){
            lo = lower_bound(v.begin()+i + 1, v.end(), l-v[i]) - (v.begin());
        }

        hi = upper_bound(v.begin()+i+ 1, v.end(), r-v[i]) - (v.begin());

        if(lo == i){
            lo++;
        }

        if(hi == n){
            if(v[hi-1] + v[i] >=l && v[hi-1] + v[i]<=r){
                hi--;
            }
        }
        
        else {
            hi--;
        }

        // if(low ==)
        // cout<< i<< ' '<< lo<<' '<<hi<<endl;
        if(hi>=0 && lo >=0 && lo<n && lo<=hi && hi<n && v[hi] + v[i] >=l && v[hi] + v[i]<=r){
            ans = ans + hi-lo+1;
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