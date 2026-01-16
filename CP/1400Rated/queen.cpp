#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    vector<int>parent(n+1,-1),respect(n+1),ans;
    int root=-1;
    vector<vector<int>>adj(n+1);

    for(int i=1;i<=n;i++){
        int p,r;
        cin>>p>>r;

        if(p == -1){
            root=i;
        }
        else{
            adj[p].push_back(i);
            parent[i]=p;
        }
        respect[i]=r;
    }

    for(int i=1;i<=n;i++){
        if(i != root && respect[i]==1){
            bool cond=true;
            for(auto &x : adj[i]){
                if(respect[x]==0) cond=false;
            }
            if(cond){
                int req = parent[i];
                ans.push_back(i);
                
            }
        }
    }

    for(auto &x : ans){
        cout<<x<<" ";
    }
    if(ans.size()==0) cout<<"-1";
    cout<<'\n';

    return 0;
}
