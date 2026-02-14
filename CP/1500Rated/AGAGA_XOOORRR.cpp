#include <bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
        int n ;
        cin>>n;

        vector<int>a(n);
        int xAll=0;

        for(int i=0;i<n;i++){
            cin>>a[i];
            xAll^=a[i];
        }

        if(xAll ==0){
            cout<<"YES \n";
            continue;
        }

        int x=0;
        int idx=-1;
        int cnt=0;
        bool cond =false;
        vector<int>pref(n+1,0);
        
        for(int i=1;i<=n;i++){
            pref[i]=pref[i-1]^a[i-1];
        }

        for(int i=0;i<n;i++){
            x^=a[i];
            if(x==xAll && (pref[n]^pref[i+1]) == xAll){
                cout<<"YES \n";
                cond=true;
                break;
            }
            else if(x==xAll){
                cnt++;
                idx=i;
                x=0;
            }
        }

        if(!cond) cout<<"NO \n";
        

    }

    return 0;

}