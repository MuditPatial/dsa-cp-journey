#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    static const int c = 2e5;
    static vector<int> spf;
    static bool done;

    void sieve() {
        if(done) return;
        done = true; // very important so that sieve runs only once
        

        spf.resize(c + 1);
        spf[1] = 1;
        for(int i = 2; i <= c; i++) spf[i] = i;

        for(int i = 2; i * i <= c; i++){
            if(spf[i] == i){
                for(int j = i * i; j <= c; j += i){
                    if(spf[j] == j)
                        spf[j] = i;
                }
            }
        }
    }

    vector<int> findPrimeFactors(int N) {
        sieve();
        vector<int> ans;
        while(N > 1){
            ans.push_back(spf[N]);
            N /= spf[N];
        }
        return ans;
    }
};

vector<int> Solution::spf;
bool Solution::done = false;
