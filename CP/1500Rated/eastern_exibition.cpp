#include <bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int>x(n),y(n);

        for(int i=0;i<n;i++){
            cin>>x[i]>>y[i];
        }
        if(n%2==1){
            cout<<"1 \n";
            continue;
        }
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());

        int val=n/2;

        long long xSide = x[n/2]-x[n/2 -1 ]+1;
        long long ySide = y[n/2]-y[n/2 - 1]+1;

        long long ans = xSide*ySide;

        cout<<ans<<'\n';

        


    }

    

    return 0;

}