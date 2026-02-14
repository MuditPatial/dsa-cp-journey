#include <bits/stdc++.h>
using namespace std;

int main(){

    int n , m ,k;
    cin>>n>>m>>k;

    vector<int>a(n),b(m);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    for(int i=0;i<m;i++){
        cin>>b[i];
    }

    vector<int>aGap,bGap;

    int gap=0;

    for(int i=0;i<n;i++){
        if(a[i]==0){
            if(gap>0) aGap.push_back(gap);
            gap=0;
        }
        else gap++;
    }
    if(gap>0) aGap.push_back(gap);
    gap=0;
    for(int i=0;i<m;i++){
        if(b[i]==0){
            if(gap>0) bGap.push_back(gap);
            gap=0;
        }
        else{
            gap++;
        }
    }
    if(gap>0) bGap.push_back(gap);

    vector<pair<int,int>>p;

    for(int i=1;i*i<=k;i++){
        if(k%i==0){
            p.push_back({i,k/i});
            if(i != k/i) p.push_back({k/i,i});
        }
    }

    int sz = p.size();

    sort(aGap.begin() , aGap.end());
    sort(bGap.begin() , bGap.end());

    int aSz = aGap.size();
    int bSz = bGap.size();

    vector<int>suf(bSz+1,0);


    for(int i=bSz-1;i>=0;i--){
        
        suf[i]=suf[i+1]+bGap[i];
        
    }

    long long ans=0;

    for(int i=0;i<aSz;i++){
        for(int j = 0 ;j<sz;j++){
            long long first = 1LL*aGap[i]-p[j].first+1;

            if(first<=0) continue;

            int ind = bSz;
            int val = p[j].second;
            int st =0 , end=bSz-1;

            while(st<=end){
                int mid = st + (end-st)/2;

                if(bGap[mid]>=val){
                    ind = mid;
                    end= mid-1;
                }
                else{
                    st = mid+1;
                }

            }

            long long second = (suf[ind] - 1LL*(bSz-ind)*(val-1));

            if(second<=0) continue;

            ans += 1LL*first*second;
                
  
        }
        
    }

    cout<<ans<<'\n';

    return 0;
}