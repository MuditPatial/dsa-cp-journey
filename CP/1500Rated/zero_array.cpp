#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

        int n;
        cin>>n;

        vector<int>vec(n);
        long long sum=0;
        for(int i=0;i<n;i++){
            cin>>vec[i];
            sum+= 1LL*vec[i];
        }

        if(sum%2==1){
            cout<<"NO \n";
            
        }

        else{
            sort(vec.begin(),vec.end());
            long long val=0;

            for(int i=0;i<n-1;i++){
                val+=1LL*vec[i];
            }
            if(val < sum/2) cout<<"NO \n";
            else cout<<"YES \n";
        }
        

    
}
