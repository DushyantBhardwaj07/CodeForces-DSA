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

ll solve() {
    int n;
    cin >> n;
 
    int minn = INT_MAX;
    vector<int> min2;
    for (int i = 0 ; i < n ; i++) {
        int m;
        cin >> m;
        vector<int> v(m);
        for (auto &el : v) cin >> el;
 
        int minel = *min_element(v.begin(), v.end());
        minn = min(minn, minel);
        v.erase(find(v.begin(), v.end(), minel));
        min2.push_back(*min_element(v.begin(), v.end()));
    }
    return  minn + (ll) accumulate(min2.begin(),min2.end(), 0ll) - *min_element(min2.begin(),min2.end());
}

int main()
{
    ios::sync_with_stdio(false);
    ll t;cin>>t;
    while(t-->0){
        cout<<solve()<<endl;
    }
    return 0;
}