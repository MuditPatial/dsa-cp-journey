#include <bits/stdc++.h>
using namespace std;


class DSU{
    public:
    vector<int>parent,rank,sz;
    DSU(int n){
        parent.resize(n),rank.resize(n,1),sz.resize(n,1);
        
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        
    }

    int sizeX(int x){
        return sz[x];
    }
    
    int find( int x){
        if(parent[x] == x) return x;
        
        return parent[x] = find(parent[x]);
    }

    bool unionByRank(int x ,int y){
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

    bool unionBySize(int x , int y){
        int ulp_x = find(x);
        int ulp_y = find(y);
        
        if(ulp_x == ulp_y ) return false;
        
        if(sz[ulp_x] > sz[ulp_y]){
            sz[ulp_x]+= sz[ulp_y];
            parent[ulp_y] = ulp_x;
            
        }
        else if(sz[ulp_x] < sz[ulp_y]){
            sz[ulp_y]+= sz[ulp_x];
            parent[ulp_x] = ulp_y;
        }
        else{
            sz[ulp_y]+= sz[ulp_x];
            parent[ulp_x] = ulp_y;
        }
        
        return true;
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxRow=0;
        int maxCol=0;

        for(auto &it : stones){
            maxRow=max(maxRow,it[0]);
            maxCol=max(maxCol,it[1]);
        }

        int n=maxRow+maxCol+2;
        
        DSU ds(n);
        int cnt=0;
        for(auto &x: stones){
            if(ds.unionByRank(x[0],x[1]+maxRow+1)){

            }
        }

        map<int,int>stoneNodes;
        for(auto it : stones){
            if(ds.find(it[0]) == it[0]) {
                stoneNodes[it[0]]=1;
            }
                
            if(ds.find(it[1]+maxRow+1)== (it[1]+maxRow+1)) {
                stoneNodes[it[1]+maxRow+1]=1;
            }
        }

        for(auto &x : stoneNodes){
            if(ds.find(x.first)==x.first) cnt++;
        }

        return stones.size() -cnt;


    }
};