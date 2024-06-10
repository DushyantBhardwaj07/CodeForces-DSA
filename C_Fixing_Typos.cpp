#include<bits/stdc++.h>
using namespace std;
#define yes "YES"
#define no "NO"
#define ll long long
#define mod 1000000007
void display(vector<char>v){ for(ll i=0;i<v.size();i++) cout<<v[i]<<' ';cout<<endl;}
void display2d(vector<vector<ll>> v){for(ll i=0;i<v.size();i++){for(ll j=0;j<v[i].size();j++){cout<<v[i][j]<<' ';}cout<<endl;}cout<<endl;}
ll add(vector<int>v){int sum = 0;for(int i=0;i<v.size();i++)sum = sum+v[i];return sum;}
bool isOdd(int n){if(n&1) return true;return false;}
bool isPrime(int n){if (n <= 1)return false;for (int i = 2; i <= n / 2; i++)if (n % i == 0)return false;return true;}
bool isVowel(char a){if(a=='a'||a=='e'||a == 'i'||a=='o'||a=='u'||a=='y'){return true;}return false;}

void solve(){
    string s; cin>>s;
    vector<char>ans;
    bool flag = false;
    for(int i=0;i<s.length();i++){

        if(!flag || (ans.size() < 2)){
            ans.push_back(s[i]);
        }

        else if((s[i] == ans.back()) && (s[i] == ans[ans.size() -2])){ 
            continue;
        }

        else if(flag && (s[i]!=ans.back())){
            flag = false;
            ans.push_back(s[i]);
            while(s[i+1] == s[i]){
                i++;
            }

        }
        
        if(ans.size() >= 2){
            if(ans[ans.size()-1] == ans[ans.size()-2]){
                flag = true;                
            }
        }
    }

    for(int i=0;i<ans.size();i++){
        cout<<ans[i];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    solve();
    return 0;
}