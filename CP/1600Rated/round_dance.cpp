#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.assign(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);  // path compression
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b)
            return false;  // already connected

        if (size[a] < size[b])
            swap(a, b);

        parent[b] = a;
        size[a] += size[b];

        return true;
    }
    

    int compSize(int x) {
        return size[find(x)];
    }
};


int main(){

    int t;
    cin>>t;
    while(t--){
        int n ;
        cin>>n;

        DSU ds(n+1);

        vector<int>vec(n+1,0);

        for(int i=1;i<=n;i++){
            cin>>vec[i];
        }
        int cnt =0;
        map<pair<int,int>,int>conn;

        for(int i=1;i<=n;i++){
            if(!ds.unite(i,vec[i]) && !conn.count({vec[i],i}) ){
                cnt++;
            }
            else{
                conn[{i,vec[i]}]=1;
            }
        }

        set<int>st;
        for(int i=1;i<=n;i++){
            st.insert(ds.find(i));
        }
    
        int maxx = st.size();

        int minn = min(cnt+1,maxx);

        cout<<minn<<" "<<maxx<<'\n';

    }

    return 0;

}