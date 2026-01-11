#include <bits/stdc++.h>
using namespace std;


int main(){
 
    int t;
    cin>>t;
 
    while(t--){
        int a,b,k;
        cin>>a>>b>>k;

        vector<int>boys(k),girls(k),freqBoys(a+1,0),freqGrils(b+1,0);

        for(int i=0;i<k;i++){
            cin>>boys[i];
            freqBoys[boys[i]]++;
        }

        for(int i=0;i<k;i++){
            cin>>girls[i];
            freqGrils[girls[i]]++;
        }

        long long comb=0;

        for(int i=0;i<k;i++){
            comb += 1LL*(k-1 - (freqBoys[boys[i]] -1 ) - ( freqGrils[girls[i]]-1 ));
        }

        cout<<comb/2<<'\n';


        
    }
    return 0;
}