#include <bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){
        long long n,m;
        cin>>n>>m;

        long long freq2=0, freq5=0;

        long long num = n;

        while(num%2==0){
            num/=2;
            freq2++;
        }

        num=n;
        while( num%5==0){
            num/=5;
            freq5++;
        }

        long long toMul=1;
        bool cond=true;
        if(freq2>freq5){
            toMul=5;
            cond=false;
        }
        else if(freq2<freq5){
            toMul=2;
        }

        long long k=1;
        long long ans=n;

        if(toMul != 1){
            while((k*1LL*toMul)<=m && (freq2 != freq5)){
                k*=toMul;
                ans *= toMul;
                if(cond) freq2++;
                else freq5++;

            }
        }

        while(k*10 <= m){
            k*=10;
            ans*= 1LL*10;
        }
        
        long long fact= m/k;

        

        ans*= 1LL*fact;

        cout<<ans<<'\n';


         
        
    }
    return 0;
}

