#include <bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        int ans=0;
        vector<int>vec(n),preXor(n+1,0);
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            vec[i]=x;
            
        }
        for(int i=1;i<=n;i++){
            preXor[i]=preXor[i-1]^vec[i-1];
        }
        if(preXor[n]==0){
            cout<<"YES \n";
            continue;
        }
        bool cond =false;
        for(int i=0;i<n;i++){
            int st=i,end=i;
            while(end<n && vec[st]==vec[end]){
                end++;
            }
            int x1 = preXor[st];
            int x2 = preXor[n]^preXor[end];
            int x3 = vec[st];

            

            if( (st==0 && end==n) || (x1==x2 && x2==x3)){
                cout<<"YES \n";
                cond=true;
                break;
            }
            
            i=end;
        }
        if(!cond) cout<<"NO \n";
        

    }

    return 0;

}