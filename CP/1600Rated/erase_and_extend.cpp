#include <bits/stdc++.h>
using namespace std;


int main(){

    int n , k;
    cin>>n>>k;
    string s ;
    cin>>s;

    string toTake="";
    toTake.push_back(s[0]);

    int idx=0;
    string b="";

    for(int i=1;i<n;i++){
        if(s[i]>s[idx]){
            break;
        }
        else if(s[i]==s[idx]){
            idx++;
            b.push_back(s[i]);
        }
        else{
            toTake+=b;
            b="";
            idx=0;
            toTake.push_back(s[i]);
        }

    }


    int nLen=toTake.size();


    int cnt=nLen;
    string ans=toTake;
    while(cnt<k){
        ans+=ans;
        cnt*=2;
    }

    while(cnt>k){
        ans.pop_back();
        cnt--;
    }

    cout<<ans<<'\n';


    return 0;
}