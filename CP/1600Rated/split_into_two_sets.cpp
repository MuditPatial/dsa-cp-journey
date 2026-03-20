#include <bits/stdc++.h>
using namespace std;

void dfs(int x , vector<vector<int>>&gAdj , vector<int>&col , bool &pos){
    
    if (!pos) return;

    for (auto y : gAdj[x]){

        if (col[y] != -1){

            if (col[y] == col[x]){
                pos = false;
                return;
            }
            continue;
        }

        col[y] = 1 - col[x];
        dfs(y, gAdj, col, pos);
    }
}

int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        vector<vector<int>> adj(n+1);
        vector<pair<int,int>> dom(n);

        for(int i=0;i<n;i++){
            cin >> dom[i].first >> dom[i].second;

            adj[dom[i].first].push_back(i+1);
            adj[dom[i].second].push_back(i+1);
        }

        bool cond = true;

        vector<vector<int>> gAdj(n+1);

        for(int i=1;i<=n;i++){

            if(adj[i].size()>2){
                cond=false;
                break;
            }

            if(adj[i].size()==2){

                int a = adj[i][0];
                int b = adj[i][1];

                gAdj[a].push_back(b);
                gAdj[b].push_back(a);
            }
        }

        if(!cond){
            cout << "NO\n";
            continue;
        }

        vector<int> col(n+1,-1);

        for(int i=1;i<=n && cond;i++){

            if(col[i] != -1) continue;

            col[i] = 0;
            dfs(i, gAdj, col, cond);
        }

        cout << (cond ? "YES\n" : "NO\n");
    }

    return 0;
}