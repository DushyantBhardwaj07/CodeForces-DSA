#include<bits/stdc++.h>
using namespace std;
#define ll long long


ll helper(ll i, ll j , ll k, vector<string> &v, string &s, vector<vector<vector<ll>>> &dp){
    if(k < 0 || i <0 || j < 0) return 0;
    if(k == 0 && i == 0 && j == 0) return 1;


    if(((i> 0) && v[i-1][j] != s[k-1]) && ((j > 0) && v[i][j-1] != s[k-1])){
        return 0;
    }

    if(dp[i][j][k] != -1){
        return dp[i][j][k];
    }

    ll up = 0, left = 0;
    if((i > 0) && v[i-1][j] == s[k-1]){
        up = helper(i-1, j, k-1, v, s,dp);
    }

    if((j > 0) && v[i][j-1] == s[k-1]){
        left = helper(i, j-1, k-1, v, s,dp);
    }

    return dp[i][j][k] = up + left;

}
void solve(){
    ll n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    string ans = "";
    vector<string>v;
    stringstream sso;
    v.push_back(s1);
    v.push_back(s2);

    // cout<<n<<endl;

    ll i=0, j=0;
    // ans += v[i][j];
    sso<<v[i][j];
    ll l = 1;
    while(j<n-1){
        if(i == 0){
            if(v[i][j+1] <= v[i+1][j]){
                if(v[i][j+1] < v[i+1][j]) l = 1;
                else if(v[i][j+1] == v[i+1][j]) l++;
                j++;
                sso<<v[i][j];
            }
            else if(v[i][j+1] > v[i+1][j]){
                i++;
                sso << v[i][j];
                break;
            }
        }

    }

    while(j<n-1){
        j++;
        sso<<v[i][j];
        
    }

    if(i == 0 && j == n-1){
        sso<<v[1][j];
    }

    sso>>ans;
    cout<<ans<<endl;
    cout<<l<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    ll t;cin>>t;
    while(t-->0){
        solve();
    }
    return 0;
}