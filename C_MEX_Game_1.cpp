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
    vector<ll>v(n, 0);
    vector<ll>m(n+1, 0);
    for(int i=0;i<n;i++){
        cin>>v[i];
        m[v[i]]++;
    }
    sort(v.begin(), v.end());

    priority_queue <pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq; 

    for(ll i=0;i<m.size();i++){
        if(m[i] > 0)pq.push({m[i], i}); // freq -- element
    }

    vector<ll>c;
    auto it = pq.top();
    c.push_back(pq.top().second);    
    pq.pop();
    if((it.first-1) > 0) pq.push({it.first-1, it.second});
    

    while(!pq.empty()){

        if(pq.top().first == 0){
            pq.pop();
        }

        else{
            // Bob
            auto itr = pq.top();
            pq.pop();
            if(itr.first > 0){
                pq.push({itr.first-1, itr.second});
            }

            if(pq.top().first == 0){                
                pq.pop(); 
            }
            // Alice
            if(!pq.empty()){
                auto i = pq.top();
                pq.pop();
                if(i.first > 0){
                    c.push_back(i.second);
                    pq.push({i.first-1, i.second});
                }
            }

        }
    }

    sort(c.begin(), c.end());

    ll cnt = 0;
    for(int i=0;i<c.size();i++){
        if((c[i] != cnt) && (cnt > c[i])){
            continue;
        }
        else if((c[i] != cnt) && (cnt < c[i])){
            return cnt;            
        }
        cnt++;
    }
    return cnt;

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
