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


bool check(ll mid, vector<pair<ll,ll>> pairs){
    for(auto it : pairs){
        if(it.first >= mid){
            return false;
        }
        mid = mid + it.second;
    }
    return true;
}


ll solve(){
    ll n; cin>>n;
    vector<vector<ll>>v;
    vector<pair<ll,ll>>pairs;
    vector<ll>kk;
    ll maxx = INT_MIN;
    for(int i=0;i<n;i++){
        ll k; cin>>k;
        kk.push_back(k);
        vector<ll>temp(k,0);
        ll maxi = INT_MIN;
        for(int j=0;j<k;j++){
            cin>>temp[j];
            maxi = max(maxi,temp[j] -(j+1));
            maxx = max(maxx, temp[j]); 
        }
        pairs.push_back({maxi, k});
        v.push_back(temp);
    }

    sort(pairs.begin(), pairs.end());


    ll low = 1, high = maxx+1;

    while(low<=high){
        ll mid = low + (high-low)/2;
        if(check(mid, pairs)) high = mid-1;
        else low = mid + 1;
    }
    return low+1;

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