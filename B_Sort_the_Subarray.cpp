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
    vector<ll>a(n,0);
    vector<ll>b(n,0);

    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];


    vector<ll>sortedA(n,0);
    vector<ll>sortedB(n,0);

    for(int i=1;i<n;i++){
        if(a[i] >= a[i-1]){
            sortedA[i] = 1 + sortedA[i-1];
        }
    }

    for(int i=1;i<n;i++){
        if(b[i] >= b[i-1] ){
            sortedB[i] = 1 + sortedB[i-1];
        }
    }

    // display(sortedA);
    // display(sortedB);

    ll maxi = INT_MIN;
    ll lf = 1, rf = 1;
    
    for(int i=0;i<sortedB.size();i++){
        if(sortedB[i] != 0){
            if(sortedB[i] != sortedA[i]){
                if(i-(i-sortedB[i]) + 1 > maxi){
                    maxi = i-(i-sortedB[i]) + 1;
                    lf = (i-sortedB[i]) + 1;
                    rf = i+1;
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        if(a[i] != b[i]){
            lf= i;
            break;
        }
    }
    for(int i=n-1;i>=0;i--){
        if(a[i] != b[i]){
            rf = i;
            break;
        }
    }
    ll orgl = lf;
    ll orgr = rf;
    while((lf>0) && (b[lf-1] <= b[lf])){
        lf--;
    }

    while((rf<n-1) && (b[rf+1] >= b[rf])){
        rf++;
    }

    cout<<lf+1<<" "<<rf+1<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    ll t;cin>>t;
    while(t-->0){
        solve();
    }
    return 0;
}