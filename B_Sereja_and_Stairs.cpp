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
    vector<ll>v(n, 0);
    for(int i=0;i<n;i++) cin>>v[i];

    sort(v.begin(), v.end(), greater<int> ());
    ll maxi = v[0];
    map<ll,ll>m;
    ll c = 1;
    for(int i=0;i<v.size();i++){
        if(m[v[i]] < 2 && v[i] != maxi){
            m[v[i]] ++;
            c++;
        }
    }
    vector<ll>temp;

    for(auto it : m){
        for(int i=0;i<it.second;i++){
            temp.push_back(it.first);
        }
    }
    sort(temp.begin(), temp.end(), greater<int>());
    ll k = 0;
    if(c & 1){
        vector<ll>ans(c, 0);
        ans[c/2] = maxi;
        ll i = c/2-1;
        ll j = c/2+1;
        while(i >= 0 && j <= c-1){
            ans[i] = temp [k];
            k++;
            ans[j] = temp[k];
            k++;
            i--; j++;
        }

        cout<<c<<endl;
        display(ans);
        return;
        
    }

    vector<ll>ans(c, 0);
    ans[c/2] = maxi;
    ll i = c/2-1;
    ll j = c/2+1;
    while(i >= 0 && j <= c-1){
        ans[i] = temp [k];
        k++;
        ans[j] = temp[k];
        k++;
        i--; j++;
    }

    while(i >=0 ){
        ans[i] = temp [k];
        k++; i--;
    }

    while(j<=c-1){
        ans[j] = temp[k];
        k++; j++;
    }
    
    cout<<c<<endl;
    display(ans);
}

int main()
{
    ios::sync_with_stdio(false);
    solve();
    return 0;
}