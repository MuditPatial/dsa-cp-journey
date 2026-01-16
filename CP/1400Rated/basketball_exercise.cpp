#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    cin>>n;
 
    vector<vector<int>>a(2,vector<int>(n));
 
    for(int i=0;i<n;i++){
        cin>>a[0][i];
    }
 
    for(int i=0;i<n;i++){
        cin>>a[1][i];
    }
 
    vector<vector<long long>>dp(2,vector<long long>(n,0));

    dp[0][0]=a[0][0];
    dp[1][0]=a[1][0];
 
    for(int i=1;i<n;i++){
        dp[0][i]=max(dp[0][i-1],1LL*a[0][i]+dp[1][i-1]);
        dp[1][i]=max(dp[1][i-1],1LL*a[1][i]+dp[0][i-1]);
    }
 
    cout<<max(dp[0][n-1],dp[1][n-1])<<endl;
 
    return 0;
}