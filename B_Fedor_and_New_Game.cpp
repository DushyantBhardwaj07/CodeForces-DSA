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

string dectobin(ll &n, ll num){
        stringstream sso;
        ll temp = num;
        ll rem = 0;
        string ans = "";
        ll cnt = n;
        while(temp > 0 && cnt > 0){
            rem = temp % 2;
            ans = to_string(rem) + ans;
            temp = temp/2;
            cnt--;
        }       
        ll c = n - ans.length();
        while(c > 0){
            sso<<'0';
            c--;        
        }
        string add; sso>>add;            
        return add+ans;
}

ll solve(){
    ll n,m,k; cin>>n>>m>>k;
    ll fred;

    vector<ll>v(m, 0);
    for(int i=0;i<m;i++){
        cin>>v[i];
    }
    cin>>fred;
    string comp = dectobin(n, fred);

    ll ans =0;

    for(int i=0;i<m;i++){
        string temp = dectobin(n, v[i]);
        ll diff = 0;
        for(int j=0;j<temp.length();j++){
            if(comp[j] != temp[j]){
                
                diff++;
            }
        }
    
        if(diff<=k){
            ans++;
        }
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<solve()<<"\n";
    return 0;
}