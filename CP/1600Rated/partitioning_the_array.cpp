#include <bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        vector<int>a(n);

        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        vector<int>fact;

        for(int i=1;i*i<=n;i++){
            if(n%i == 0){
                fact.push_back(i);
                if(i != n/i) fact.push_back(n/i);
            }
        }
        
        int ans=0;

        for( auto k : fact){
            int g=0;
            for(int i=k;i<n;i++){
                g=gcd(g, abs(a[i] -a[i-k]));
            }

            if(g != 1) ans++;
        }

        cout<<ans<<'\n';

        
        

    }

    return 0;

}