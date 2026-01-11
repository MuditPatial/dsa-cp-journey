#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int E = edges.size();

        vector<vector<int>>dist(n,vector<int>(n,1e8));

        for(int i=0;i<n;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            dist[u][v]=wt;
            dist[v][u]=wt;
        }

        for(int i=0;i<n;i++){
            dist[i][i]=0;
        }

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][k] != 1e8 && dist[k][j] != 1e8) 
                    dist[i][j]= min(dist[i][j] , dist[i][k]+dist[k][j]);
                }
            }
        }


        int ans=n;
        int node=-1;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(dist[i][j] <= distanceThreshold) cnt++;
            }

            if(cnt <= ans){
                ans=cnt;
                node=i;
            }
        }

        
        

        return node;
 
    }
};