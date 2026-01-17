#include <bits/stdc++.h>
using namespace std;

class DSU{
public:
    vector<int> parent, rank, sz;

    DSU(int n){
        parent.resize(n);
        rank.resize(n,0);
        sz.resize(n,1);

        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }

    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    int sizeX(int x){
        return sz[find(x)];
    }

    bool unionByRank(int x, int y){
        int rx = find(x);
        int ry = find(y);

        if(rx == ry) return false;

        if(rank[rx] > rank[ry]){
            parent[ry] = rx;
            sz[rx] += sz[ry];
        }
        else if(rank[rx] < rank[ry]){
            parent[rx] = ry;
            sz[ry] += sz[rx];
        }
        else{
            parent[rx] = ry;
            rank[ry]++;
            sz[ry] += sz[rx];
        }
        return true;
    }

    bool unionBySize(int x, int y){
        int rx = find(x);
        int ry = find(y);

        if(rx == ry) return false;

        if(sz[rx] > sz[ry]){
            parent[ry] = rx;
            sz[rx] += sz[ry];
        }
        else{
            parent[rx] = ry;
            sz[ry] += sz[rx];
        }
        return true;
    }
};


class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n= accounts.size();

        DSU ds(n+1);

        map<string,int>mp;
        for(int i=0;i<n;i++){
            int sz=accounts[i].size();
            for(int j=1;j<sz;j++){
                if(mp.find(accounts[i][j]) == mp.end() ){
                    mp[accounts[i][j]] =i;
                }
                else{
                    ds.unionBySize(i,mp[accounts[i][j]]);
                }
            }
        }

        vector<string>mails[n];

        for(auto it : mp){
            string mail = it.first;
            int node = ds.find(it.second);
            
            mails[node].push_back(mail);
        }

        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            if(mails[i].size()==0) continue;
            
            sort(mails[i].begin(),mails[i].end());

            vector<string>vec;

            vec.push_back(accounts[i][0]);

            for(auto &x : mails[i]){
                vec.push_back(x);
            }

            ans.push_back(vec);
            
        }

        return ans;
        
            
    }
};