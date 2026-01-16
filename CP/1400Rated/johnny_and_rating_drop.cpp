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
        
        vector<int>a(n);

        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        if(n==1){
            cout<<"0 \n";
            continue;
        }

        int b1=a[0],b2=a[1];
        int penalty=0;
        for(int i=2;i<n;i++){
            if(b1>b2){
                if(a[i]>b2){
                    penalty++;
                    cout<<a[i]<<"    penalty up  "<<penalty<<'\n';
                }
                b2=a[i];
            }
            else{
                if(a[i]>b1){
                    penalty++;
                    cout<< a[i]<<"   penalty down  "<<penalty<<'\n';
                }
                b1=a[i];
            }
        }
        cout<<penalty<<'\n';
    }

    return 0;
}
