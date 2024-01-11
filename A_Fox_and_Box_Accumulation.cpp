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


bool check(vector<ll> & v, ll mid){
    vector<vector<ll>>ans;
    vector<ll>sum;
    for(int i=0;i<mid;i++){
        ans.push_back({v[i]});
        sum.push_back(v[i]);
    }

    ll pushed = 0;
    for(int i=mid;i<v.size();i++){
        for(int j = (pushed) % ans.size();j<ans.size(); j++){
            if(ans[j].back() == 0 && v[i] == 0){
                continue;
            }
            if(ans[j].back() >= v[i] && sum[j] > 0){
                sum[j]--;
                ans[j].push_back(v[i]);
                pushed = j+1;
                break;
            }
        }
    }
    ll total = 0;
    for(int i=0;i<ans.size();i++){
        total += ans[i].size();
    }
    if(total != v.size()) return false;

    for(int i=0;i<ans.size();i++){
        for(int j =0;j<ans[i].size();j++){
            if((ans[i][j] < ans[i].size()-1-j) ){
                return false;
            }
        }
    }
    return true;

}

ll solve(){
    ll n; cin>>n;
    vector<ll>v(n,0);
    for(int i=0;i<n;i++) cin>>v[i];
    sort(v.begin(), v.end(), greater<ll>());

    ll low = 1, high = n;
    while(low<=high){
        ll mid = low + (high-low)/ 2;
        if(check(v, mid)){
            high = mid-1;
        }
        else{
            low = mid + 1;
        }
    }

    return low;

}

int main()
{
    ios::sync_with_stdio(false);
    cout<<solve()<<"\n";
    return 0;
}