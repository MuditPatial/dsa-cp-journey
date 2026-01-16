#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,k;
    cin>>n>>m>>k;

    vector<int>vec(n);

    for(int i=0;i<n;i++){
        cin>>vec[i];
    }

    vector<int>diff(n-1);

    for(int i=1;i<n;i++){
        diff[i-1]=vec[i]-vec[i-1];
    }

    sort(diff.begin(),diff.end());

    long long sum=k;

    for(int i=0;i<n-k;i++){
        sum += 1LL*diff[i];
    }

    cout<<sum<<'\n';



    return 0;
}
