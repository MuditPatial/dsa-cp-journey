#include <bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){
        
        int n,m;
        cin>>n>>m;

        vector<int>l(m),r(m);

        for(int i=0;i<m;i++){
            cin>>l[i]>>r[i];
            l[i]--;
            r[i]--;
        }

        int q;
        cin>>q;

        vector<int>query(q);

        for(int i=0;i<q;i++){
            cin>>query[i];
            query[i]--;
        }


        int st=0 , end=q-1;

        int ans = -1;

        while(st<=end){
            int mid = st + (end-st)/2;

            vector<int>vec(n,0),pref(n+1,0);

            for(int i=0;i<=mid ;i++){
                vec[query[i]]=1;
            }

            for(int i=1;i<=n;i++){
                pref[i]=pref[i-1]+vec[i-1];
            }

            bool cond = false;

            for(int i=0;i<m;i++){
                int val = pref[r[i]+1] - pref[l[i]];
                int len = (r[i]-l[i]+1);

                if(2*val > len){
                    ans=mid;
                    end=mid-1;
                    cond=true;
                    break;
                }
            }
            if(!cond){
                st=mid+1;
            }

        }
        ans= (ans==-1)?ans:ans+1;

        cout<<ans<<'\n';

    }

    

    return 0;

}