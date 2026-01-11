#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        int E=edges.size();


        vector<int>dist(V,1e8);

        dist[src]=0;

        for(int i=0;i<V-1;i++){
            for(int i=0;i<E;i++){
                int u = edges[i][0];
                int v= edges[i][1];
                int wt = edges[i][2];

                if(dist[u] != 1e8 && dist[v] > dist[u]+wt){
                    dist[v]=dist[u]+wt;
                }
            }
        }

        for(int i=0;i<E;i++){
                int u = edges[i][0];
                int v= edges[i][1];
                int wt = edges[i][2];

                if(dist[u] != 1e8 && dist[v] > dist[u]+wt){
                    return {-1};
                }
        }

        

        return dist;
        
        
    }
};
