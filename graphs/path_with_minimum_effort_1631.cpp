#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n= heights.size();
        int m=heights[0].size();
        
        vector<vector<int>>dist(n,vector<int>(m,1e9));

        priority_queue< pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>> >pq; // {dist[i][j],{i,j}} will be stored in this queue
        pq.push({0,{0,0}});
        dist[0][0]=0;

        vector<int>dx={1,0,-1,0} , dy={0,1,0,-1};

        while(!pq.empty()){
            int d = pq.top().first;
            int x= pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if (x == n-1 && y == m-1) return d;

            if(d > dist[x][y]) continue;

            for(int i=0;i<4;i++){
                int nx= dx[i]+x;
                int ny= dy[i]+y;

                if(nx >=0 && nx<n && ny>=0 && ny<m && dist[nx][ny] > max(abs(heights[x][y]-heights[nx][ny]),dist[x][y])){
                    dist[nx][ny]=max(abs(heights[x][y]-heights[nx][ny]),dist[x][y]);

                    pq.push({dist[nx][ny],{nx,ny}});
                }
            }
            
        }

        return dist[n-1][m-1];

    }
};