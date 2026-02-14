#include <bits/stdc++.h>
using namespace std;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

        
        int n , m;
        cin>>n>>m;

        vector<vector<int>>adj(n+1);

        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            if(x!=y){
                adj[x].push_back(y);
                adj[y].push_back(x);
            }
        }

        for(int i=1;i<=n;i++){
            sort(adj[i].begin() , adj[i].end());
        }

        vector<int>ans , vis(n+1,0);

        priority_queue<int , vector<int> , greater<int>>q;

        q.push(1);

        vis[1]=1;
        while(!q.empty()){
            int curr = q.top();
            q.pop();

            ans.push_back(curr);

            for(auto &x : adj[curr]){
                if(!vis[x]){
                    vis[x]=1;
                    q.push(x);
                }
            }
        }
        for(auto &x : ans){
            cout<<x<<" ";
        }
        cout<<'\n';

    return 0;
}

