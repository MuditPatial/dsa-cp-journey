#include <bits/stdc++.h>
using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        int n ;
        cin>>n;

        vector<int>a(n),b(n);

        for(int i=0;i<n;i++){
            cin>>a[i]>>b[i];
        }

        int l=0,r=n;
        int ans=0;

        while(l<=r){
            int m = l+(r-l)/2;
            int cnt=0;
            for(int i=0;i<n;i++){
                if(b[i]>=cnt && a[i]>=(m-cnt-1)){
                    cnt++;
                }
            }

            if(cnt>=m){
                ans=m;
                l=m+1;
            }
            else{
                r=m-1;
            }
        }

        cout<<ans<<'\n';

    }

    return 0;
}