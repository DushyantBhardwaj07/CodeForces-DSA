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
    string s; cin>>s;
    ll ans = 0;
    bool flag = 1;
    for(int i = 0;i<n;i++){
        if(s[i] == 'L'){
            ans = 0;
        }
        if(s[i] == '.'){
            ans++;
        }
        if(s[i] == 'R'){
            break;
        }
        s[i] = '*';
    }

    ll last =0;
    for(int i = n-1;i>=0;i--){
        if(s[i] == 'R'){
            last = 0;
        }
        if(s[i] == '.'){
            last++;
        }
        if(s[i] == 'L'){
            break;
        }
        s[i] = '*';
    }

    ans = ans + last;

    ll mid = 0;
    for(int i=0;i<n;i++){

        if(s[i] == 'R'){

            for(int j = i+1;j<n;j++){

                if(s[j] == 'L'){
                    
                    if(!((j - i) & 1)){

                        mid++;

                        break;                        
                    }
                }
                    

                else if(s[j] == 'R'){
                    break;
                }

                s[j] = '*';
            }
        }

        else if(s[i] == 'L'){

            for(int j = i+1; j<n;j++){

                if(s[j] == ''){

                }                

            }

        }
        
        s[i] = '*';
    }

    for(auto it : s){
        if(it == '.') ans++;
    }
    return ans + mid;
}

int main()
{
    ios::sync_with_stdio(false);
    cout<<solve()<<endl;
    return 0;
}