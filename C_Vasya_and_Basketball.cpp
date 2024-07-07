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

string solve(){
    ll n, m; 
    cin>>n;
    ll a;
    vector<pair<ll,ll>>v;

    for(int i=0;i<n;i++){
        cin>>a;
        v.push_back({a, 1});
    }
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>a;
        v.push_back({a, 2});
    }

    sort(v.begin(), v.end());

    ll maxi = INT_MIN;
    ll scoreA = n*3;
    ll scoreB = m*3;
    maxi = max(maxi, scoreA - scoreB);

    ll ansA = scoreA;   
    ll ansB = scoreB;

    for(int i=0;i<v.size();i++){
        if(v[i].second == 1){
            scoreA--;
        }
        if(v[i].second == 2){
            scoreB--;
        }

        if(scoreA - scoreB > maxi){
            maxi = scoreA - scoreB;
            ansA = scoreA;
            ansB = scoreB;
        }
    }

    string ans = to_string(ansA) + ":" + to_string(ansB);

    return ans;
    
}

int main()
{
    ios::sync_with_stdio(false);
    cout<<solve()<<"\n";
    return 0;
}