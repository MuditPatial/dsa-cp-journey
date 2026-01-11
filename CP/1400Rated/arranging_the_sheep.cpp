#include <bits/stdc++.h>
using namespace std;


int main(){
 
    int t;
    cin>>t;
 
    while(t--){
        int n;
        cin>>n;

        string s;
        cin>>s;

        int st=n;

        for(int i=0;i<n;i++){
            if(s[i]=='*') {
                st=i;
                break;
            }
        }

        long long steps=0;int place=st;

        for(int i=st;i<n;i++){
            if(s[i]=='*'){
                steps += 1LL*(i-place);
                place++;
            }
        }

        


        
    }
    return 0;
}