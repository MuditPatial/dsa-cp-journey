#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

// Ordered set supporting order statistics (order_of_key, find_by_order)
#define Oset tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin>>n;
        
        vector<pair<int,int>>vec(n);

        for(int i=0;i<n;i++){
            cin>>vec[i].first>>vec[i].second;
        }
        sort(vec.begin(),vec.end());

        Oset st;
        long long ans=0;

        for(int i=0;i<n;i++){
            ans += 1LL*i- st.order_of_key(vec[i].second);
            st.insert(vec[i].second);
        }

        cout<<" " <<ans<<'\n';
        
        


    }
}
