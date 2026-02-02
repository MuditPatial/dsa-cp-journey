#include <bits/stdc++.h>
using namespace std;


int main(){

    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;

        string s;
        cin>>s;

        vector<int>check(k,2);
        bool cond=true;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                if(check[i%k]==0){
                    cond=false;
                    break;
                }
                check[i%k]=1;
                
            }
            else if(s[i]=='0'){
                if(check[i%k]==1){
                    cond=false;
                    break;
                }
                check[i%k]=0;
            }
        }
        int f1=0,f0=0;
        for(int i=0;i<k;i++){
            if(check[i]==0) f0++;
            if(check[i]==1) f1++;
        }

        if(!cond || f1>k/2 || f0>k/2){
            cout<<"NO \n";
        }
        else{
            cout<<"YES \n";
        }



    }

    return 0;

}