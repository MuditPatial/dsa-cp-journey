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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    // cin >> t;

    while (t--) {
        int n,m;
        cin>>n>>m;

        DSU ds(n+1);

        for(int i=0;i<m;i++){
            int x;
            cin>>x;
            vector<int>vec(x);
            for(int j=0;j<x;j++){
                cin>>vec[j];
            }

            for(int i=1;i<x;i++){
                ds.unionBySize(vec[i-1],vec[i]);
            }

        }

        for(int i=1;i<=n;i++){
            int val = ds.sizeX(i);
            cout<<val<<" ";
        }
        cout<<'\n';
    }

    return 0;
}
