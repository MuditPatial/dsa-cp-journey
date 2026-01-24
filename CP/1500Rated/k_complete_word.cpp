#include <bits/stdc++.h>
using namespace std;

int findMax(string s ,int k ,int i1,int i2){
    vector<int>hash(26,0);
    int n=s.size();
    for(int i=0;i<n/k;i++){
        hash[s[i*k + i1]-'a']++;
        if(i1 != i2) hash[s[i*k + i2] - 'a']++;
    }

    int maxFreq=0;

    for(int i=0;i<26;i++){
        maxFreq=max(maxFreq,hash[i]);
    }

    return maxFreq;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int t;
    cin>>t;

    while(t--){
        int n,k;
        cin>>n>>k;

        string s;
        cin>>s;

        int fact=n/k;
        int ans=0;

        for(int i=0;i<k/2;i++){
            ans += 2LL*fact - findMax(s,k,i,k-1-i);
        }

        if(k%2==1) {
            int mid=k/2;
            ans += 1LL*fact - findMax(s,k,mid,mid);
        }

        cout<<ans<<'\n';
        
    }



    return 0;
}

