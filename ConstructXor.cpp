#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n,sum;
    cin >> n>>sum;
    if(n==1){
        cout<<-1<<endl;
        return;
    }
    else if(n%2==0){
        if(sum%2==0){
            if(sum>=n){
                ll divide=sum/n,temp=sum%n;
                for(ll i=0; i<n; i++){
                    if(temp){
                        cout<<divide+1<<" ";
                        temp--;
                    }
                    else{
                        cout<<divide<<" ";
                    }

                }
                cout<<endl;
            }
            
            else{
                cout<<-1<<endl;
                return;
            }

        }
        else{
            cout<<-1<<endl;
            return;
        }
    }
    
    else{
        if(sum%2){
                cout<<-1<<endl;
                return;
        }
        else{   
            if(n>3){
                if(sum>=(n+3)){
                    cout<<1<<" "<<2<<" "<<3<<" ";
                    n-=3;
                    sum-=6;
                    ll divide=sum/n,temp=sum%n;
                    for(ll i=0; i<n; i++){
                        if(temp){
                            cout<<divide+1<<" ";
                            temp--;
                        }
                        else{
                            cout<<divide<<" ";
                        }
                    }
                    cout<<endl;
                }
                else{
                    cout<<-1<<endl;
                    return;
                }
            }
            else{
                if(sum<6 || sum==(1<<((ll)log2(sum)))){
                    cout<<-1<<endl;
                    return;
                }
                else{
                    cout<<sum/2<<" "<<(1<<((ll)log2(sum/2)))<<" "<<(sum/2)-(1<<((ll)log2(sum/2)))<<endl;
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    ll t;cin>>t;
    while(t-->0){
        solve();
    }
    return 0;
}
