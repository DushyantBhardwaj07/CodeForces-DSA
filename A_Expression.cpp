#include<bits/stdc++.h>
using namespace std;

long long solve(){
    long long x,y,z; cin>>x>>y>>z;
    long long ans1=x+(y*z);
    long long ans2=x*(y+z);
    long long ans3=x*y*z;
    long long ans4=(x+y)*z;
    long long ans5=(x+y+z);
    long long ans6=(x*y)+z;
    return max({ans1,ans2,ans3,ans4,ans5,ans6});
}

int main(){
    cout<<solve()<<endl;
    return 0;
}