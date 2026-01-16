#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin>>n;
        
        vector<int>a(n);

        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        map<int,int>freq,check;

        for(int i=0;i<n;i++){
            freq[a[i]]++;
        }
        
        vector<int>table;
        stack<int>st;

        table.push_back(0);

        for(auto &[x,y] : freq){
            table.push_back(y);
        }

        sort(table.begin(),table.end());

        long long ans=0;

        int sz=table.size();

        for(int i=1;i<sz;i++){
            for(int j=table[i-1]+1;j<table[i];j++){
                st.push(j);
            }
            if(check[table[i]] != 1){
                ans+=1LL*table[i];
                check[table[i]]=1;
            }
            else if(!st.empty()){
                ans+= 1LL*st.top();
                st.pop();
            }

        }
        
        cout<<ans<<'\n';
    }

    return 0;
}
