#include <bits/stdc++.h>
using namespace std;


vector<vector<int>>adj;
vector<int>dp;

void f(int node ,int par){
    dp[node]=1;

    for(auto &x : adj[node]){
        if(x == par) continue;

        f(x,node);
        dp[node] += dp[x];
    }

    
}
int main(){

    
        int n;
        cin>>n;

        adj.assign(n+1,vector<int>(0));
        dp.assign(n+1,0);

        for(int i=0;i<n-1;i++){
            int x,y;
            cin>>x>>y;

            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        if(n%2==1){
            cout<<"-1 \n";
            return 0;
        }

        f(1,1);

        int ans=0;

        for(int i=2;i<=n;i++){
            if(dp[i]%2==0){
                ans++;
            }
        }

        cout<<ans<<'\n';

        

    

    return 0;

}