#include <bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int>l(n),r(n);
        int maxNum=0;

        for(int i=0;i<n;i++){
            cin>>l[i]>>r[i];
            maxNum=max(maxNum,r[i]);
        }

        int low=0, high=maxNum;
        int ans=maxNum;

        while(low<=high){
            int mid = low + (high-low)/2;
            int cBack=0 , cFront=0;
            bool cond=true;
            for(int i=0;i<n;i++){
                int lowRange=cBack-mid , highRange=cFront+mid;
                if(r[i] < lowRange || l[i] > highRange){
                    cond=false;
                    break;
                }

                // most important part as this updation gives us the valid bound 
                cBack=max(cBack-mid , l[i]); // we can go back till cback-mid ,max step taken to back is mid or l[i] if it comes before that
                cFront=min(r[i],cFront+mid); // similar logic to upper updation
            }
            if(cond){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

        cout<<ans<<'\n';

        
    }
    return 0;
}

