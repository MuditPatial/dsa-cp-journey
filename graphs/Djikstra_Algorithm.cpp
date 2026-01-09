// using Priority Queue

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>>adj(V);  // pair<dist,node>
        vector<int>dist(V,1e9);

        int E= edges.size();

        for(int i=0;i<E;i++){
            adj[edges[i][0]].push_back({edges[i][2],edges[i][1]});
            adj[edges[i][1]].push_back({edges[i][2],edges[i][0]});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,src});
        dist[src]=0;

        while(!pq.empty()){
            pair<int,int>curr = pq.top();
            pq.pop();

            int d=curr.first;
            int u= curr.second;

            if(d> dist[u]){
                continue;
            }

            for(auto &x : adj[u]){
                if(dist[x.second] > d+x.first){
                    dist[x.second]=d+x.first;
                    pq.push({dist[x.second],x.second});
                }
            }
        }

        return dist;


    }
};



// Using Set Data Structure

