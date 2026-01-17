#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int>vec(n);
    map<int,long long>mp;


    for(int i=0;i<n;i++){
        int x;
        cin>>x;

        vec[i]=x-(i+1);
        mp[vec[i]]+= 1LL*x;
    }
    long long maxVal=0;

    for(auto &[x,y] : mp){
        maxVal=max(1LL*maxVal,1LL*y);
    }

    cout<<maxVal<<'\n';

    
}