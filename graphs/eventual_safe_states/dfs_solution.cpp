#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

    bool dfs(int node , vector<vector<int>>& adj , vector<int>& vis , vector<int>& pathVis,vector<int>&ans){
        vis[node]=1;
        pathVis[node]=1;

        for(auto &x : adj[node]){
            if(!vis[x]){
                if(dfs(x,adj,vis,pathVis,ans) == false)
                return false;
            }
            else if( pathVis[x]){
                return false;
            }

        }
        pathVis[node]=0;
        ans[node]=1;
        return true;

    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();

        vector<int>vis(n,0),pathVis(n,0),ans(n,0),fAns;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,graph,vis,pathVis,ans);
            }
        }
        for(int i=0;i<n;i++){
            if(ans[i]) fAns.push_back(i);
        }
        return fAns;


    }
};