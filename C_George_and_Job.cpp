#include<bits/stdc++.h>
using namespace std;
#define yes "YES"
#define no "NO"
#define ll long long
#define mod 1000000007

ll dp[5005][5005];
ll sum[5005];

int main() {
    // your code goes here
    ll n,m,k,i,j,size,ki;
    cin>>n>>m>>ki;
    size=m;

    ll a[n+2];
     
     if(m==1)
     {
     	for(i=0;i<n;i++)
         cin>>a[i];
         
         sort(a,a+n);
         if(ki==1){
         cout<<a[n-1]<<endl;
         return 0;
        }
       // sort(a,a+n);
        ll s=0;
        //a[0]=0;
        //for(i=n;i>=n-ki+1;i--)
         //cout<<a[i]<<" ";
         
        for(i=n-1;i>=n-ki;i--)
         s+=a[i];
         
         cout<<s<<endl;
         return 0;
     }
     
     for(i=1;i<=n;i++)
     cin>>a[i];
  
     for(i=1;i<size;i++)
      sum[i]=a[i];
      
     for(i=1;i<=size;i++)
      {
      	sum[size]+=a[i];
      }
      
    //  cout<<sum[2]<<" ";
      
    for(i=size+1;i<=n;i++)
    {
        sum[i]+= sum[i-1]- a[i-size]+ a[i];
     // cout<<sum[i]<<" ";
    }
   // cout<<endl;
    
    for(i=0;i<=5002;i++)
    {
        for(j=0;j<=5002;j++)
         dp[i][j]=0;
    }
    
    for(j=1;j<=n;j++)
     dp[1][j]= max(sum[j], dp[1][j-1]);
    
    for(k=2;k<=ki;k++)
    {
        for(j=1;j<=n;j++)
        {
            if(j-size>=size)
            dp[k][j]= max(dp[k-1][j-size]+sum[j],dp[k][j-1]);
        }
    }
    /*
    for(i=1;i<=ki;i++)
    {
        for(j=1;j<=n;j++)
         cout<<dp[i][j]<<" ";
         cout<<endl;
    }
    */
    cout<<dp[ki][n]<<endl;
    return 0;
}x  