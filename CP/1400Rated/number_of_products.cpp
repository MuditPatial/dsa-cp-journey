#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    int n;
    cin>>n;

    vector<int>a(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    long long neg=0, pos=0;

    long long preNeg=0,prePos=0;

    for(int i=0;i<n;i++){
        long long currNeg=0,currPos=0;
        if(a[i]>0){
            currNeg+=1LL*preNeg;
            currPos+=1LL*prePos+1;
        }
        else{
            currNeg+=1LL*prePos +1;
            currPos+=1LL*preNeg;
        }
        neg+= 1LL*currNeg;
        pos+=1LL*currPos;

        preNeg= currNeg;
        prePos=currPos;

    }

    cout<<neg<<" "<<pos<<'\n';

    return 0;
}
