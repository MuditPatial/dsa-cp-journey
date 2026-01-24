#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    vector<int>vec(n);

    int gcdAll=0;

    for(int i=0;i<n;i++){
        cin>>vec[i];
        gcdAll=gcd(gcdAll,vec[i]);
    }
    

    if(gcdAll !=1){
        cout<<"-1 \n";
    }
    else {
        
    }
        
        

    
}
