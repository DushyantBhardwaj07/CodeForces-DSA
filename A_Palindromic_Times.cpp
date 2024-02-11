#include<bits/stdc++.h>
using namespace std;
#define yes "YES"
#define no "NO"
#define ll long long
#define mod 1000000007
void display(vector<string>v){ for(ll i=0;i<v.size();i++) cout<<v[i]<<' ';cout<<endl;}
void display2d(vector<vector<ll>> v){for(ll i=0;i<v.size();i++){for(ll j=0;j<v[i].size();j++){cout<<v[i][j]<<' ';}cout<<endl;}cout<<endl;}
ll add(vector<int>v){int sum = 0;for(int i=0;i<v.size();i++)sum = sum+v[i];return sum;}
bool isOdd(int n){if(n&1) return true;return false;}
bool isPrime(int n){if (n <= 1)return false;for (int i = 2; i <= n / 2; i++)if (n % i == 0)return false;return true;}
bool isVowel(char a){if(a=='a'||a=='e'||a == 'i'||a=='o'||a=='u'||a=='y'){return true;}return false;}



string solve(){
    string s; cin>>s;
    vector<string>v = {"00:00", "01:10" , "02:20", "03:30" ,"04:40", "05:50", "10:01" , "11:11",  "12:21" , "13:31" , "14:41" , "15:51" , "20:02" , "21:12" , "22:22" , "23:32" };
    ll hr = stoi(s.substr(0, 2));
    ll sec = stoi(s.substr(3, 2));
    for(int i=0;i<v.size();i++){
        ll hrtemp = stoi(v[i].substr(0, 2));   
        ll sectemp = stoi(v[i].substr(3, 2));
        if(hrtemp>=hr){
            if(hrtemp == hr){
                if(sectemp>sec) return v[i];
            }
            else{
                return v[i];
            }
        }
    }
    return "00:00";
}

int main()
{
    ios::sync_with_stdio(false);
    cout<<solve()<<endl;
    return 0;
}