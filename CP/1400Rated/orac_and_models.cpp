#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin>>n;

        vector<int>hash(n+1,0);
        vector<pair<int,int>> pr(n);
        vector<int>val(n+1);

        for(int i=0;i<n;i++){
            cin>>pr[i].first;
            pr[i].second=i+1;
            val[i+1]=pr[i].first;
        }

        sort(pr.begin(),pr.end());

        int globalMax=1;

        for(int i=0;i<n;i++){

            int localMax=1;

            int num = pr[i].second;

            for(int j=1;j*j<=num;j++){
                if(num % j == 0){
                    // cout<<num<<" "<<j<<" "<<hash[j]<<" "<<hash[n/j]<<" "<<'\n';
                    if(val[num] > val[j]) localMax=max(localMax,hash[j]+1);
                    if(val[num] > val[num/j]) localMax=max(localMax,hash[num/j]+1);
                    // cout<<"local maxima   "<<localMax<<'\n';
                }
            }
            hash[num]=localMax;
            globalMax=max(globalMax,hash[num]);
            // cout<<"global   "<<globalMax<<" \n";
        }


        cout<<globalMax<<'\n';

    }

    return 0;
}
