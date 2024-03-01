// #include<bits/stdc++.h>
// using namespace std;
// #define yes "YES"
// #define no "NO"
// #define ll long long
// #define mod 1000000007

// char solve(){
//     string a,b,c,d; cin>>a>>b>>c>>d;
//     ll la = a.length() - 2;
//     ll lb = b.length() - 2;
//     ll lc = c.length() - 2;
//     ll ld = d.length() - 2;
//     vector<ll>v = {la,lb,lc,ld};
//     ll cnt = 0;
//     char ans;
//     set<char>s;
//     for(int i=0;i<v.size();i++){
//         bool flag = 1;
//         for(int j = 0;j<v.size();j++){
//             if(i!=j){
//                 if(!(v[i] >= v[j]*2)) flag = 0;
//             }
//         }
//         if(flag){
//             ans = i + 'A';
//             if(s.find(ans) == s.end()){
//                 s.insert(ans);
//                 cnt++;
//             }
//         }
//         flag = 1;
//         for(int j = 0;j<v.size();j++){
//             if(i!=j){
//                 if(!(v[i]*2 <= v[j])) flag = 0;
//             }
//         }
//         if(flag){
//             ans = i + 'A';
//             if(s.find(ans) == s.end()){
//                 s.insert(ans);
//                 cnt++;
//             }
//         }

//     }
//     if(cnt == 1) return ans;
//     return 'C';

// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cout<<solve()<<endl;
//     return 0;
// }
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


int main()
{
    // ios::sync_with_stdio(false);
    // ll t;cin>>t;
    // while(t-->0){
    //     cout<<solve()<<endl;
    // }
    cout<<__gcd(56,15)<<endl;
    return 0;
}