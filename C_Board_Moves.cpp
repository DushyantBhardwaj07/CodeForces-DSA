#include<bits/stdc++.h>
using namespace std;
int main(){
    string s; cin>>s;
    int sum = 0;
    for(int i=0;i<s.length();i++){
        sum = sum + s[i]-'0';
        if(!(sum & 1)){
            cout<<sum<< endl;
            break;
        }
        
    }
    return 0;
}