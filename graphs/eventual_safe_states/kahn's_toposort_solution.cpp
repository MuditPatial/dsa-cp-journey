#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int>kahnAlgo(vector<int>&ans , vector<vector<int>>&adj ){
        int n= adj.size();

        vector<int>inDeg(n,0) ;

        queue<int>q;

        for(int i=0;i<n;i++){
            for( auto &x: adj[i]){
                inDeg[x]++;
            }
        }

        for(int i=0;i<n;i++){
            if(inDeg[i]==0){
                q.push(i);

            }
        }

        while(!q.empty()){
            int curr = q.front();
            ans.push_back(curr);
            q.pop();

            for(auto &x : adj[curr]){
                inDeg[x]--;
                if(inDeg[x]==0){
                    q.push(x);
                }
            }
        }

        return ans;
        

    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();

        vector<vector<int>>adj(n);

        for(int i=0;i<n;i++){
            for(auto &x : graph[i]){
                adj[x].push_back(i);
            }
        }

        vector<int>ans;

        kahnAlgo(ans,adj);
        sort(ans.begin(),ans.end());
        
        return ans;


    }
};