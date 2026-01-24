#include <bits/stdc++.h>
using namespace std;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin>>n;

        vector<vector<int>>adj(n+1);
        map<pair<int,int>,int>mp;
        mp[{1,1}]=n+1;
        for(int i=0;i<n-1;i++){
            int x,y;
            cin>>x>>y;
            mp[{x,y}]=i;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        vector<int>vis(n+1,0),parent(n+1,-1),when(n+1,-1);

        queue<pair<int,int>>q; //node,when
        q.push({1,0});
        vis[1]=1;
        when[1]=0;
        parent[1]=1;

        while(!q.empty()){
            int curr = q.front().first;
            int w = q.front().second;
            q.pop();

            int sz=adj[curr].size();

            for(int i=0;i<sz;i++){
                int node = adj[curr][i];
                if(vis[node] ==0){
                    pair<int,int>prev,now;
                    if(mp.find({parent[curr],curr})==mp.end()) prev={curr,parent[curr]};
                    else prev={parent[curr],curr};

                    if(mp.find({curr,node})==mp.end()) now={node,curr};
                    else now = {curr,node};

                    if(mp[now]>mp[prev]) when[node]=w;
                    else when[node]=w+1;

                    q.push({node,when[node]});
                    vis[node]=1;
                    parent[node]=curr;
                    
                }
            }
        }

        int ans=0;

        for(int i=1;i<=n;i++){
            ans=max(ans,when[i]);
        }

        cout<<ans<<'\n';

        
    }
}
