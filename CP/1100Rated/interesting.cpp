#include <bits/stdc++.h>
using namespace std;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

        int n;
        cin>>n;

        vector<int>a(n);

        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        int q;
        cin>>q;

        vector<pair<int,int>>m(q);

        for(int i=0;i<q;i++){
            cin>>m[i].first;
            m[i].second=i;
        }

        sort(a.begin(),a.end());
        sort(m.begin(),m.end());

        vector<int>ans(q);

        

        int idx=0;

        for(int i=0;i<q;i++){
            while(idx<n && m[i].first>=a[idx]){
                idx++;
            }
            ans[m[i].second]=idx;
        }

        for(int i=0;i<q;i++){
            cout<<ans[i]<<'\n';
        }

        

    return 0;
}

