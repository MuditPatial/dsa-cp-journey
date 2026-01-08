#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    
    string findOrder(vector<string> &words) {
        // code here
        int n=words.size();
        set<char>st;
        for(int i=0;i<n;i++){
            for(auto &x: words[i]){
                st.insert(x);
            }
        }

        int k=st.size();  // number of unique characters in the given list

        map<char,int>mp;
        int ind=0;

        for(auto &c: st){
            mp[c]=ind;
            ind++;
        }


        vector<vector<int>>adj(k);
        vector<int>inDeg(k,0);

        for(int i=0;i<n-1;i++){
            
            string a = words[i];
            string b=words[i+1];
            bool found =false;

            int sz= min(a.size(),b.size());

            for(int j=0;j<sz;j++){
                if(a[j] != b[j]){
                    adj[mp[a[j]]].push_back(mp[b[j]]);
                    inDeg[mp[b[j]]]++;
                    found=true;

                    break;
                }
            }
            if(!found && a.size()>b.size()) return ""; // if all numbers till min common string size is same but the prior string is longer 
        }

        string ans=""; // final string which will contain the order

        queue<int>q;

        for(int i=0;i<k;i++){
            if(inDeg[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int curr = q.front();
            for (auto &p : mp) {
                if (p.second == curr) {
                    ans.push_back(p.first);
                    break;
                }
            }
            q.pop();

            for(auto &x : adj[curr]){
                inDeg[x]--;
                if(inDeg[x]==0){
                    q.push(x);
                }
            }
        }

        if(ans.size() != k ) return ""; // if all numbers are not accompained 

        return ans;

        
    }
};