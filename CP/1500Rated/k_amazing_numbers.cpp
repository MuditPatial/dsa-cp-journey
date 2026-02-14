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

        vector<int>vec(n);

        for(int i=0;i<n;i++){
            cin>>vec[i];
        }

        vector<pair<int,int>> lastOcc(n+1,{-1,0});

        for(int i=0;i<n;i++){
            int num = vec[i];

            int last=lastOcc[num].first;
            int diff = lastOcc[num].second;

            lastOcc[num] = {i,max(i-last,diff)};
        }

        vector<int>ans(n+1,-1);
        int ind = n;
        for(int i=1;i<=n;i++){
            
            if(lastOcc[i].first != -1){
                int diff = max(lastOcc[i].second , n-lastOcc[i].first);
                while(ind >=0 && ind >= diff){
                    ans[ind]=i;
                    ind--;
                }
                
            }
        }


        for(int i=1;i<=n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<'\n';

    }



    return 0;
}

