#include <bits/stdc++.h>
using namespace std;
#define yes "YES"
#define no "NO"
#define ll long long
#define mod 1000000007
void display(vector<ll> v)
{
    for (ll i = 0; i < v.size(); i++)
        cout << v[i] << ' ';
    cout << endl;
}
void display2d(vector<vector<ll>> v)
{
    for (ll i = 0; i < v.size(); i++)
    {
        for (ll j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}
ll add(vector<int> v)
{
    int sum = 0;
    for (int i = 0; i < v.size(); i++)
        sum = sum + v[i];
    return sum;
}
bool isOdd(int n)
{
    if (n & 1)
        return true;
    return false;
}
bool isPrime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i <= n / 2; i++)
        if (n % i == 0)
            return false;
    return true;
}
bool isVowel(char a)
{
    if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u' || a == 'y')
    {
        return true;
    }
    return false;
}

void solve()
{

    int t;
    cin >> t;

    cin.ignore();

    while (t--)
    {
        string s;
        getline(cin, s);

        bool miao = false;
        bool lala = false;

        // cout<<s<<endl;

        if (s.length() >= 5)
        {
            if (s.substr(0, 5) == "miao.")
            {

                miao = true;
            }

            if (s.substr(s.length() - 5, 5) == "lala.")
            {
                lala = true;
            }
        }

        // cout<<lala<<" "<<miao<<endl;

        if (lala && miao || !lala && !miao)
        {
            cout << "OMG>.< I don't know!" << endl;
        }

        else if (lala && !miao)
        {
            cout << "Freda's" << endl;
        }

        else
        {
            cout << "Rainbow's" << endl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    solve();
    return 0;
}