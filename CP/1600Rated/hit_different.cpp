#include <bits/stdc++.h>
using namespace std;

long long add(int st , int end){
    if(st>end) return 0;
    
    long long val1 = (1LL*end*(end+1)*(2*end + 1))/6;
    long long val2 = (1LL*st*(st-1)*(2*st-1))/6;

    return val1-val2;
}

int main(){

    int t;
    cin>>t;
    while(t--){
        int n ;
        cin>>n;

        int row=0,col=0;

        int i=1;
        int comp=0;

        while(comp<n){
            comp+=i;
            i++;
        }

        i--;

        comp-=i;
        col = n-comp;
        row=i;
        
        long long sum=1LL*n*n;
        int offSet=0;

        for(int i=1;i<row;i++){
            int rowSt = offSet+1;
            int rowEnd = offSet+i;

            int val = row -i;

            int allowedSt = offSet + col -val;
            int allowedEnd = offSet + col;

            long long a = add(max(allowedSt,rowSt) , min(allowedEnd,rowEnd));

            sum += 1LL*a;

            offSet+=i;

        }

        cout<<sum<<'\n';

    }

    return 0;

}