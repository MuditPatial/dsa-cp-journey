#include <bits/stdc++.h>
using namespace std;

const int c= 1e5;

class Solution {
  public:
    
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        
        int n=arr.size();

        vector<int>dist(c,1e8); // considering every number till 10^5 as a node and steps as distance 

        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>> > pq;

        pq.push({0,start});

        dist[start]=0;

        while(!pq.empty()){
            
            int node = pq.top().second;
            int steps= pq.top().first;
            pq.pop();
            
            if(steps > dist[node]) continue;
            if(node==end) return dist[node];

            for(int i=0;i<n;i++){
                int val = (node*arr[i])%c;
                if(dist[val] > steps+1){
                    dist[val] = steps+1;
                    pq.push({steps+1,val});
                    
                }
            }
        }
        
        return -1;

    }
};
