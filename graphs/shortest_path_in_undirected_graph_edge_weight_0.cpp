#include <bits/stdc++.h>
using namespace std;



class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        // code here
        int n=edges.size();

        vector<vector<int>>adj(V);

        for(int i=0;i<n;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int>vis(V,0),dist(V,-1);

        if(src>=V || src<0) return dist;
        
        queue<pair<int,int>>q;

        q.push({src,0});
        vis[src]=1;
        dist[src]=0;

        while(!q.empty()){
            int curr=q.front().first;
            int level = q.front().second;
            dist[curr]=level;
            q.pop();

            for(auto &x : adj[curr]){
                if(!vis[x]){
                    vis[x]=1;
                    q.push({x,level+1});
                }
            }
        }
        return dist;

    }
};
