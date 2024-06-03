#include<bits/stdc++.h>
using namespace std;
#define yes "YES"
#define no "NO"
#define ll long long
#define mod 1000000007

void display(vector<string>v){ for(ll i=0;i<v.size();i++) cout<<v[i]<<endl;}
void display2d(vector<vector<ll>> v){for(ll i=0;i<v.size();i++){for(ll j=0;j<v[i].size();j++){cout<<v[i][j]<<' ';}cout<<endl;}cout<<endl;}
ll add(vector<int>v){int sum = 0;for(int i=0;i<v.size();i++)sum = sum+v[i];return sum;}
bool isOdd(int n){if(n&1) return true;return false;}
bool isPrime(int n){if (n <= 1)return false;for (int i = 2; i <= n / 2; i++)if (n % i == 0)return false;return true;}
bool isVowel(char a){if(a=='a'||a=='e'||a == 'i'||a=='o'||a=='u'||a=='y'){return true;}return false;}

bool compare(pair<ll,ll> a, pair<ll,ll> b){

    long double dista =sqrt((long double)((long double) (a.first * a.first) + (long double) (a.second * a.second)));
    long double distb = sqrt( (long double)((long double) (b.first * b.first) + (long double) (b.second * b.second)));

    if(distb <= dista) return false;

    return true;
    
}

void solve(){
    ll n; cin>>n;
    vector<pair<ll,ll>>v;
    ll a, b;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        v.push_back({a,b});
    }    

    sort(v.begin(), v.end(), compare);

    vector<string>ans;

    for(int i=0;i<v.size();i++){
        ll x = v[i].first;
        ll y = v[i].second;
        string comebackx;
        string comebacky;
        string dir;
        if(x!=0){
            if(x > 0){
                dir = "R";
                comebackx = "L";
            }
            if(x < 0){
                dir = "L";
                comebackx = "R";
            }
            ans.push_back("1 " + to_string(abs(x)) + " " + dir);
        }        
        if(y!=0){
            if(y > 0){
                dir = "U";
                comebacky = "D";
            }
            if(y < 0){
                dir = "D";
                comebacky = "U";
            }
            ans.push_back("1 " + to_string(abs(y)) + " " + dir);
        }
        ans.push_back("2");
        if(comebackx.length() > 0){
            ans.push_back("1 " + to_string(abs(x)) + " " + comebackx);
        }
        if(comebacky.length() > 0){
            ans.push_back("1 " + to_string(abs(y)) + " " + comebacky);
        }
        ans.push_back("3");
    }
    cout<<ans.size()<<"\n";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<"\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}