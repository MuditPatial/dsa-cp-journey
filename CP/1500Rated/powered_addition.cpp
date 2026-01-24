#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int>a(n);

        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        int maxadd=0;

        for(int i=1;i<n;i++){
            if(a[i]<a[i-1]){
                maxadd=max(maxadd,a[i-1]-a[i]);
                a[i]=a[i-1];
            }
        }

        int ans=0;
        while(maxadd>0){
            ans++;
            maxadd/=2;
        }

        cout<<ans<<'\n';
    }



    return 0;
}

