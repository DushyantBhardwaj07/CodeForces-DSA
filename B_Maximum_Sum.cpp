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
    ll n, k; cin>>n>>k;
    ll k2 = k;
    ll k1 = k;
    vector<ll>v(n, 0);
    ll sum = 0;
    for(int i=0;i<n;i++){
        cin>>v[i];
        sum = sum + v[i];
    }
    ll summ = sum;
    sort(v.begin(), v.end());
    // display(v);
    // cout<<sum<<endl;

    ll i=0, j=n-1;
    while(i<j && i+1<j && k>0){
        ll first = v[i];
        ll second = v[i+1];
        ll last = v[j];

        if(first+second <= last){
            sum = sum - first - second;
            i = i +2;
            k--;
        }

        else if(first+second > last){
            sum = sum - last;
            j--;
            k--;
        }

    }  

    ll mini = summ;
    // cout<<n-k<<endl;
    for(int i=n-1;i>=n-k1;i--){
        summ = summ-v[i];
    }

    i = 0;
    while(k1 > 0 && i<n){
        mini = mini - v[i];
        i++;
        mini = mini - v[i];
        i++;
        k1--;
    }

    vector<ll>prefix(n, 0);
    prefix[0] = v[0];
    for(int i=1;i<n;i++){
        prefix[i] = v[i] + prefix[i-1];
    }
    // display(prefix);

    ll maxi = INT_MIN;

    for(int i=0;i<=k2;i++){
    // cout<<"pogek";
            // cout<<maxi<<endl;
        if(i == 0){
            maxi = max(maxi, prefix[n -(k2-i)- 1]);
            // cout<<maxi<<endl;
        }

        else {
            maxi = max(maxi, prefix[n -(k2-i)- 1] - prefix[(i*2)-1]);
        }
    }

    // cout<<summ<<" "<<sum<<endl;

    // cout<<k<<endl;
    return max({summ, sum, mini, maxi});
}

int main()
{
    ios::sync_with_stdio(false);
    ll t;cin>>t;
    while(t-->0){
        cout<<solve()<<"\n";
    }
    return 0;
}