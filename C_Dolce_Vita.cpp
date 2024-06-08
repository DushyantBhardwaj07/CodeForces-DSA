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
    ll n, x; cin>>n>>x;
    vector<ll>v(n,0);
    for(int i=0;i<n;i++) cin>>v[i];
    sort(v.begin(), v.end());
    if(v[0] > x) return 0;
    // ll ans = x/v[0];

    ll ans = x- v[0] + 1;
    ll sum = v[0];
    // cout<<ans<<endl;
    for(int i=1;i<n;i++){
        ll low = 0, high =  x- v[0] + 1;
        ll maxi = 1;
        while(low<=high){
            ll mid = low + (high-low)/2;
            ll day = mid - v[i-1] + 1;
            ll b  = sum + (i) * (day-1);
            ll a = x - b;
            ll temp = v[i] + (day-1);
            if(a < temp){
                high = mid-1;
            }
            else{
                maxi = max(maxi, day);
                low = mid+1;
            }
        }
        // ll b  = sum + (i) * (day-1);
        while(maxi >0 && (x - (sum + (i) * (maxi-1)) < v[i] + (maxi-1))){
            maxi--;
        }        
        ans = ans +maxi;
        // cout<< ans << " "  << maxi<<" "<<endl;
        sum = sum + v[i];
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