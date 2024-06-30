#include<bits/stdc++.h>
using namespace std;
#define yes "YES"
#define no "NO"
#define ll long long
#define mod 1000000007
void display(vector<ll>a){ for(ll i=0;i<a.size();i++) cout<<a[i]<<' ';cout<<endl;}
void display2d(vector<vector<ll>> a){for(ll i=0;i<a.size();i++){for(ll j=0;j<a[i].size();j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;}
ll add(vector<int>a){int sum = 0;for(int i=0;i<a.size();i++)sum = sum+a[i];return sum;}
bool isOdd(int n){if(n&1) return true;return false;}
bool isPrime(int n){if (n <= 1)return false;for (int i = 2; i <= n / 2; i++)if (n % i == 0)return false;return true;}
bool isVowel(char a){if(a=='a'||a=='e'||a == 'i'||a=='o'||a=='u'||a=='y'){return true;}return false;}


string checkArrays() {
    long long arraySize;
    cin >> arraySize;
    
    vector<long long> arrayA(arraySize, 0);
    for (int index = 0; index < arraySize; ++index) {
        cin >> arrayA[index];
    }
    
    vector<long long> arrayB(arraySize, 0);
    for (int index = 0; index < arraySize; ++index) {
        cin >> arrayB[index];
    }
    
    long long specialSize;
    cin >> specialSize;
    
    vector<long long> specialArray(specialSize, 0);
    map<long long, long long> specialMap;
    
    for (int index = 0; index < specialSize; ++index) {
        cin >> specialArray[index];
        specialMap[specialArray[index]]++;
    }
    
    bool conditionMet = false;
    
    for (int index = 0; index < arraySize; ++index) {
        if (specialArray[specialSize - 1] == arrayB[index]) {
            conditionMet = true;
        }
        if (arrayA[index] != arrayB[index]) {
            specialMap[arrayB[index]]--;
        }
    }
    
    for (const auto &pair : specialMap) {
        if (pair.second < 0) {
            conditionMet = false;
        }
    }
    
    if (conditionMet) {
        return yes;
    } else {
        return no;
    }
    return yes;
}

int main() {
    ios::sync_with_stdio(false);
    long long testCases;
    cin >> testCases;
    
    while (testCases-- > 0) {
        cout << checkArrays() << "\n";
    }
    
    return 0;
}
