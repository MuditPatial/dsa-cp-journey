#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    vector<int>a(n),b(n);

    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    int st=0;
    bool ok=true;

    for(int i=0;i<n;i++){
        while(st<n && a[st]<=b[i]){
            st++;
        }
        if(st-i >2){
            ok=false;
            break;
        }

    }

    cout<<((ok)?"YES \n":"NO \n");

    
        
        

    
}
