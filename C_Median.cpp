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
    ll n,x; cin>>n>>x;
    vector<ll>v(n,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    ll ans = 0;
    sort(v.begin(), v.end());
    
    if(binary_search(v.begin(), v.end(), x)){

        ll median = ((n + 1)/2)-1;
        ll right = INT_MAX, left = INT_MAX;

        for(int i = median;i<n;i++){
            if(v[i] == x){
                right = i;
                break;
            }
        }

        for(int i = median;i>=0;i--){
            if(v[i] == x){
                left = i;
                break;
            }
        }


        if(abs(right - median) < abs(median - left)){
            while(v[((v.size() + 1)/2) - 1] != x){
                ans++;
                v.push_back(v.back());
            }
        } 

        else{
            while(v[((v.size() + 1)/2) - 1] != x){
                ans++;
                v.push_back(v[0]);
                sort(v.begin(), v.end());
            }
        }

    }
    else{
        ans++;
        v.push_back(x);
        sort(v.begin(), v.end());


        ll median = ((v.size() + 1)/2)-1;
        ll right = INT_MAX, left = INT_MAX;

        for(int i=median; i<v.size(); i++){
            if(v[i] == x){
                right = i;
                break;
            }
        }

        for(int i = median; i>=0; i--){
            if(v[i] == x){
                left = i;
                break;
            }
        }


        if(abs(right - median) < abs(median - left)){
            while(v[((v.size() + 1)/2) - 1] != x){
                ans++;
                v.push_back(v.back());
            }
        } 

        else{
            while(v[((v.size() + 1)/2) - 1] != x){
                ans++;
                v.push_back(v[0]);
                sort(v.begin(), v.end());
            }
        }

    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cout<<solve()<<endl;
    return 0;
}