#include<bits/stdc++.h>
using namespace std;
#define yes "YES"
#define no "NO"
#define ll long long
#define mod 1000000007
void display(vector<string>v){ for(ll i=0;i<v.size();i++) cout<<v[i]<<' ';cout<<endl;}
void display2d(vector<vector<bool>> v){for(ll i=0;i<v.size();i++){for(ll j=0;j<v[i].size();j++){cout<<v[i][j]<<' ';}cout<<endl;}cout<<endl;}
ll add(vector<int>v){int sum = 0;for(int i=0;i<v.size();i++)sum = sum+v[i];return sum;}
bool isOdd(int n){if(n&1) return true;return false;}
bool isPrime(int n){if (n <= 1)return false;for (int i = 2; i <= n / 2; i++)if (n % i == 0)return false;return true;}
bool isVowel(char a){if(a=='a'||a=='e'||a == 'i'||a=='o'||a=='u'||a=='y'){return true;}return false;}

vector <int> movex = {0, -1, -1, -1, 0, 1, 1, 1};
vector <int> movey = {1, 1, 0 , -1, -1, -1, 0, 1};

void dfs(int i, int j, vector<vector<char>> &v,string s, vector<string> &ans, vector<vector<bool>> &vis){
    vis[i][j] = true;
    s = s + v[i][j];

    if(s.length() == 3){
        ans.push_back(s);
        display2d(vis);
    }

    for(int i=0;i<8;i++){
        ll x = i + movex[i];
        ll y = j + movey[i];

        if(x >= 0 && x <=2 && y >=0 && y <=2 && !vis[x][y]){
            dfs(x, y, v, s, ans, vis);
        }

    }
    vis[i][j] = false;
}

string solve(){
    vector<vector<char>> v (3, vector<char> (3, '0'));
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>v[i][j];
        }
    }
    vector<string>ans;

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            string s = "";
            vector<vector<bool>>vis(3, vector<bool>(3, false));
            dfs(i, j, v, s, ans, vis);
        }
    }
    sort(ans.begin(), ans.end());
    display(ans);
    return ans[0];
}

int main()
{
    ios::sync_with_stdio(false);
    cout<<solve()<<endl;
    return 0;
}