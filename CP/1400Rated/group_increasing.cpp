#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);

        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int b1=0,b2=0,cnt=0;
        b1=a[n-1];

        for(int i=n-2;i>=0;i--){
            if(b1<b2) swap(b1,b2);

            if(a[i]<b2){
                cnt++;
                b2=a[i];
                
            }
            else if(a[i]<b1){
                b2=a[i];
            }
            else{
                b1=a[i];
            }
            
        }

        cout<<cnt<<'\n';
    }
}
