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
    ll n; cin>>n;
    vector<pair<ll,ll>>positive;
    vector<pair<ll,ll>>negative;
    ll a,b;
    ll beforeZero = 0, afterZero = 0;
    ll beforeSum = 0, afterSum =0;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        if(a<0){
            negative.push_back({a,b});
            beforeZero++;
            beforeSum = beforeSum+b;
        }
        if(a>0){
            positive.push_back({a,b});
            afterZero++;
            afterSum = afterSum+b;
        }
    }

    sort(positive.begin(), positive.end());
    sort(negative.begin(), negative.end(),greater<pair<ll,ll>>());
    ll ans = 0;
    if(beforeZero<afterZero){
        ans = ans+beforeSum;
        if((beforeZero+1 > positive.size()) || (beforeZero == 0)) return positive[0].second;
        for(int i=0;i<beforeZero+1;i++){
            ans = ans+positive[i].second;
        }
    }
    else if(beforeZero>afterZero){
        // cout<<"test"<<endl;
        ans = ans+afterSum;
        // cout<<afterZero<<endl;
        if((afterZero+1 > negative.size()) || (afterZero == 0)) return negative[0].second;

        for(int i=0;i<afterZero+1;i++){
            ans = ans+negative[i].second;
        }
    }
    else{
        ans = ans+afterSum+beforeSum;
    }
    return ans;

}

int main()
{
    ios::sync_with_stdio(false);
    cout<<solve()<<endl;
    return 0;
}