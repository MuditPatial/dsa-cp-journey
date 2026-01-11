#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int E = times.size();

        vector<vector<pair<int,int>>> adj(n+1);
        vector<int>dist(n+1,1e9);

        for(int i=0;i<E;i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>> > pq;

        pq.push({0,k});
        dist[k]=0;

        while(!pq.empty()){
            int d = pq.top().first;
            int curr= pq.top().second;
            pq.pop();

            if(dist[curr] < d){
                continue;
            }

            for(auto &[x,y] : adj[curr]){
                if(dist[x] > d + y){
                    dist[x]= d+y;
                    pq.push({dist[x],x});
                }
            }
        }
        int maxNum=-1;

        for(int i=1;i<=n;i++){
            if(dist[i]== 1e9){
                return -1;
            }
            else{
                maxNum=max(maxNum,dist[i]);
            }
        }

        return maxNum;

    }
};