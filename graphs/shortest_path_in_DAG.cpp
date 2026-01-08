#include <bits/stdc++.h>
using namespace std;

// User function Template for C++
void dfs(int node , vector<vector<pair<int,int>>>&adj , vector<int>&vis , stack<int>&st){
    vis[node]=1;

    for(auto &x : adj[node]){
        if(!vis[x.first]){
    
            dfs(x.first,adj,vis,st);
        }
    }
    st.push(node);
    return ;

}
class Solution {
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>>adj(V);

        for(int i=0;i<E;i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }

        vector<int>vis(V,0),dist(V,1e9);

        stack<int>st;

        dfs(0,adj,vis,st);
        dist[0]=0;

        while(!st.empty()){
            int curr = st.top();
            st.pop();

            for(auto &[x,y] : adj[curr]){
                dist[x] = min(dist[x] , dist[curr]+y);
            }
        }

        for(int i=0;i<V;i++){
            if(dist[i]==1e9){
                dist[i]=-1;
            }
        }

        return dist;

        

        

        return dist;
    }
};
