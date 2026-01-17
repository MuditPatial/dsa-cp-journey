#include <bits/stdc++.h>
using namespace std;


static const long long MOD = 1e9 + 7;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k;
    cin>>n>>k;

    vector<long long>freq(n+1,1);

    for(int iter=2 ; iter<=k ; iter++){
        vector<long long>prev=freq;
        for(int i=1;i<=n;i++){
            for(int j=i*2;j<=n;j+=i){
                freq[j]=  (freq[j]+ 1LL*prev[i])%MOD;
            }
        }
    }

    long long sum=0;

    for(int i=1;i<=n;i++){
        sum =(sum + 1LL* freq[i])%MOD;
    }

    cout<<sum<<'\n';


    return 0;
}
