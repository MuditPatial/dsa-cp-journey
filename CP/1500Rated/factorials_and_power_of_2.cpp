#include <bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int>a(n);
        set<int>st;
        int num=1e3;
        for(int i=0;i<n;i++){
            cin>>a[i];
            st.insert(a[i]);
            
        }

        for(int i=st.size();i<=1e3;i++){
            if(st.count(i)){
                cout<<i<<'\n';
                break;
            }
        }


    }

    

    return 0;

}