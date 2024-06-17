#include<bits/stdc++.h>
using namespace std;
#define yes "YES"
#define no "NO"
#define ll long long
#define mod 1000000007

ll solve(){
    int n; cin>>n;
    vector<ll>v(n,0);
    for(int low=0;low<n;low++) cin>>v[low];
    bool flag = 0;
    bool comp =1;
    for(int low=1;low<v.size();low++){
        if(v[low] != v[low-1]) {
            comp = 0;
            break;
        }
    }
    if(comp) return 0;

    int c = 0;
    int low = 0;
    int temp = v[0];
    int maxi = 0;

    while (maxi < n && v[low] == temp) {
        low++;
        c++;
    }
    maxi = max(maxi, c);

    if (low == n) {
        cout << "0" << endl;
        return 0;
    }

    if (v[n - 1] != temp) {
        c = 0;
        temp = v[n - 1];
    }

    low = n - 1;
    while (low >= 0 && v[low] == temp) {
        low--;
        c++;
    }
    maxi = max(maxi, c);
    
    int ans = n - maxi;
    return ans;

}


int main()
{
    ios::sync_with_stdio(false);
    ll t;cin>>t;
    while(t-->0){
        cout<<solve()<<endl;
    }
    return 0;
}