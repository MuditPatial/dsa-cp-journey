#include <bits/stdc++.h>
using namespace std;
 
int main(){
 
    int t;
    cin>>t;
 
    while(t--){
        int n,k;
        cin>>n>>k;
 
        vector<int>a(n);
 
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
 
        int l=0,r=1;
        int cnt=0;
 
        while(l<n && r<n){
            if(a[r-1] >= 2*a[r]){
                l=r;
            }
            int len = r-l+1;
 
            if(len >k) cnt++;
 
            r++;
        }
 
        cout<<cnt<<'\n';
        
    }
    return 0;
}