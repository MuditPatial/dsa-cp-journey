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

    bool unionF(int x ,int y){
        int ulp_x = find(x);
        int ulp_y = find(y);
        
        if(ulp_x == ulp_y ) return false;
        
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
        
        return true;
        
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int E = connections.size();
        if(n-1 > E) return -1;

        DSU ds(n);

        int comp=n;

        for(auto &it : connections){
            if(ds.unionF(it[0],it[1])){
                comp--;
            }
        }

        return comp-1;
    }
};