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
    vector<ll>v(n,0);
    ll sum = 0;
    
    for(int i=0;i<n;i++){
        cin>>v[i];
        sum = sum + v[i];
    }   
    if(k >= sum) return n;
    ll i =0, j = n-1;
    ll f = 0;
    while(k >0 && (i<j)){
        ll temp = 2 * min(v[i], v[j]);
        if(k>=temp){
            f++;
            k = k - temp;
            if(v[i]<v[j]){
                v[j] = v[j] - v[i];
                i++;
            }
        
            else if(v[i] == v[j]){
                j--; i++;
                f++;
            }   

            else{
                v[i] = v[i] - v[j];
                j--;
            }
        }
        else if((k+1)== temp && v[i]<=v[j]){
            return f+1;
        }
        else break;
    }

    return f;
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
