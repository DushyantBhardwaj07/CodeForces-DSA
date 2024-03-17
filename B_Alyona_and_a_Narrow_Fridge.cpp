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
    ll n,h; cin>>n>>h;
    vector<ll>v(n,0);
    ll ansmaxi = 1;
    for(int i=0;i<n;i++) cin>>v[i];

    for(ll i=1;i<n;i++){
        ll ans = 0;
        ll h1 = h;
        vector<ll>sub = {v.begin(), v.begin() + i+1};
        sort(sub.begin(), sub.end(), greater<ll>());
        // display(sub);
        if(sub.size() & 1){
            ll maxi = 0;
            ll  k =0;
            for(int j=0;j<sub.size()-1;j=j+2){
                maxi = max(sub[j], sub[j+1]);
                if(maxi<=h1){
                    h1 = h1-maxi;
                    ans = ans + 2;
                    ansmaxi = max(ansmaxi, ans);
                    k = j;
                }
                else{
                    break;
                }
                k = j+2;
            }
            if(k == sub.size()-1){
                if(sub.back() <= h1){
                    h1 = h1 - sub.back();
                    ans++;
                    ansmaxi = max(ansmaxi, ans);

                }
            }

        }
        else{
            ll maxi;
            for(int j=0;j<sub.size();j=j+2){
                maxi = max(sub[j], sub[j+1]);
                if(maxi <= h1){
                    h1 = h1-maxi;
                    ans = ans + 2;
                    ansmaxi = max(ansmaxi, ans);
                }
                else{
                    break;
                }
            }
        }
    }
    return ansmaxi;

}

int main()
{
    ios::sync_with_stdio(false);
    ll t=1;
    while(t-->0){
        cout<<solve()<<"\n";
    }
    return 0;
}