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
    ll n, k; cin>>n>>k;
    string s; cin>>s;
    map<ll,char>m;
    stack<char> st;
    char temp = 'A';
    for(int i=0;i<k;i++){
        m[i+1] = temp;
        temp++;
    }
    ll ans = 0;
    stringstream sso1;
    for(int i=0;i<n;i++){

        if(st.empty()){
            st.push(s[i]);
            sso1<<s[i];

        }

        else if(!st.empty() && st.top() == s[i]){
            if(i == n-1){
                for(int j= 1; j<= k ; j++){
                    if(j !=  (ll) (st.top() - 64)){
                        if(m.find(j) != m.end()){
                            st.push(m[j]);
                            sso1<<m[j];
                            ans++;
                            break;
                        }
                    }

                }                
            }

            else{
                for(int j= 1; j<= k ; j++){
                    if(k == 2){
                        if(j !=  (ll) (st.top() - 64) && j!= (ll) (s[i] - 64)){
                            if(m.find(j) != m.end()){
                                st.push(m[j]);
                                sso1<<m[j];
                                ans++;
                                break;
                            }
                        }
                    }
                    else{
                        if(j !=  (ll) (st.top() - 64) && j!= (ll) (s[i] - 64) && j!= (ll) (s[i+1] - 64)){
                            if(m.find(j) != m.end()){
                                st.push(m[j]);
                                sso1<<m[j];
                                ans++;
                                break;
                            }
                        }
                    }

                }
            }
            
        }

        else{
            st.push(s[i]);
            sso1<<s[i];
        }
    }

    
    ll ans2 = 0;
    string ansstr2 = "";
    stack<char>st2;
    stringstream sso2;
    if(k == 2){
        ans2++;
        if(s[0] == 'A'){
            st2.push('B');
            sso2<<'B';
        }
        else if(s[0] == 'B'){
             st2.push('A');
             sso2<<'A';
        }

        for(int i= 1;i<n;i++){
            if(st2.top() == s[i] ){
                for(int j= 1; j<= k ; j++){
                    if(j !=  (ll) (st2.top() - 64) && j!= (ll) (s[i] - 64)){
                        if(m.find(j) != m.end()){
                            st2.push(m[j]);
                            sso2<<m[j];
                            ans2++;
                            break;
                        }
                    }
                }
            }
            else{
                st2.push(s[i]);
                sso2<<s[i];
            }
        }
        sso2 >> ansstr2;

    }


    string ansstr = "";
    sso1 >> ansstr;
    if( k == 2 && (ans2< ans)){
        cout<<ans2<<endl;
        cout<<ansstr2<<endl;
        return;
    }

    cout<<ans<<endl;
    cout<<ansstr<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}