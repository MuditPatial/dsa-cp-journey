#include <bits/stdc++.h>
using namespace std;

const int INF = 1e8;

int f(vector<vector<int>>&dp , int i,int turn , vector<int>&vec){
    int n=dp.size();
    
    
    if(i>=n){
        return 0;
    }

    if(dp[i][turn] != INF) return dp[i][turn];

    int taken1=INF,taken2=INF;
    if(turn ==0 ){
        taken1 = vec[i]+f(dp,i+1,1-turn,vec);
        if(i<n-1) taken2 = vec[i]+vec[i+1]+f(dp,i+2,1-turn,vec);
    }
    else{
        taken1 = f(dp,i+1,1-turn,vec);
        if(i<n-1) taken2 = f(dp,i+2,1-turn,vec);
    }

    return dp[i][turn]= min(taken1,taken2);

}
int main(){
    int t;
    cin>>t;

    while(t--){

        int n;
        cin>>n;

        vector<int>vec(n);

        for(int i=0;i<n;i++){
            cin>>vec[i];
        }

        vector<vector<int>>dp(n,vector<int>(2,INF));

        f(dp,0,0,vec);

        int ans = dp[0][0];

        cout<<ans<<'\n';
        
    }





    return 0;
}