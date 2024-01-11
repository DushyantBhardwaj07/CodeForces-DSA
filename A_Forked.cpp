#include<bits/stdc++.h>
using namespace std;
#define no "NO"
#define yes "YES"
#define ll long long
#define mod 1000000007
int add(vector<int>v){int sum = 0;for(int i=0;i<v.size();i++)sum = sum+v[i];return sum;}
bool isOdd(int n){if(n&1) return true;return false;}
bool isPrime(int n){if (n <= 1)return false;for (int i = 2; i <= n / 2; i++)if (n % i == 0)return false;return true;}
bool isVowel(char a){if(a=='a'||a=='e'||a == 'i'||a=='o'||a=='u'||a=='y'){return true;}return false;}

const int MOD_VALUE = 1e9 + 7;

int customPower(long long x, long long y) {
    int result = 1;
    while (y) {
        if (y & 1) {
            result = (result * 1ll * x) % MOD_VALUE;
        }
        x = (x * 1ll * x) % MOD_VALUE;
        y >>= 1;
    }
    return result;
}

struct CustomPairHash {
    template <class U1, class U2>
    size_t operator () (const pair<U1, U2>& p) const {
        auto hash1 = hash<U1>{}(p.first);
        auto hash2 = hash<U2>{}(p.second);
        return hash1 ^ hash2;
    }
};

int main() {
    int testCases;
    cin >> testCases;
    while (testCases--) {
        int x, y;
        cin >> x >> y;
        int m1, m2, m3, m4;
        cin >> m1 >> m2;
        cin >> m3 >> m4;
        unordered_set<pair<int, int>, CustomPairHash> set1;
        unordered_set<pair<int, int>, CustomPairHash> set2;

        for (int i = 0; i <= 1; i++) {
            if (i == 0) {
                set1.insert({m1 + x, m2 + y});
                set1.insert({m1 - x, m2 - y});
                set1.insert({m1 + x, m2 - y});
                set1.insert({m1 - x, m2 + y});
            } else {
                set1.insert({m1 + y, m2 + x});
                set1.insert({m1 - y, m2 - x});
                set1.insert({m1 + y, m2 - x});
                set1.insert({m1 - y, m2 + x});
            }
        }
        for (int i = 0; i <= 1; i++) {
            if (i == 0) {
                set2.insert({m3 + x, m4 + y});
                set2.insert({m3 - x, m4 - y});
                set2.insert({m3 + x, m4 - y});
                set2.insert({m3 - x, m4 + y});
            } else {
                set2.insert({m3 + y, m4 + x});
                set2.insert({m3 - y, m4 - x});
                set2.insert({m3 + y, m4 - x});
                set2.insert({m3 - y, m4 + x});
            }
        }
        vector<pair<int, int>> commonElements;
        for (auto &element : set1) {
            if (set2.count(element)) {
                commonElements.push_back(element);
            }
        }

        cout << commonElements.size();
        cout << endl;
    }

    return 0;
}
