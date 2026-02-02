#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k1,k2;
    cin>>n>>k1>>k2;

    vector<int>a(n),b(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    for(int i=0;i<n;i++){
        cin>>b[i];
    }

    long long sum=0;
    priority_queue<int>c;

    for(int i=0;i<n;i++){
        c.push(abs(a[i]-b[i]));
        sum += 1LL*abs(a[i]-b[i]);
    }

    long long ans=0;

    if(sum<=(1LL*k1+k2)){
        long long diff  = 1LL*(1LL*k1+k2)-sum;
        if(diff%2==0){
            cout<<"0 \n";
        }
        else{
            cout<<"1 \n";
        }
    }
    else{
        int k=k1+k2;
        while(k--){
            int curr=c.top();
            curr--;
            c.pop();

            if(curr != 0) c.push(curr);
        }

        while(!c.empty()){
            int curr=c.top();
            c.pop();

            ans+= 1LL*curr*curr;
        }

        cout<<ans<<'\n';
    }
  

    return 0;
}