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
        
        vector<int>a(n);
        long long sum=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            sum+= 1LL*a[i];
        }

        sort(a.begin(),a.end());

        long long steps=1LL*(sum+1)/2;

        long long check=0;

        for(int i=0;i<n;i++){
            if(check+1LL*a[i] == steps){
                steps += 1LL*n -(i+1);
                break;
            }
            else if(check+1LL*a[i] > steps){
                steps += 1LL*n -(i);
                break;
            }
            check += 1LL*a[i];
        }
        

        cout<<steps<<'\n';

    }
}
