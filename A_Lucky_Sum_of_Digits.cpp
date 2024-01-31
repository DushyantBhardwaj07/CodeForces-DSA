#include<bits/stdc++.h>
using namespace std;
#define yes "YES"
#define no "NO"
#define ll long long
#define mod 1000000007

string solve(){
    double n; cin>>n;
    ll sum = 0;
    string ans;
    double maxi = INT_MAX;
    ll f = 0, s= 0; 
    for(double i=0;i<=1000000;i++){
        double temp = (n - (7 * i))/4.0;
        if(temp<0){
            break;
        }
        if(ceil(temp) == floor(temp)){
            if((temp + i) < maxi){
                maxi = temp + i;
                f = temp;
                s = i;
            }
        }
    }
    stringstream sso;
    for(int i=0;i<f;i++){
        sso<<4;
    }
    for(int i=0;i<s;i++){
        sso<<7;
    }
    sso>>ans;
    if(ans.length() == 0) return "-1";
    return ans;


}

int main()
{
    ios::sync_with_stdio(false);
    cout<<solve()<<endl;
    return 0;
}