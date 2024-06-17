#include <bits/stdc++.h>
using namespace std;
#define yes "YES"
#define no "NO"
#define ll long long
#define mod 1000000007
bool isPrime(ll n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i <= n / 2; i++)
        if (n % i == 0)
            return false;
    return true;
}

void solve()
{
    ll n;
    cin >> n;
    char c;
    cin >> c;
    string s;
    cin >> s;

    map<char, ll> m;
    bool flag = 0;
    for (auto it : s)
    {
        m[it]++;
        if (m.size() == 2)
        {
            flag = 1;
        }
        if (it != c)
        {
            flag = 1;
        }
    }
    if (!flag)
    {
        cout << 0<<endl;
        return;
    }

    vector<ll> temp;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != c)
        {
            temp.push_back(i + 1);
        }
    }

    int x = -1;
    for (int j = n / 2; j < n; ++j)
    {
        if (s[j] == c)
        {
            x = j + 1;
            break;
        }
    }

    if (x == -1)
    {
        x = n / 2 + 1;
    }

    if (s[x - 1] == c)
    {
        cout << "1" << endl;
        cout << x;
    }
    else
    {
        cout << "2" << endl;
        cout << x << " " << x + 1;
    }
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    ll t;
    cin >> t;
    while (t-- > 0)
    {
        solve();
    }
    return 0;
}