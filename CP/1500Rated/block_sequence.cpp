#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin>>n;
        
        vector<int>a(n);

        for(int i=0;i<n;i++){
            cin>>a[i];
            
        }

        vector<int>dp(n+1,n);

        dp[n]=0;

        for(int i=n-1;i>=0;i--){
            int taken=n,notTaken=n;
            if(i+a[i] < n){
                taken=dp[i+a[i]+1];
            }
            notTaken=1+dp[i+1];

            dp[i]=min(notTaken,taken);
        }

        cout<<dp[0]<<'\n';


        

    }
}
