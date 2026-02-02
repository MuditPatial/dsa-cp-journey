#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;

    vector<int>a(n),b(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    for(int i=0;i<n;i++){
        cin>>b[i];
    }

    map<pair<int,int>,int>mp;
    int ans=0,bias=0;
    for(int i=0;i<n;i++){
        if(a[i]==0){
            if(b[i]==0){
                bias++;
            }
        }
        else if(b[i]==0){
            mp[{0,1}]++;
        }
        else {
            int x = gcd(a[i],b[i]);
            int A = a[i] /x;
            int B= b[i] /x;

            if(B<0){
                A=-A;
                B=-B;
            }
            mp[{A,B}]++;
        }
    }

    for(auto &[x,y]:mp){
        ans=max(ans,y);
    }

    cout<<ans+bias<<'\n';

    return 0;
}