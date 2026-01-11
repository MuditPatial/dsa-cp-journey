#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int E= flights.size();

        vector<vector<pair<int,int>>>adj(n);
        vector<vector<int>>cost(n,vector<int>(k+1,1e8));

        for(int i=0;i<E;i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }

        priority_queue<
        pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>> >pq;  // cost,stops,node

        pq.push({0,{0,src}});
        cost[src][0]=0;

        while(!pq.empty()){
            int c = pq.top().first;
            int stops= pq.top().second.first;
            int curr = pq.top().second.second;

            pq.pop();

            if(stops > k) continue;
            if(c > cost[curr][stops]) continue;

            for(auto &[x,y] : adj[curr]){
                if(cost[x][stops+1] > (c+y)){
                    cost[x][stops+1] = c+y;
                    pq.push({cost[x][stops+1],{stops+1,x}});
                }
            }
        }
        int ans=1e8;
        for(int i=0;i<k;i++){
            ans=min(ans,cost[dst][i]);
        }

        return (ans != 1e9)? ans:-1;        
        

    }
};