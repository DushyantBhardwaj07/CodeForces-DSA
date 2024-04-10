#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll solve(){
    ll a,b; cin>>a>>b;
    if(b<a) swap(a,b);
    ll gcd = __gcd(a,b);    
    ll temp1 = a/gcd;
    ll temp2 = b/gcd;
    bool flag1 = 0, flag2 = 0;
    ll ans = 0;
    while(temp1 != temp2){
        if(temp1 % 5 == 0){
            temp1 = temp1/5;
            ans++;
        }
        else if(temp1 % 3 == 0){
            temp1 = temp1/3;
            ans++;
        }
        else if(temp1 % 2 == 0){
            temp1 = temp1/2;
            ans++;
        }
        else{
            flag1 = 1;
        }

        if(temp2 % 5 == 0){
            temp2 = temp2/5;
            ans++;
        }
        else if(temp2 % 3 == 0){
            temp2 = temp2/3;
            ans++;
        }
        else if(temp2 % 2 == 0){
            temp2 = temp2/2;
            ans++;
        }
        else{
            flag2 = 1;
        }
        
        if(flag1 && flag2){
            return -1;
        }
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cout<<solve()<<endl;
    return 0;
}