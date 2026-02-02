#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,q;
    cin>>n>>q;

    vector<int>a(n),l(q),r(q);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<long long>freq(n,0);

    for(int i=0;i<q;i++){
        cin>>l[i]>>r[i];
        freq[l[i]-1]++;
        if(r[i]<n) freq[r[i]]--;
    }

    long long sum=0;

    for(int i=0;i<n;i++){
        sum+=1LL*freq[i];
        freq[i]=sum;
    }

    sort(a.begin(),a.end());
    sort(freq.begin(),freq.end());

    sum=0;

    for(int i=0;i<n;i++){
        sum += 1LL*freq[i]*a[i];
    }

    cout<<sum<<'\n';





    return 0;
}