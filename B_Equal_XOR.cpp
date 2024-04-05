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
    ll n,k; cin>>n>>k;
    vector<ll>left(n+1, 0);
    vector<ll>right(n+1,0);
    ll a;
    for(int i=0;i<n;i++){
        cin>>a;
        left[a]++;
    }
    for(int i=n;i<2*n;i++){
        cin>>a;
        right[a]++;
    }

    ll l = 2*k;
    ll r = 2*k;
    ll cnt = 1;
    vector<ll>leftAns;
    vector<ll>rightAns; 

    while(l > 0 && r >0 && cnt<=n){
        if(l > 1 && left[cnt] == 2){
            left[cnt] = 0;
            leftAns.push_back(cnt);
            leftAns.push_back(cnt);
            l = l-2;
        }
        else if(r>1 && right[cnt] == 2){
            right[cnt] = 0;
            rightAns.push_back(cnt);
            rightAns.push_back(cnt);
            r = r -2;
        }
        cnt++;
    }

    if(l > 0){
        for(int i=0;i<left.size();i++){
            if(l > 1 && left[i] == 2){
                leftAns.push_back(i);
                leftAns.push_back(i);
                l =l-2;
            }
        }
    }

    if(r > 0){
        for(int i=0;i<right.size();i++){
            if(r > 1 && right[i] == 2){
                rightAns.push_back(i);
                rightAns.push_back(i);
                r =r-2;
            }
        }
    }
    cnt =1;
    while(l>0 && r>0 && cnt<=n){
        if(left[cnt] >0 && right[cnt] >0){
            left[cnt]--;
            right[cnt]--;
            leftAns.push_back(cnt);
            rightAns.push_back(cnt);
            l--; r--;
        }
        cnt++;
    }



    display(leftAns);
    display(rightAns);


}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;cin>>t;
    while(t-->0){
        solve();
    }
    return 0;
}