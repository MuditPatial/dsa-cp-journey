#include <bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){
        int n,m;
        cin>>n>>m;

        vector<int>a(n),b(n);
        a[0]=1;

        for(int i=1;i<n;i++){
            cin>>a[i];
        }

        for(int i=0;i<n;i++){
            cin>>b[i];
        }

        // point that you may reorder the array any way after using one operation gives us levarage to change the array and for greedy
        // we take the sorted order
        
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());

        

        int i=0,j=0 , aRem=0,bRem=0;

        while(i<n && j<n){
            if(a[i]<b[j]){
                i++;
                j++;
            }
            else{
                j++;
            }
        }

        aRem+= (n-i);
        bRem+=(n-j);

        cout<<max(aRem,bRem)<<'\n';
        
    }
    return 0;
}

