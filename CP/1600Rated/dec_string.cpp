#include <bits/stdc++.h>
using namespace std;

int main(){

    int T;
    cin>>T;
    vector<char>ans(T);
    int t =T;

    while(t--){
        string s ;
        cin>>s;

        int n ;
        long long pos;
        cin>>pos;

        n=s.size();

        stack<char>st;

        long long num=0;
        int valid=n;

        while(num <pos){
            num += 1LL*valid;
            valid--;
        }

        int toRemove = n-valid -1;
        
        for(int i =0;i<n;i++){
            while(!st.empty() &&  toRemove>0 && st.top() > s[i]){
                st.pop();
                toRemove--;
            }

            st.push(s[i]);
        }

        while(toRemove>0 && !st.empty()){
            st.pop();
            toRemove--;
        }

        string req ="";

        while(!st.empty()){
            req+=st.top();
            st.pop();
        }

        reverse(req.begin(),req.end());

        long long p = pos - (num -valid) ;

        ans[T-t-1]=req[p];
        
    }

    for(auto &c : ans){
        cout<<c;
    }

    return 0;

}