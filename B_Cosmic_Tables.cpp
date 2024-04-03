#include<iostream>
#include<vector>
#include<map>
using namespace std;
#define yes "YES"
#define no "NO"
#define ll long long

void swapCol(vector<vector<ll>> &v, ll col1, ll col2){
    for(int i=0;i<v.size();i++){
        swap(v[i][col1], v[i][col2]);
    }
}

void swapRow(vector<vector<ll>> &v, ll row1, ll row2){
    for(int i=0;i<v[0].size();i++){
        swap(v[row1][i], v[row2][i]);
    }
}



void solve(){
    ll n, m, k; cin>>n>>m>>k;
    vector<vector<ll>>v(n, vector<ll>(m, 0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    char op;
    ll a, b;

    vector<ll> row(n+1, 0);
    vector<ll> col(m+1, 0);

    for(int i=0;i<n;i++) row[i+1] = i+1;
    for(int i=0;i<m;i++) col[i+1] = i+1;

    for(int i=0;i<k;i++){
        cin>>op>>a>>b;
        if(op == 'g'){
            cout<<v[row[a]-1][col[b]-1]<<"\n";
        }
        else if(op == 'r'){
            swap(row[a], row[b]);
        }

        else if(op == 'c'){
            swap(col[a], col[b]);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}