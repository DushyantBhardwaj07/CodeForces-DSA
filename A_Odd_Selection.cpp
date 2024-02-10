// #include<bits/stdc++.h>
// using namespace std;
// #define yes "Yes"
// #define no "No"
// #define ll long long
// #define mod 1000000007
// void display(vector<ll>v){ for(ll i=0;i<v.size();i++) cout<<v[i]<<' ';cout<<endl;}
// void display2d(vector<vector<ll>> v){for(ll i=0;i<v.size();i++){for(ll j=0;j<v[i].size();j++){cout<<v[i][j]<<' ';}cout<<endl;}cout<<endl;}
// ll add(vector<int>v){int sum = 0;for(int i=0;i<v.size();i++)sum = sum+v[i];return sum;}
// bool isOdd(int n){if(n&1) return true;return false;}
// bool isPrime(int n){if (n <= 1)return false;for (int i = 2; i <= n / 2; i++)if (n % i == 0)return false;return true;}
// bool isVowel(char a){if(a=='a'||a=='e'||a == 'i'||a=='o'||a=='u'||a=='y'){return true;}return false;}

// string solve(){
//     ll n, x; cin>>n>>x;
//     vector<ll>v(n,0);
//     ll sum = 0;
//     for(int i=0;i<n;i++){
//         cin>>v[i];
//         sum = sum + v[i];
//     }

//     ll n1 = n;
//     // cx   out<<sum<<endl;
//     vector<ll>vis(n, false);
//     while(n>x){
//         for(int i=0;i<n1;i++){
//             if(n == x ){
//                 if(sum & 1) return yes;
//                 else return no;
//             }
//             // sum = sum - v[i]
//             if((sum & 1) && !(v[i] & 1) && !vis[i]){
//                 sum = sum - v[i];
//                 vis[i] = true;
//                 n--;
//             }
//             if(!(sum & 1) && (v[i] & 1) && !vis[i]){
//                 sum = sum - v[i];
//                 vis[i] = true;
//                 n--;
//             }
//         }
//     }
//     if(n == x ){
//         if(sum & 1) return yes;
//     }
//     return no;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     ll t;cin>>t;
//     while(t-->0){
//         cout<<solve()<<"\n";
//     }
//     return 0;
// }

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        long long count = 0;

        // Count the number of 1s in each row and column
        vector<int> rowCount(rows, 0);
        vector<int> colCount(cols, 0);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                rowCount[i] += grid[i][j];
                colCount[j] += grid[i][j];
            }
        }

        // Count right triangles
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    // Count triangles with the same row and column
                    count += (rowCount[i] - 1) * (colCount[j] - 1);
                }
            }
        }

        return count;
    }
};
