#include <iostream>
#include <vector>
using namespace std;

struct Pair {
    int first;
    long long second;

    Pair(int first, long long second) : first(first), second(second) {}
};

long long getSum(const vector<long long>& sum, int l, int r) {
    if (l == 0) {
        return sum[r];
    } else {
        return sum[r] - sum[l - 1];
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<long long> a(n), sum(n);

    cin >> a[0];
    sum[0] = a[0];

    for (int i = 1; i < n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }

    Pair ans(n - 2 * k, n - k);
    long long ansSum = getSum(sum, n - 2 * k, n - k - 1) + getSum(sum, n - k, n - 1);
    Pair suffMax(n - k, getSum(sum, n - k, n - 1));

    for (int i = n - 2 * k - 1; i >= 0; i--) {
        long long cur = getSum(sum, i + k, i + 2 * k - 1);

        if (cur >= suffMax.second) {
            suffMax = Pair(i + k, cur);
        }

        cur = getSum(sum, i, i + k - 1) + suffMax.second;

        if (cur >= ansSum) {
            ansSum = cur;
            ans = Pair(i, suffMax.first);
        }
    }

    cout << ans.first + 1 << " " << ans.second + 1 << endl;

    return 0;
}
