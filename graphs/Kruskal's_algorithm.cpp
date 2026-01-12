#include <bits/stdc++.h>
using namespace std;


class DSU{
    public:
    vector<int>parent,rank;
    DSU(int n){
        parent.resize(n),rank.resize(n,0);
        
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        
    }
    
    int find( int x){
        if(parent[x] == x) return x;
        
        return parent[x] = find(parent[x]);
    }

    void unionF(int x ,int y){
        int ulp_x = find(x);
        int ulp_y = find(y);
        
        if(ulp_x == ulp_y ) return ;
        
        if(rank[ulp_x] > rank[ulp_y]){
            parent[ulp_y] = ulp_x;
        }
        else if(rank[ulp_x] < rank[ulp_y]){
            parent[ulp_x] = ulp_y;
        }
        else{
            parent[ulp_x] = ulp_y;
            rank[ulp_y]++;
        }
        
        return;
        
    }
};

class Solution {
  public:
    
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        DSU ds(V);
        int ans=0;
        
        set<vector<int>> st;
        

        for(auto &it : edges){
            reverse(it.begin(),it.end());
            st.insert(it);
        }
        
        while(!st.empty()){
            vector<int>curr = (*st.begin());
            
            st.erase((*st.begin()));
            
            int u = curr[2];
            int v = curr[1];
            int wt = curr[0];
            
            if(ds.find(u) != ds.find(v)){
                ans+= wt;
                
                ds.unionF(u,v);
            }
            
        }
        return ans;
    }
};