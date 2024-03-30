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

void solve(){
    ll n,m; cin>>n>>m;
    vector<ll>v;
    for(int i=1;i<=n;i++) v.push_back(i);
    vector<vector<ll>>ans;
    map<ll,vector<ll>>mp;
    ll a,b;
    for(int i = 0;i<m;i++){
        cin>>a>>b;
        mp[a].push_back(b);
    }

    set<ll>sets;
    set<ll>donttake;
    for(auto it : mp){
        vector<ll>temp;
        if(it.second.size() >= 3){
            cout<<-1<<endl;
            return;
        }
        if(it.second.size() == 2){
            temp.push_back(it.first);
            temp.push_back(it.second[0]);
            temp.push_back(it.second[1]);
            ans.push_back(temp);
            donttake.insert(it.first);
            donttake.insert(it.second[0]);
            donttake.insert(it.second[1]);
        }

        sets.insert(it.first);
        for(int i=0;i<it.second.size();i++){
            sets.insert(it.second[i]);
        }
    }

    vector<ll>others;

    for(int i = 1;i<=n;i++){
        if((donttake.find(i) == donttake.end()) && (mp.find(i) != mp.end())){
            others.push_back(i);

            for(int j = 0; j < mp[i].size(); j++){
                others.push_back(mp[i][j]);
            }
            for(int j =1; j<= n ;j++){
                if(sets.find(j) == sets.end()){
                    others.push_back(j);
                    if(others.size() == 3){
                        ans.push_back(others);
                        sets.insert(others[0]);
                        sets.insert(others[1]);
                        sets.insert(others[2]);
                        others.clear();
                        break;
                    }
                }
            }
            
        }
    }

    vector<ll>koi;
    for(int i= 1 ;i<=n;i++){
        if(sets.find(i) == sets.end()){
            koi.push_back(i);
            if(koi.size() == 3){
                ans.push_back(koi);
                koi.clear();
            }
        }
    }

    if(ans.size() != (n/3)){
        cout<<-1<<endl;
        return;
    }
    ll c = 0;
    for(int i=0;i<ans.size();i++){
        if(ans[i].size() != 3){
            cout<<-1<<endl;
            return;
        }
    }
    display2d(ans);

}

int main()
{
    ios::sync_with_stdio(false);
    solve();
    return 0;
}