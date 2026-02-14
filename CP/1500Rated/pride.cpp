#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n ;
    cin>>n;

    vector<int>a(n);
    int minStep=n+1;

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int cnt=0;
    for(int i=0;i<n;i++){
        if(a[i]==1){
            cnt++;
        }
    }

    if(cnt>0){
        cout<<n-cnt<<'\n';
        return 0;
    }

    for(int i=0;i<n;i++){
        int x = a[i];
        int steps=0;
        for(int j=i+1;j<n;j++){
            x = gcd(x,a[j]);
            steps++;
            if(x==1){
                minStep = min(minStep , steps);
                break;
            }
        }
    }

    int ans = (minStep == n+1)?-1 : minStep + n-1;

    cout<<ans<<'\n';

    return 0;
}
