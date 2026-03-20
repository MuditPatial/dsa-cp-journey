#include <bits/stdc++.h>
using namespace std;



int main(){

    int t;
    cin>>t;
    vector<int>cost(1000+1,1e8);

    cost[1]=0;
    for(int i=1;i<=1000;i++){
        for(int j=1;j<=i;j++){
            int val = i + i/j;
            if(val <= 1000){
                cost[val]=min(cost[val],cost[i]+1);
            }
        }
    }

    while(t--){
        int n,k;
        cin>>n>>k;

        vector<int>b(n),c(n);

        for(int i=0;i<n;i++){
            cin>>b[i];
        }

        for(int i=0;i<n;i++){
            cin>>c[i];
        }
        
        k =min(12000,k);

        vector<vector<int>>dp(n,vector<int>(k+1,0));
        for(int i=cost[b[0]];i<=k;i++){
            dp[0][i]=c[0];
        }

        for(int i=1;i<n;i++){
            int w = cost[b[i]];
            int val = c[i];

            for(int j=0;j<=k;j++){
                dp[i][j]=dp[i-1][j];
                if(j>=w) dp[i][j]=max(dp[i-1][j],val+dp[i-1][j-w]);
            }
        }

        int ans=0;

        for(int i=0;i<=k;i++){
            ans=max(ans,dp[n-1][i]);
        }

        cout<<ans<<'\n';
   

    }

    

    return 0;

}