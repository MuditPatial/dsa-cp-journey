#include <bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;

        vector<int>a(n);
        int maxx=0;

        for(int i=0;i<n;i++){
            cin>>a[i];
            maxx=max(maxx,a[i]);
        }

        int st=maxx , end=maxx+k;
        int ans =maxx;

        while(st<=end){
            int mid = st + (end-st)/2;
            bool cond=false;

            for(int i=0;i<n;i++){
                int move = k;
                int req=mid;
                int idx=i;

                bool c1=true;
                while(idx<n-1 && req-a[idx] > 0 && move>0){
                    move -= (req-a[idx]);
    
                    idx++;
                    req--;
                    
                }

                if(req <= a[idx] && move>=0){
                    // cout<<req<<" "<<a[idx]<<'\n';
                    ans=mid;
                    cond=true;
                    break;
                }


            }

            if(cond){
                st=mid+1;
            }
            else{
                end=mid-1;
            }
        }

        cout<<ans<<'\n';

        

        
        

    }

    return 0;

}