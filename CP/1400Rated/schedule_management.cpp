#include <bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){
        int n,m;
        cin>>n>>m;

        vector<int>a(m),freq(n+1,0);

        for(int i=0;i<m;i++){
            cin>>a[i];
            freq[a[i]]++;
        }

        sort(freq.begin()+1 , freq.end());

        int st=1, end= 2*m;
        int ans=0;

        while( st <= end ){
            int mid = st + (end-st)/2;
            
            int idx=1;
            long long toAcc=0 , toFill=0;

            while(idx <=n && freq[idx] <= mid){
                toAcc += 1LL*(mid-freq[idx])/2;
                idx++;
            }
            while(idx<=n && freq[idx] > mid){
                toFill += 1LL*(freq[idx] - mid);
                idx++;
            }

            if(toFill <= toAcc){
                end=mid-1;
                ans=mid;
            }
            else{
                st=mid+1;
            }
        }

        cout<<ans<<'\n';
    }
    return 0;
}