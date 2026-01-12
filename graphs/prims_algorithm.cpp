#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>>adj(V);

        for(auto it : edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

        set<vector<int>>st;
        for(auto &x: adj[0]){
            st.insert({x.second,0,x.first}); //wt,u
        }

        set<int>node;
        node.insert(0);
        
        int ans=0;

        while(node.size() != V){
            vector<int> vec = (*st.begin());
            st.erase((*st.begin()));
            
            if(node.count(vec[1]) && node.count(vec[2])) continue;

            node.insert(vec[2]);

            
            
            ans += vec[0];

            for(auto &[x,y] : adj[vec[2]]){
                if(node.count(x)){
                    continue;
                }
                else{
                    st.insert({y,vec[2],x});
                }
            }
        }
        
        return ans;
    }
};