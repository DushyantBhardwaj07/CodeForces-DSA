#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<int> global(201001, 0);

vector<int> solve() {
    int num;
    cin >> num;
    vector<int> result;
    result.push_back(num);
    return result;
}


int main() {
    ios::sync_with_stdio(false);

    for (int i = 0; i < 201001 - 1; ++i) {
        int ans = 0;
        int num = i + 1;
        while (num > 0) {
            ans += num % 10;
            num /= 10;
        }
        global[i + 1] = global[i] + ans;
    }

    vector<int> input = solve();
    int t = input[0];
    while(t-->0){
        int num;
        cin >> num;
        vector<int> temp;
        temp.push_back(num);
        int n = temp[0];
        cout << global[n] << endl;
    }

    return 0;
}
