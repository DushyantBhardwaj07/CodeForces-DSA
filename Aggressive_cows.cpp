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

bool check(ll mid, vector<ll> &v, ll c){
    ll ans = 1;
    ll last = v[0];
    for(int i=1;i<c;i++){
        if(binary_search(v.begin() , v.end(), last + mid)){
            last = last + mid;
            ans++;
        }        
        else{
            ll ind = upper_bound(v.begin(), v.end(), last+mid) - v.begin();
            if(ind == v.size()){
                if(ans < c) return false;
                else return true;
            }
            else{
                last = v[ind];
                ans++;
            }
        }

        if(ans >= c) return true;
    }
    return false;
}

ll solve(){
    ll n, c; cin>>n>>c;
    vector<ll>v(n, 0);
    for(int i=0;i<n;i++) cin>>v[i];
    sort(v.begin(), v.end());

    ll low = 1, high = 1e10;

    while(low <= high){
        ll mid = low + (high-low)/2;

        if(check(mid, v, c)){
            low = mid + 1;            
        }
        else{
            high = mid-1;
        }
    }

    return high;
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
