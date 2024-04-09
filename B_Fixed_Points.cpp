    #include<bits/stdc++.h>
    using namespace std;
    #define no "NO"
    #define yes "YES"
    #define ll long long
    #define mod 1000000007
    void display(vector<ll>v){ for(ll i=0;i<v.size();i++) cout<<v[i]<<' ';cout<<endl;}
    void display2d(vector<vector<ll>> v){for(ll i=0;i<v.size();i++){for(ll j=0;j<v[i].size();j++){cout<<v[i][j]<<' ';}cout<<endl;}cout<<endl;}
    int add(vector<int>v){int sum = 0;for(int i=0;i<v.size();i++)sum = sum+v[i];return sum;}
    bool isOdd(int n){if(n&1) return true;return false;}
    bool isPrime(int n){if (n <= 1)return false;for (int i = 2; i <= n / 2; i++)if (n % i == 0)return false;return true;}
    bool isVowel(char a){if(a=='a'||a=='e'||a == 'i'||a=='o'||a=='u'||a=='y'){return true;}return false;}

    ll solve(){
        ll n; cin>>n;
        vector<ll>v(n,0);

        ll temp =0;
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        for(int i=0;i<n;i++){
            if(v[i] == i) temp++;
        }
        ll ans = temp;
        if(ans == n) return temp;
        ll maxi = INT_MIN;
        for(int i=0;i<n;i++){
            if(v[i]==i){
                continue;
            }
            else{
                ll var = v[i];
                swap(v[var], v[i]);
                if(i == v[i] && v[var] == var){
                    ans = ans+2;
                    maxi = max(maxi, ans);
                    break;
                }
                else{
                    maxi = max(maxi, ans+1);
                }
                swap(v[var], v[i]);

            }
        }
        return  maxi;
    }

    int main()
    {
        ios::sync_with_stdio(false);
        cout<<solve()<<endl;
        return 0;
    }