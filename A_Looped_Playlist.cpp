#include <bits/stdc++.h>
using namespace std;
#define yes "YES"
#define no "NO"
#define ll long long
#define mod 1000000007

void display(vector<ll>v){ for(ll i=0; i<v.size(); i++) cout<<v[i]<<' '; cout<<endl;}
void display2d(vector<vector<ll>> v){for(ll i=0; i<v.size(); i++){for(ll j=0; j<v[i].size(); j++){cout<<v[i][j]<<' ';}cout<<endl;} cout<<endl;}
ll add(vector<ll>v){ll sum = 0; for(ll i=0; i<v.size(); i++) sum = sum + v[i]; return sum;}
bool isOdd(ll n){return n & 1;}
bool isPrime(ll n){if (n <= 1) return false; for (ll i = 2; i <= n / 2; i++) if (n % i == 0) return false; return true;}
bool isVowel(char a){return a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u' || a == 'y';}

void solve() {
    ll n, p;
    cin >> n >> p;
    vector<ll> v(n, 0);
    ll sum = 0;

    for (ll i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
    }

    ll temp = p / sum;

    if (temp == 0) {
        for (ll i = 0; i < n; i++) {
            v.push_back(v[i]);
        }
        ll ind = 0;
        ll number = LLONG_MAX;
        for (ll i = 0; i < 2 * n; i++) {
            ll sub_sum = 0;
            ll j = i;
            for (; j < 2 * n; j++) {
                sub_sum += v[j];
                if (sub_sum >= p) break;
            }

            if ((sub_sum >= p) && (j - i + 1) < number) {
                number = j - i + 1;
                ind = i % n;
            }
        }

        cout << ind + 1 << " " << number << endl;
    } else {
        p = p - temp * sum;
        ll summ = 0;
        ll cnt = 0;
        for (ll i = 0; i < n; i++) {
            summ += v[i];
            cnt++;
            if (summ >= p) break;
        }
        cout << 1 << " " << cnt + temp * n << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    while (t-- > 0) {
        solve();
    }
    return 0;
}
