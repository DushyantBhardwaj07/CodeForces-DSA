#include<bits/stdc++.h>
using namespace std;
#define yes "YES"
#define no "NO"
#define ll long long
#define mod 1000000007
void display(vector<string>v){ for(ll i=0;i<v.size();i++) cout<<v[i]<<endl;cout<<endl;}
void display2d(vector<vector<ll>> v){for(ll i=0;i<v.size();i++){for(ll j=0;j<v[i].size();j++){cout<<v[i][j]<<' ';}cout<<endl;}cout<<endl;}
ll add(vector<int>v){int sum = 0;for(int i=0;i<v.size();i++)sum = sum+v[i];return sum;}
bool isOdd(int n){if(n&1) return true;return false;}
bool isPrime(int n){if (n <= 1)return false;for (int i = 2; i <= n / 2; i++)if (n % i == 0)return false;return true;}
bool isVowel(char a){if(a=='a'||a=='e'||a == 'i'||a=='o'||a=='u'||a=='y'){return true;}return false;}

void solve(){
    ll n; cin>>n;
    vector<string>captain;
    vector<string>womanandchild;
    vector<string>man;
    vector<string>rat;

    string s;
    string job;
    for(int i=0;i<n;i++){
        cin>>s; cin>>job;
        if(job == "captain") captain.push_back(s);
        else if(job == "woman" || job == "child") womanandchild.push_back(s);
        else if(job == "rat") rat.push_back(s);
        else if(job == "man") man.push_back(s);
        
    }
    vector<string> ans;
    for(int i=0;i<rat.size();i++) ans.push_back(rat[i]);
    for(int i=0;i<womanandchild.size();i++) ans.push_back(womanandchild[i]);
    for(int i=0;i<man.size();i++) ans.push_back(man[i]);
    for(int i=0;i<captain.size();i++) ans.push_back(captain[i]);

    display(ans);

}

int main()
{
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
