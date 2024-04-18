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
    vector<ll>v(n, 0);
    for(int i=0;i<n;i++) cin>>v[i];
    bool flagAsc = true;
    bool flagDesc = true;

    for(int i=1;i<n;i++){
        if(v[i-1] > v[i]) flagAsc = false;
        if(v[i-1] < v[i]) flagDesc = false;
    }

    if(flagAsc) return 0;

    // for(int i = 1; i <v.size() - 1;i++){
    //     if(v[i-1] < v[i]  && v[i] > v[i+1]){
            
    //         return -1;
    //     }
    // }

    // if(v.size() > 2 && (v[0]>v[1] &&  v[0] > v[n-1])) return -1;

    ll j =0;
    ll ii = 0;
    for(int i = 1; i < n; i++){
        if(v[i] < v[i-1]){
            j = i;
            ii = i-1;
            break;
        }
    }

    ll jj = j;
    j++;
    for(;j<n;j++){
        if(v[j] < v[j-1]){
            return -1;
        }
    }

    vector<ll>temp;

    for(int i = jj; i < n ; i++){
        temp.push_back(v[i]);
    }

    for(int i=0;i<ii+1;i++){
        temp.push_back(v[i]);
    }


    for(int i=1;i<temp.size();i++){
        if(temp[i-1] > temp[i]) return -1;
    }

    // display(temp);



    // cout<<ii  +1<<" "<<jj<<endl;

    // return  min(ii + 1, n- jj);
    return n - jj;

}

int main()
{
    ios::sync_with_stdio(false);
    cout<<solve()<<endl;
    return 0;
}