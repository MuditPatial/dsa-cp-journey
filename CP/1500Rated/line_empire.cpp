#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n,h,l;
        cin>>n>>h>>l;

        vector<int>vec(n);
        int lessH=0,lessL=0;
        if(h<l) swap(h,l);
        for(int i=0;i<n;i++){
            cin>>vec[i];
            if(vec[i]<=h)lessH++;
            if(vec[i]<=l)lessL++;
        }

        if(h==l || lessH == lessL){
            cout<<lessH/2<<'\n';
        }
        else{
            if(lessL < lessH-lessL){
                cout<<lessL<<'\n';
            }
            else{
                cout<<lessH/2<<'\n';
            }
        }

    }
}
