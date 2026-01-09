#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m= grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));

        queue<pair<int,pair<int,int>>>q;

        if(grid[0][0] != 0 || grid[n-1][m-1] !=0) return -1;

        q.push({1,{0,0}});
        vis[0][0]=1;


        vector<int> dx = {1,1,1,0,0,-1,-1,-1};
        vector<int> dy = {0,1,-1,1,-1,-1,0,1};

        while(!q.empty()){
            int d = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();

            if(x ==n-1 && y == m-1) return d;

            for(int i=0;i<8;i++){
                int nx = dx[i]+x;
                int ny = dy[i]+y;
                
                if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny] && grid[nx][ny]==0){
                    
                    q.push({d+1,{nx,ny}});
                    vis[nx][ny]=1;

                }
            }

        }  
        return -1;      

    }
};