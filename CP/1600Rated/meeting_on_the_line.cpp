#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int>tm(n),x(n);

        for(int i=0;i<n;i++){
            cin>>x[i];
        }

        for(int i=0;i<n;i++){
            cin>>tm[i];
        }

        double low=0,high=1e9;
        double ans=0;

        for(int it=0; it<100; it++){
            
            double mid=low+(high-low)/2;

            double L=0,R=1e8;

            for(int i=0;i<n;i++){

                double rem=max(0.0, mid-tm[i]); // person may stand on that point itself do that point is exceptable even tm[i] exceeds

                double ll=x[i]-rem;
                double ul=x[i]+rem;
                    
                L=max(L,ll);
                R=min(R,ul);
            }

            if(L<=R){
                ans=(L+R)/2;
                high=mid;
            }
            else{
                low=mid;
            }
        }

        cout<<fixed<<setprecision(10)<<ans<<'\n';
    }

    return 0;
}