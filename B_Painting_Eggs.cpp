#include<bits/stdc++.h>
using namespace std;
#define yes "YES"
#define no "NO"
#define ll long long
#define mod 1000000007
void display(vector<char>v){ for(ll i=0;i<v.size();i++) cout<<v[i]; cout<<endl;}
void display2d(vector<vector<ll>> v){for(ll i=0;i<v.size();i++){for(ll j=0;j<v[i].size();j++){cout<<v[i][j]<<' ';}cout<<endl;}cout<<endl;}
ll add(vector<int>v){int sum = 0;for(int i=0;i<v.size();i++)sum = sum+v[i];return sum;}
bool isOdd(int n){if(n&1) return true;return false;}
bool isPrime(int n){if (n <= 1)return false;for (int i = 2; i <= n / 2; i++)if (n % i == 0)return false;return true;}
bool isVowel(char a){if(a=='a'||a=='e'||a == 'i'||a=='o'||a=='u'||a=='y'){return true;}return false;}

void solve(){
    ll n; cin>>n;
    ll a,b;
    vector<pair<ll,ll>>v;
    ll suma = 0;
    ll sumb = 0;
    priority_queue<pair<ll,ll>>maxHeap;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        v.push_back({a,b});
        suma = suma + a;
        maxHeap.push({b, i});
    }

    vector<char>ans(n, 'A');
    while(!maxHeap.empty()){
        if((suma - sumb) <= 500){
            break;
        }
        else if(suma > sumb){
            ans[maxHeap.top().second] = 'G';   
            suma = suma - v[maxHeap.top().second].first;
            sumb = sumb + maxHeap.top().first;
            maxHeap.pop();
        }
    }
    display(ans);
}

int main()
{
    ios::sync_with_stdio(false);
    solve();
    return 0;
}