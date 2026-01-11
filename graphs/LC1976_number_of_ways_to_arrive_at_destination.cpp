#include <bits/stdc++.h>
using namespace std;

const int c = 1e9+7;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int E= roads.size();

        vector<vector<pair<int,int>>> adj(n);

        vector<pair<int,long long>>dist(n,{1e18,-1});  // distance,freq

        for(int i=0;i<E;i++){
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }

        priority_queue<pair<long long,long long>, vector<pair<long long,long long>> , greater<pair<long long,long long>> > pq;

        pq.push({0,0});
        dist[0]={0,1};

        while(!pq.empty()){
            int d = pq.top().first;
            int curr= pq.top().second;
            pq.pop();

            if(dist[curr].first < d){
                continue;
            }

            for(auto &[x,y] : adj[curr]){
                if(dist[x].first > d + y){
                    dist[x]= {d+y,dist[curr].second};
                    pq.push({dist[x].first,x});
                }
                else if(dist[x].first == d + y){
                    dist[x].second = (dist[x].second+dist[curr].second)%c;
                }
            }
        }

        return dist[n-1].second ;

        
    }
};