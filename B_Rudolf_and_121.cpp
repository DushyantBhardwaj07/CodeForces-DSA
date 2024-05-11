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
    ll n; cin>>n;
    vector<ll>temp(n,0);
    ll s = 0;
    for(int i=0;i<n;i++){
        cin>>temp[i];
        s = s + temp[i];
    }

    for(int i = 1;i <n-1;i++){
        if(temp[i-1]<=temp[i+1]&&temp[i]>=2*temp[i-1]) { 
            temp[i+1]-=temp[i-1]; 
            temp[i]-=2*temp[i-1]; 
            temp[i-1]=0; 
        } 
    }

    for(int i=0;i<n;i++){
        if(temp[i] != 0)  return no;
    }
    return yes;
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


            if(arr[i-1]<=arr[i+1]&&arr[i]>=2*arr[i-1]) 
            { 
                arr[i+1]-=arr[i-1]; 
                arr[i]-=2*
                arr[i-1]; 
                 arr[i-1]=0; 
            } 
